# wsjcpp-arguments

[![Build Status](https://api.travis-ci.com/wsjcpp/wsjcpp-arguments.svg?branch=master)](https://travis-ci.com/wsjcpp/wsjcpp-arguments) [![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-arguments.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-arguments/stargazers) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-arguments.svg)](https://github.com/wsjcpp/wsjcpp-arguments/) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-arguments.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-arguments/network/members)

Parsing and handling for application arguments

## Intagrate to your project

```
wsjcpp install "https://github.com/wsjcpp/wsjcpp-arguments:master"
```

or include this files:

* src.wsjcpp/wsjcpp_core/wsjcpp_core.h
* src.wsjcpp/wsjcpp_core/wsjcpp_core.cpp
* src/wsjcpp_arguments.cpp
* src/wsjcpp_arguments.h

## Example usage

header `argument_processor_test_program.h`:
```
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
``` 

source-code `argument_processor_main.cpp`:

```
#include "argument_processor_main.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// ArgumentProcessorMain

ArgumentProcessorMain::ArgumentProcessorMain() 
: WsjcppArgumentProcessor("test_program", "TODO description") {
    TAG = "ArgumentProcessorMain";
    // registrySingleArgument("--single", "What exactly do this single param?");
    // registryParameterArgument("-param", "What need this param?");
    // registryExample("here example of command");
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
```

usage:
```
#include <wsjcpp_arguments.h>
#include "argument_processor_main.h"


int main(int argc, const char* argv[]) {
    ArgumentProcessorMain *pMain = new ArgumentProcessorMain();
    WsjcppArguments prog(argc, argv, pMain);

    int nResult = prog.exec();
    if (nResult != 0) {
        // print help
        std::cout << "Try exec help" << std::endl;
        std::cout << prog.help();
    }
    return nResult;
}
```
