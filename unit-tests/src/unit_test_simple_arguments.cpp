#include "unit_test_simple_arguments.h"
#include <vector>
#include <iostream>
#include <wsjcpp_core.h>
#include <wsjcpp_arguments.h>

REGISTRY_UNIT_TEST(UnitTestSimpleArguments)

UnitTestSimpleArguments::UnitTestSimpleArguments()
    : UnitTestBase("UnitTestSimpleArguments") {
    //
}

// ---------------------------------------------------------------------

void UnitTestSimpleArguments::init() {
    // nothing
}

// ---------------------------------------------------------------------

class ArgumentProcessorInstall : public WSJCppArgumentProcessor {
    public:
        ArgumentProcessorInstall() {
            TAG = "ArgumentProcessorInstall";
        };

        virtual int handle(const std::string &sProgramName, const std::vector<std::string> &vSubParams) {
            if (vSubParams.size() != 3) {
                WSJCppLog::err(TAG, "Expected 3 args");
                return -1;
            }

            if (sProgramName != "./program") {
                WSJCppLog::err(TAG, "sProgramName expected as './program'");
                return -1;
            }
            
            if (vSubParams[0] != "install") {
                WSJCppLog::err(TAG, "vSubParams[0] expected as 'install'");
                return -1;
            }

            if (vSubParams[1] != "1") {
                WSJCppLog::err(TAG, "vSubParams[1] expected as '1'");
                return -1;
            }

            if (vSubParams[2] != "2") {
                WSJCppLog::err(TAG, "vSubParams[2] expected as '2'");
                return -1;
            }
            return 0;
        }

        virtual bool canHandle(const std::vector<std::string> &vSubParams) {
            if (vSubParams.size() > 0 && vSubParams[0] == "install") {
                return true;
            }
            return false;
        }

    private:
        std::string TAG;
};

// ---------------------------------------------------------------------

bool UnitTestSimpleArguments::run() {
    bool bTestSuccess = true;

    const int argc1 = 4;
    const char *argv1[argc1] = {"./program", "install", "1", "2"};
    WSJCppArguments args1(argc1, argv1);
    args1.addProcessor(new ArgumentProcessorInstall());

    compareB(bTestSuccess, "canHandle-1", args1.canHandle(), true);
    compareN(bTestSuccess, "handle-1", args1.handle(), 0);

    const int argc2 = 4;
    const char *argv2[argc2] = {"./program2", "some", "1", "2"};
    WSJCppArguments args2(argc2, argv2);
    compareB(bTestSuccess, "canHandle-2", args2.canHandle(), false);
    compareN(bTestSuccess, "handle-2", args2.handle(), -1);


    return bTestSuccess;
}