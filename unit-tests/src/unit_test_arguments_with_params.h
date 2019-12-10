#ifndef UNIT_TEST_AURGUMENTS_WITH_PARAMS_H
#define UNIT_TEST_AURGUMENTS_WITH_PARAMS_H

#include <unit_tests.h>

class UnitTestArgumentsWithParams : public UnitTestBase {
    public:
        UnitTestArgumentsWithParams();
        virtual void init();
        virtual bool run();
};

#endif // #ifndef UNIT_TEST_AURGUMENTS_WITH_PARAMS_H
