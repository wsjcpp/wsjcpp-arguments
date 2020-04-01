
#include "argument_processor_main.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// ArgumentProcessorMain

ArgumentProcessorMain::ArgumentProcessorMain() 
: WSJCppArgumentProcessor({"main"}, "Examples") {
    TAG = "ArgumentProcessorMain";
    registrySingleArgument("--single1", "Single 1");
    registrySingleArgument("--single2", "Single 2");
    registryParameterArgument("-param1", "Param 1");
    registryParameterArgument("-param2", "Param 2");
    registryExample("wsjcpp --single1 -param1 1");
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

