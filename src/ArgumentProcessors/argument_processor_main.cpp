
#include "argument_processor_main.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// ArgumentProcessorMain

ArgumentProcessorMain::ArgumentProcessorMain() 
: WsjcppArgumentProcessor({"main"}, "Examples") {
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
    WsjcppLog::err(TAG, "Not implemented");
    return false;
}

// ---------------------------------------------------------------------

bool ArgumentProcessorMain::applyParameterArgument(
    const std::string &sProgramName, 
    const std::string &sArgumentName, 
    const std::string &sValue
) {
    WsjcppLog::err(TAG, "Not implemented");
    return false;
}

// ---------------------------------------------------------------------

int ArgumentProcessorMain::exec(const std::string &sProgramName, const std::vector<std::string> &vSubParams) {
    WsjcppLog::err(TAG, "Not implemented");
    return -1;
}

