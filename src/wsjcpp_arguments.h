#ifndef WSJCPP_PARSE_ARGUMENTS_H
#define WSJCPP_PARSE_ARGUMENTS_H

#include <string>
#include <vector>

// ---------------------------------------------------------------------

class WSJCppArgumentProcessor {
    public:
        WSJCppArgumentProcessor();
        virtual int handle(const std::string &sProgramName, const std::vector<std::string> &vSubParams);
        virtual bool canHandle(const std::vector<std::string> &vSubParams);
        void addProcessor(WSJCppArgumentProcessor *p);
    private:
        std::vector<WSJCppArgumentProcessor *> m_vProcessors;
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
        WSJCppArgumentProcessor *findProcessor();
        std::string TAG;
        std::vector<std::string> m_vArguments;
        std::string m_sProgramName;
        std::vector<WSJCppArgumentProcessor *> m_vProcessors;
};

// ---------------------------------------------------------------------

#endif // WSJCPP_PARSE_ARGUMENTS_H
