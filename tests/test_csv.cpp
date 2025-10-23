#include "utils/csv.hpp"
#include <gtest/gtest.h>

TEST(CSVUtils, EscapeComma) {
    using namespace chessDataLib::utils;
    EXPECT_EQ(EscapeCSVField("a,b"), "\"a,b\"");
    EXPECT_EQ(EscapeCSVField("noquote"), "noquote");
    EXPECT_EQ(EscapeCSVField("he\"llo"), "\"he\"\"llo\"");
}

TEST(CSVUtils, Trim) {
    using namespace chessDataLib::utils;
    EXPECT_EQ(Trim("  x  "), "x");
    EXPECT_EQ(Trim("\n\tabc\r"), "abc");
}