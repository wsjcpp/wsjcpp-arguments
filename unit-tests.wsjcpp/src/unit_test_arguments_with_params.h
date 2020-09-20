#ifndef UNIT_TEST_ARGUMENTS_WITH_PARAMS_H
#define UNIT_TEST_ARGUMENTS_WITH_PARAMS_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestArgumentsWithParams : public WsjcppUnitTestBase {
    public:
        UnitTestArgumentsWithParams();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_ARGUMENTS_WITH_PARAMS_H

