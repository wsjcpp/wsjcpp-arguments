#ifndef WSJCPP_PARSE_ARGUMENTS_H
#define WSJCPP_PARSE_ARGUMENTS_H

#include <string>
#include <vector>

// ---------------------------------------------------------------------

class WSJCppArgumentProcessor {
    public:
        WSJCppArgumentProcessor(const std::string &sName);
        virtual int handle(const std::string &sProgramName, const std::vector<std::string> &vSubParams);
        virtual bool canHandle(const std::vector<std::string> &vSubParams);

        void singleFlag(const std::string &sName);
        void param(const std::string &sName);
        void addSubArgumentProcesor(const std::string &sName, WSJCppArgumentProcessor *);
    private:
        std::string m_sName;
        std::string m_sProgramName;
        std::vector<WSJCppArgumentProcessor *> m_vSubProcessors;
};

// ---------------------------------------------------------------------

class WSJCppArguments {
    public:
        WSJCppArguments(int argc, const char* argv[]);
        void addProcessor(WSJCppArgumentProcessor *p);
        int handle();
        bool canHandle();

        std::string help();

    private:
        std::string TAG;
        std::vector<std::string> m_vArguments;
        std::string m_sProgramName;
        std::vector<WSJCppArgumentProcessor *> m_vProcessors;
};

// ---------------------------------------------------------------------

#endif // WSJCPP_PARSE_ARGUMENTS_H
