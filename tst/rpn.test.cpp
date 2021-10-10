#include "gtest/gtest.h"
#include "rpn.h"

TEST(evaluate_rpn_suite, parses_basic_expression) {
    int answer = evaluate_rpn("2 2 +");
    ASSERT_EQ(answer, 4);
}

TEST(evaluate_rpn_suite, parses_complex_expression) {
    int answer = evaluate_rpn("10 6 9 3 + -11 * / * 17 + 5 +");
    ASSERT_EQ(answer, 22);
}