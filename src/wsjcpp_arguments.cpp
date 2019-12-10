#include "wsjcpp_arguments.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------

WSJCppArgumentProcessor::WSJCppArgumentProcessor(const std::string &sName, const std::string &sDescription) {
    TAG = "WSJCppArgumentProcessor-" + sName;
    m_sName = sName;
    m_sDescription = sDescription;
}

// ---------------------------------------------------------------------

std::string WSJCppArgumentProcessor::getName() {
    return m_sName;
}

// ---------------------------------------------------------------------

std::string WSJCppArgumentProcessor::getDescription() {
    return m_sDescription;
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

void WSJCppArgumentProcessor::registryProcessor(WSJCppArgumentProcessor *p) {
    for (int i = 0; i < m_vProcessors.size(); i++) {
        if (m_vProcessors[i]->getName() == p->getName()) {
            WSJCppLog::throw_err(TAG, "Processor '" + p->getName() + "' already registered");
        }
    }
    m_vProcessors.push_back(p);
}

// ---------------------------------------------------------------------

void WSJCppArgumentProcessor::registrySingleArgument(const std::string &sArgumentName, const std::string &sDescription) {

}

// ---------------------------------------------------------------------

void WSJCppArgumentProcessor::registryParamArgument(const std::string &sArgumentName, const std::string &sDescription) {

}

// ---------------------------------------------------------------------

std::string WSJCppArgumentProcessor::help(const std::string &sProgramName, const std::string &sPrefix) {
    std::string sRet = "";
    if (sProgramName == m_sName) {
        sRet = "Usage: " + m_sName + " <params> <command> <subcomands/args>\r\n";
    }
    sRet += sPrefix + "  <params>: \r\n";
    sRet += sPrefix + "    [] - description \r\n"; // TODO

    if (m_vProcessors.size() > 0) {
        sRet += sPrefix + "  <commands>: \r\n";
        for (int i = 0; i < m_vProcessors.size(); i++) {
            WSJCppArgumentProcessor *p = m_vProcessors[i];
            sRet += sPrefix + "    " + p->getName() + " - " + p->getDescription() + "\r\n";
            sRet += p->help(sProgramName, sPrefix + "  ");
        }
    }
    sRet += "\r\n"; // TODO
    return sRet;
}

// ---------------------------------------------------------------------

WSJCppArgumentProcessor *WSJCppArgumentProcessor::findProcessor(const std::vector<std::string> &vSubParams) {
    WSJCppArgumentProcessor *pRet = nullptr;
    bool bCanHandle = false;
    for (int i = 0; i < m_vProcessors.size(); i++) {
        if (m_vProcessors[i]->canHandle(vSubParams)) {
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

WSJCppArguments::WSJCppArguments(int argc, const char* argv[]) {
    TAG = "WSJCppArguments";
    for (int i = 0; i < argc; i++) {
        m_vArguments.push_back(std::string(argv[i]));
    }
    m_sProgramName = m_vArguments[0];
    m_vArguments.erase(m_vArguments.begin());
    m_pRoot = new WSJCppArgumentProcessor(m_sProgramName, "");
}

// ---------------------------------------------------------------------

int WSJCppArguments::handle() {
    WSJCppArgumentProcessor *pArgumentProcessor = m_pRoot->findProcessor(m_vArguments);
    if (pArgumentProcessor != nullptr) {
        return pArgumentProcessor->handle(m_sProgramName, m_vArguments);    
    }
    WSJCppLog::err(TAG, "Not found argument processor");
    return -1;
}

// ---------------------------------------------------------------------

bool WSJCppArguments::canHandle() {
    WSJCppArgumentProcessor *pArgumentProcessor = m_pRoot->findProcessor(m_vArguments);
    return pArgumentProcessor != nullptr;
}

// ---------------------------------------------------------------------

WSJCppArgumentProcessor &WSJCppArguments::getRoot() {
    return *m_pRoot;
}

// ---------------------------------------------------------------------

std::string WSJCppArguments::help() {
    return m_pRoot->help(m_sProgramName, "");
}

// ---------------------------------------------------------------------