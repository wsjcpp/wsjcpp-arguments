#include "wsjcpp_arguments.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------

WSJCppArgumentProcessor::WSJCppArgumentProcessor() {
    //
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

void WSJCppArgumentProcessor::addProcessor(WSJCppArgumentProcessor *p) {
    m_vProcessors.push_back(p);
}

// ---------------------------------------------------------------------

WSJCppArguments::WSJCppArguments(int argc, const char* argv[]) {
    TAG = "WSJCppArguments";
    for (int i = 0; i < argc; i++) {
        m_vArguments.push_back(std::string(argv[i]));
    }
    m_sProgramName = m_vArguments[0];
    m_vArguments.erase(m_vArguments.begin());
}

// ---------------------------------------------------------------------

void WSJCppArguments::addProcessor(WSJCppArgumentProcessor *p) {
    m_vProcessors.push_back(p);
}

// ---------------------------------------------------------------------

int WSJCppArguments::handle() {
    WSJCppArgumentProcessor *pArgumentProcessor = this->findProcessor();
    if (pArgumentProcessor != nullptr) {
        return pArgumentProcessor->handle(m_sProgramName, m_vArguments);    
    }
    WSJCppLog::err(TAG, "Not found argument processor");
    return -1;
    
}

// ---------------------------------------------------------------------

bool WSJCppArguments::canHandle() {
    WSJCppArgumentProcessor *pArgumentProcessor = this->findProcessor();
    return pArgumentProcessor != nullptr;
}

// ---------------------------------------------------------------------

WSJCppArgumentProcessor *WSJCppArguments::findProcessor() {
    WSJCppArgumentProcessor *pRet = nullptr;
    bool bCanHandle = false;
    for (int i = 0; i < m_vProcessors.size(); i++) {
        if (m_vProcessors[i]->canHandle(m_vArguments)) {
            if (pRet == nullptr) {
                pRet = m_vProcessors[i];
            } else {
                WSJCppLog::throw_err(TAG, "Several processors can handle this arguments");
            }
        }
    }
    return pRet;
}

// ---------------------------------------------------------------------

std::string WSJCppArguments::help() {
    // TODO
    return "";
}

// ---------------------------------------------------------------------