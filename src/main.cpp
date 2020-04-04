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
    if (!WsjcppCore::dirExists(appLogPath)) {
        WsjcppCore::makeDir(appLogPath);
    }
    WsjcppLog::setPrefixLogFile("wsjcpp_arguments");
    WsjcppLog::setLogDirectory(".logs");

    ArgumentProcessorMain *pMain = new ArgumentProcessorMain();
    WsjcppArguments prog(argc, argv, (WsjcppArgumentProcessor *)pMain);

    int nResult = prog.exec();
    if (nResult != 0) {
        // print help
        std::cout << "Try exec help" << std::endl;
        std::cout << prog.help();
    }
    return nResult;
}