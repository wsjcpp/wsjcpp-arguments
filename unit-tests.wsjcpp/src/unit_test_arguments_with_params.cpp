#include <wsjcpp_unit_tests.h>
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_arguments.h>

// ---------------------------------------------------------------------
// ArgumentProcessorUninstall

class ArgumentProcessorUninstall : public WsjcppArgumentProcessor {
    public:
        ArgumentProcessorUninstall() : WsjcppArgumentProcessor({"uninstall"}, "uninstall", "uninstall something") {
            TAG = "ArgumentProcessorUninstall";
        };

        virtual int exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams) {
            if (vSubParams.size() != 3) {
                WsjcppLog::err(TAG, "Expected 3 args");
                return -1;
            }

            if (vRoutes[0] != "./program") {
                WsjcppLog::err(TAG, "sProgramName expected as './program'");
                return -1;
            }
            
            if (vSubParams[0] != "install") {
                WsjcppLog::err(TAG, "vSubParams[0] expected as 'uninstall'");
                return -1;
            }

            if (vSubParams[1] != "1") {
                WsjcppLog::err(TAG, "vSubParams[1] expected as '1'");
                return -1;
            }

            if (vSubParams[2] != "2") {
                WsjcppLog::err(TAG, "vSubParams[2] expected as '2'");
                return -1;
            }
            return 0;
        }

        virtual bool canHandle(const std::vector<std::string> &vSubParams) {
            if (vSubParams.size() > 0 && vSubParams[0] == "uninstall") {
                return true;
            }
            return false;
        }

    private:
        std::string TAG;
};

// ---------------------------------------------------------------------
// UnitTestArgumentsWithParams

class UnitTestArgumentsWithParams : public WsjcppUnitTestBase {
    public:
        UnitTestArgumentsWithParams();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestArgumentsWithParams)

UnitTestArgumentsWithParams::UnitTestArgumentsWithParams()
    : WsjcppUnitTestBase("UnitTestArgumentsWithParams") {
}

// ---------------------------------------------------------------------

bool UnitTestArgumentsWithParams::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestArgumentsWithParams::executeTest() {

    const int argc1 = 5;
    const char *argv1[argc1] = {"./program", "-v", "uninstall", "1", "2"};
    WsjcppArguments args1(argc1, argv1, nullptr);
    // args1.getRoot().registryProcessor(new ArgumentProcessorUninstall());

    // compareB(bTestSuccess, "canHandle-1", args1.canHandle(), true);
    // compareN(bTestSuccess, "handle-1", args1.handle(), 0);

    const int argc2 = 4;
    const char *argv2[argc2] = {"./program2", "some", "1", "2"};
    WsjcppArguments args2(argc2, argv2, nullptr);
    // compareB(bTestSuccess, "canHandle-2", args2.canHandle(), false);
    // compareN(bTestSuccess, "handle-2", args2.handle(), -1);

}

// ---------------------------------------------------------------------

bool UnitTestArgumentsWithParams::doAfterTest() {
    // nothing
    return true;
}

