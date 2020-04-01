
#include "argument_processor_main.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// ArgumentProcessorMain

ArgumentProcessorMain::ArgumentProcessorMain() 
: WSJCppArgumentProcessor({"main"}, "TODO description") {
    TAG = "ArgumentProcessorMain";
    // registrySingleArgument("--single", "What exactly do this single param?");
    // registryParameterArgument("-param", "What need this param?");
    // registryExample("here example of command");
    // registryProcessor(new ArgumentProcessorOtherProcessor());
}

// ---------------------------------------------------------------------

bool ArgumentProcessorMain::applySingleArgument(const std::string &sProgramName, const std::string &sArgumentName) {
    WSJCppLog::err(TAG, "Not implemented");
    return false;
}

// ---------------------------------------------------------------------

bool ArgumentProcessorMain::applyParameterArgument(
    const std::string &sProgramName, 
    const std::string &sArgumentName, 
    const std::string &sValue
) {
    WSJCppLog::err(TAG, "Not implemented");
    return false;
}

// ---------------------------------------------------------------------

int ArgumentProcessorMain::exec(const std::string &sProgramName, const std::vector<std::string> &vSubParams) {
    WSJCppLog::err(TAG, "Not implemented");
    return -1; 
}

