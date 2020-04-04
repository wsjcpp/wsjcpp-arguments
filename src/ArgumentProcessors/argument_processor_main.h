#ifndef ARGUMENT_PROCESSOR_MAIN_H
#define ARGUMENT_PROCESSOR_MAIN_H

#include <wsjcpp_arguments.h>

class ArgumentProcessorMain : public WsjcppArgumentProcessor {
    public:
        ArgumentProcessorMain();

        virtual bool applyParameterArgument(const std::string &sProgramName, const std::string &sArgumentName, const std::string &sValue);
        virtual bool applySingleArgument(const std::string &sProgramName, const std::string &sArgumentName);
        virtual int exec(const std::string &sProgramName, const std::vector<std::string> &vSubParams);
};

#endif // ARGUMENT_PROCESSOR_MAIN_H
