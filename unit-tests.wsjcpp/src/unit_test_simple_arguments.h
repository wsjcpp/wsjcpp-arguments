#ifndef UNIT_TEST_SIMPLE_ARGUMENTS_H
#define UNIT_TEST_SIMPLE_ARGUMENTS_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestSimpleArguments : public WsjcppUnitTestBase {
    public:
        UnitTestSimpleArguments();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_SIMPLE_ARGUMENTS_H

