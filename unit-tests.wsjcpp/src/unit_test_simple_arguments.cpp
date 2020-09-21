#include <wsjcpp_unit_tests.h>
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_arguments.h>

// ---------------------------------------------------------------------
// ArgumentProcessorInstall

class ArgumentProcessorInstall : public WsjcppArgumentProcessor {
    public:
        ArgumentProcessorInstall();

        // WsjcppArgumentProcessor
        virtual bool applySingleArgument(const std::string &sProgramName, const std::string &sArgumentName);
        virtual bool applyParameterArgument(const std::string &sProgramName, const std::string &sArgumentName, const std::string &sValue);
        virtual int exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams);
        
        void reset();
        bool silent;
        std::vector<std::string> vParams;
    private:
        std::string TAG;
};

// ---------------------------------------------------------------------

ArgumentProcessorInstall::ArgumentProcessorInstall() 
 : WsjcppArgumentProcessor({"install", "i"}, "install", "install something") {
    TAG = "ArgumentProcessorInstall";

    registrySingleArgument("--silent", "Silent");
    reset();
}

// ---------------------------------------------------------------------

void ArgumentProcessorInstall::reset() {
    silent = false;
    vParams.clear();
}

// ---------------------------------------------------------------------

bool ArgumentProcessorInstall::applySingleArgument(const std::string &sProgramName, const std::string &sArgumentName) {
    if (sArgumentName == "--silent") {
        silent = true;
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------

bool ArgumentProcessorInstall::applyParameterArgument(const std::string &sProgramName, const std::string &sArgumentName, const std::string &sValue) {
    return false;
}

// ---------------------------------------------------------------------

int ArgumentProcessorInstall::exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams) {
    vParams = std::vector<std::string>(vSubParams);
    return 0;
};

// ---------------------------------------------------------------------

class ArgumentProcessorProgram1 : public WsjcppArgumentProcessor {
    public:
        ArgumentProcessorProgram1();
        
        // WsjcppArgumentProcessor
        virtual bool applySingleArgument(const std::string &sProgramName, const std::string &sArgumentName);
        virtual bool applyParameterArgument(const std::string &sProgramName, const std::string &sArgumentName, const std::string &sValue);
        virtual int exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams);

        void reset();
        bool hello;
        bool hello2;
        bool hello3;
        std::string param1;
        std::string param2;
        std::string h;
        std::vector<std::string> vParams;
        ArgumentProcessorInstall *pInstall;
    private:
        std::string TAG;
};

// ---------------------------------------------------------------------

ArgumentProcessorProgram1::ArgumentProcessorProgram1() 
    : WsjcppArgumentProcessor({"program1"}, "install", "Program for unit-tests") {
    TAG = "ArgumentProcessorProgram1";
    registrySingleArgument("--hello", "Hello argument");
    registrySingleArgument("--hello2", "Hello2 argument");
    registrySingleArgument("--hello3", "Hello3 argument");
    registryParameterArgument("-param1", "str", "Parameter 1");
    registryParameterArgument("-param2", "str", "Parameter 2");
    registryParameterArgument("-h", "str", "Parameter hello");
    pInstall = new ArgumentProcessorInstall();
    registryProcessor(pInstall);

    reset();
};

// ---------------------------------------------------------------------

void ArgumentProcessorProgram1::reset() {
    pInstall->reset();

    hello = false;
    hello2 = false;
    hello3 = false;

    param1 = "";
    param2 = "";
    h = "";

    vParams.clear();
}

// ---------------------------------------------------------------------

bool ArgumentProcessorProgram1::applySingleArgument(const std::string &sProgramName, const std::string &sArgumentName) {
    if (sArgumentName == "--hello") {
        hello = true;
        return true;
    }
    
    if (sArgumentName == "--hello2") {
        hello2 = true;
        return true;
    }
    
    if (sArgumentName == "--hello3") {
        hello3 = true;
        return true;
    }

    return false;
}

// ---------------------------------------------------------------------

bool ArgumentProcessorProgram1::applyParameterArgument(const std::string &sProgramName, const std::string &sArgumentName, const std::string &sValue) {
    if (sArgumentName == "-param1") {
        param1 = sValue;
        return true;
    }
    
    if (sArgumentName == "-param2") {
        param2 = sValue;
        return true;
    }

    if (sArgumentName == "h") {
        h = sValue;
        return true;
    }

    return false;
}

// ---------------------------------------------------------------------

int ArgumentProcessorProgram1::exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams) {
    vParams = std::vector<std::string>(vSubParams);
    return 0;
};

// ---------------------------------------------------------------------
// UnitTestSimpleArguments

class UnitTestSimpleArguments : public WsjcppUnitTestBase {
    public:
        UnitTestSimpleArguments();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestSimpleArguments)

UnitTestSimpleArguments::UnitTestSimpleArguments()
    : WsjcppUnitTestBase("UnitTestSimpleArguments") {
}

// ---------------------------------------------------------------------

bool UnitTestSimpleArguments::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestSimpleArguments::executeTest() {

    const int argc1 = 8;
    const char *argv1[argc1] = {"./program", "--hello", "--hello2", "--hello3", "install", "--silent", "p1", "p2"};
    ArgumentProcessorProgram1 *pProgram1 = new ArgumentProcessorProgram1();
    WsjcppArguments args1(argc1, argv1, pProgram1);
    compare("args1 exec", args1.exec(), 0);
    compare("args1 --hello", pProgram1->hello, true);
    compare("args1 --hello2", pProgram1->hello2, true);
    compare("args1 --hello3", pProgram1->hello3, true);

    compare("args1 -param1", pProgram1->param1, "");
    compare("args1 -param2", pProgram1->param2, "");
    compare("args1 -h", pProgram1->h, "");

    compare("args1 install --silent", pProgram1->pInstall->silent, true);
    compare("args1 install arguments size", pProgram1->pInstall->vParams.size(), 2);
    compare("args1 install argument 1", pProgram1->pInstall->vParams[0], "p1");
    compare("args1 install argument 2", pProgram1->pInstall->vParams[1], "p2");
    
    pProgram1->reset();

    const int argc2 = 8;
    const char *argv2[argc2] = {"./program", "--hello", "-param1", "p1", "-param2", "p2", "arg1", "arg2"};

    WsjcppArguments args2(argc2, argv2, pProgram1);
    compare("args2 exec", args2.exec(), 0);
    compare("args2 --hello", pProgram1->hello, true);
    compare("args2 --hello2", pProgram1->hello2, false);
    compare("args2 --hello3", pProgram1->hello3, false);

    compare("args2 -param1", pProgram1->param1, "p1");
    compare("args2 -param2", pProgram1->param2, "p2");
    compare("args2 -h", pProgram1->h, "");
    compare("args2 arguments size", pProgram1->vParams.size(), 2);
    compare("args2 argument 2", pProgram1->vParams[0], "arg1");
    compare("args2 argument 2", pProgram1->vParams[1], "arg2");
    
    pProgram1->reset();

    const int argc3 = 6;
    const char *argv3[argc3] = {"./program", "--hello", "i", "--silent", "some1", "some2"};
    
    WsjcppArguments args3(argc3, argv3, pProgram1);
    compare("args3 exec", args3.exec(), 0);

    compare("args3 --hello", pProgram1->hello, true);
    compare("args3 --hello2", pProgram1->hello2, false);
    compare("args3 --hello3", pProgram1->hello3, false);

    compare("args3 -param1", pProgram1->param1, "");
    compare("args3 -param2", pProgram1->param2, "");

    compare("args3 install --silent", pProgram1->pInstall->silent, true);
    compare("args3 install arguments size", pProgram1->pInstall->vParams.size(), 2);
    compare("args3 install argument 1", pProgram1->pInstall->vParams[0], "some1");
    compare("args3 install argument 2", pProgram1->pInstall->vParams[1], "some2");


    // WsjcppLog::info(TAG, "\r\n" + args2.help());
}

// ---------------------------------------------------------------------

bool UnitTestSimpleArguments::doAfterTest() {
    // nothing
    return true;
}
