#include <string.h>
#include <iostream>
#include <wsjcpp_core.h>
#include "wsjcpp_arguments.h"
#include "argument_processor_main.h"

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);

    std::string appLogPath = ".logs";
    if (!WSJCppCore::dirExists(appLogPath)) {
        WSJCppCore::makeDir(appLogPath);
    }
    WSJCppLog::setPrefixLogFile("wsjcpp_arguments");
    WSJCppLog::setLogDirectory(".logs");

    ArgumentProcessorMain *pMain = new ArgumentProcessorMain();
    WSJCppArguments prog(argc, argv, (WSJCppArgumentProcessor *)pMain);

    int nResult = prog.exec();
    if (nResult != 0) {
        // print help
        std::cout << "Try exec help" << std::endl;
        std::cout << prog.help();
    }
    return nResult;
}