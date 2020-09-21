#ifndef ARGUMENT_PROCESSOR_MAIN_H
#define ARGUMENT_PROCESSOR_MAIN_H

#include <wsjcpp_arguments.h>

class ArgumentProcessorMain : public WsjcppArgumentProcessor {
    public:
        ArgumentProcessorMain();
        virtual bool applySingleArgument(const std::string &sProgramName, const std::string &sArgumentName);
        virtual bool applyParameterArgument(const std::string &sProgramName, const std::string &sArgumentName, const std::string &sValue);
};

class ArgumentProcessorSubcommand1 : public WsjcppArgumentProcessor {
    public:
        ArgumentProcessorSubcommand1();
        virtual bool applySingleArgument(const std::string &sProgramName, const std::string &sArgumentName);
        virtual bool applyParameterArgument(const std::string &sProgramName, const std::string &sArgumentName, const std::string &sValue);
        virtual int exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams);

    private:
        bool m_bSilent;
        bool m_bFirst;
        int m_nTimesTest;
};

class ArgumentProcessorNothing : public WsjcppArgumentProcessor {
    public:
        ArgumentProcessorNothing();
        virtual int exec(const std::vector<std::string> &vRoutes, const std::vector<std::string> &vSubParams) override;
};

#endif // ARGUMENT_PROCESSOR_MAIN_H
