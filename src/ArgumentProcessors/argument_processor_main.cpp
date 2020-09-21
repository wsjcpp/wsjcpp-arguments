
#include "argument_processor_main.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// ArgumentProcessorMain

ArgumentProcessorMain::ArgumentProcessorMain() 
: WsjcppArgumentProcessor({"main"}, "Short description", "Here long description.") {
    TAG = "ArgumentProcessorMain";
    registrySingleArgument("--single1", "Single 1");
    registrySingleArgument("--single2", "Single 2");
    registryParameterArgument("-param1", "P", "Param 1");
    registryParameterArgument("-param2", "P", "Param 2");
    registryExample("wsjcpp --single1 -param1 1");
    registryProcessor(new ArgumentProcessorSubcommand1());
    registryProcessor(new ArgumentProcessorNothing());
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

int ArgumentProcessorMain::exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams) {
    WsjcppLog::err(TAG, "Not implemented");
    return -1;
}

// ---------------------------------------------------------------------
// ArgumentProcessorSubcommand1

ArgumentProcessorSubcommand1::ArgumentProcessorSubcommand1() 
: WsjcppArgumentProcessor(
    {"subcommand1", "sc1"}, 
    "Subcommand1",
    "Example of subcommand1 with long description must be here 12345678901234567890 lol"
) {
    TAG = "ArgumentProcessorSubcommand1";
    registrySingleArgument("--silent", "Silent mode. Will be print 'silent' - no more.");
    registrySingleArgument("--first", "First. Will be print 'first' - no more.");
    registryParameterArgument("-times", "N", "How much times print line 'test'");

    m_bSilent = false;
    m_bFirst = false;
    m_nTimesTest = 0;
}

// ---------------------------------------------------------------------

bool ArgumentProcessorSubcommand1::applySingleArgument(const std::string &sProgramName, const std::string &sArgumentName) {
    if (sArgumentName == "--silent") {
        m_bSilent = true;
        return true;
    }
    
    if (sArgumentName == "--first") {
        m_bFirst = true;
        return true;
    }

    return false;
}

// ---------------------------------------------------------------------

bool ArgumentProcessorSubcommand1::applyParameterArgument(const std::string &sProgramName, const std::string &sArgumentName, const std::string &sValue) {
    if (sArgumentName == "-times") {
        m_nTimesTest = std::atoi(sValue.c_str());
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------

int ArgumentProcessorSubcommand1::exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams) {
    WsjcppLog::info(TAG, "Exec");
    for (int i = 0; i < m_nTimesTest; i++) {
        std::cout << i << ": test" << std::endl;
    }
    return 0;
}

// ---------------------------------------------------------------------
// ArgumentProcessorNothing

ArgumentProcessorNothing::ArgumentProcessorNothing() 
: WsjcppArgumentProcessor(
    {"nothing", "n"}, 
    "nothing",
    "Example of nothing with long description must be here 12345678901234567890 lol again"
) {
    TAG = "ArgumentProcessorSubcommand1";
}

// ---------------------------------------------------------------------

int ArgumentProcessorNothing::exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams) {
    std::cout << "Nothing" << std::endl;
    return 0;
}
