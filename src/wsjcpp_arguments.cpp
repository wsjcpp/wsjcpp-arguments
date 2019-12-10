#include "wsjcpp_arguments.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------

WSJCppArgumentProcessor::WSJCppArgumentProcessor(const std::string &sName) {
    m_sName = sName;
    // m_sProgramName = sProgramName;
}

// ---------------------------------------------------------------------

int WSJCppArgumentProcessor::handle(const std::string &sProgramName, const std::vector<std::string> &vSubParams) {
    return -1;
}

// ---------------------------------------------------------------------

bool WSJCppArgumentProcessor::canHandle(const std::vector<std::string> &vSubParams) {
    return false;
}

// ---------------------------------------------------------------------

WSJCppArguments::WSJCppArguments(int argc, const char* argv[]) {
    TAG = "WSJCppArguments";
    for (int i = 0; i < argc; i++) {
        m_vArguments.push_back(std::string(argv[i]));
    }
    m_sProgramName = m_vArguments[0];
}

// ---------------------------------------------------------------------

void WSJCppArguments::addProcessor(WSJCppArgumentProcessor *p) {
    m_vProcessors.push_back(p);
}

// ---------------------------------------------------------------------

int WSJCppArguments::handle() {
    return 0;
}

// ---------------------------------------------------------------------

bool WSJCppArguments::canHandle() {
    bool bCanHandle = false;
    for (int i = 0; i < m_vProcessors.size(); i++) {
        if (!bCanHandle) {
            if (m_vProcessors[i]->canHandle(m_vArguments)) { // TODO pop
                bCanHandle = true;
            }
        } else {
            WSJCppLog::err(TAG, "Several processors can handle this arguments");
        }
    }
    return false;
}

// ---------------------------------------------------------------------

std::string WSJCppArguments::help() {
    // TODO
    return "";
}

// ---------------------------------------------------------------------