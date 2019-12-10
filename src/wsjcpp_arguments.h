#ifndef WSJCPP_ARGUMENTS_H
#define WSJCPP_ARGUMENTS_H

#include <string>
#include <vector>
#include <map>

// ---------------------------------------------------------------------

class WSJCppArgumentProcessor {
    public:
        WSJCppArgumentProcessor(const std::string &sName, const std::string &sDescription);
        std::string getName();
        std::string getDescription();

        void registryProcessor(WSJCppArgumentProcessor *p);
        void registrySingleArgument(const std::string &sArgumentName, const std::string &sDescription);
        void registryParamArgument(const std::string &sArgumentName, const std::string &sDescription);
        
        std::string help(const std::string &sProgramName, const std::string &sPrefix);

        WSJCppArgumentProcessor *findProcessor(const std::vector<std::string> &vSubParams);
        

        bool hasSingleArgument(const std::string &sArgumentName);
        bool getValueOfParam(const std::string &sArgumentName);
        bool hasParamArgument(const std::string &sArgumentName, const std::string &sDescription);
        
        
        virtual int handle(const std::string &sProgramName, const std::vector<std::string> &vSubParams);
        virtual bool canHandle(const std::vector<std::string> &vSubParams);
    private:
        std::string TAG;
        std::string m_sName;
        std::string m_sDescription;
        std::vector<WSJCppArgumentProcessor *> m_vProcessors;
        std::map<std::string, std::string> m_vSingleArguments;
        std::map<std::string, std::string> m_vParamArguments;
};

// ---------------------------------------------------------------------

class WSJCppArguments {
    public:
        WSJCppArguments(int argc, const char* argv[]);
        int handle();
        bool canHandle();
        std::string help();
        WSJCppArgumentProcessor &getRoot();

    private:
        WSJCppArgumentProcessor *m_pRoot;

        std::string TAG;
        std::vector<std::string> m_vArguments;
        std::string m_sProgramName;
        std::vector<WSJCppArgumentProcessor *> m_vProcessors;
};

// ---------------------------------------------------------------------

#endif // WSJCPP_ARGUMENTS_H
