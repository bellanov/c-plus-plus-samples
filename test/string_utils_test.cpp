#include <cstring>
#include <gtest/gtest.h>

extern "C"
{
#include "string_utils.h"
}

class StringUtilsTest : public ::testing::Test
{
  protected:
    void TearDown() override
    {
        // Cleanup is handled by individual tests
    }
};

TEST_F(StringUtilsTest, DuplicateSuccessful)
{
    const char *original = "Hello, World!";
    StringResult result = string_duplicate(original);

    ASSERT_EQ(result.error, STR_OK);
    ASSERT_NE(result.data, nullptr);
    EXPECT_EQ(result.length, std::strlen(original));
    EXPECT_STREQ(result.data, original);

    string_result_free(&result);
}

TEST_F(StringUtilsTest, DuplicateNullPointer)
{
    StringResult result = string_duplicate(nullptr);

    EXPECT_EQ(result.error, STR_NULL_POINTER);
    EXPECT_EQ(result.data, nullptr);
    EXPECT_EQ(result.length, 0);
}

TEST_F(StringUtilsTest, DuplicateEmptyString)
{
    const char *empty = "";
    StringResult result = string_duplicate(empty);

    ASSERT_EQ(result.error, STR_OK);
    ASSERT_NE(result.data, nullptr);
    EXPECT_EQ(result.length, 0);
    EXPECT_STREQ(result.data, "");

    string_result_free(&result);
}

TEST_F(StringUtilsTest, ConcatSuccessful)
{
    const char *str1 = "Hello";
    const char *str2 = "World";
    StringResult result = string_concat(str1, str2);

    ASSERT_EQ(result.error, STR_OK);
    ASSERT_NE(result.data, nullptr);
    EXPECT_STREQ(result.data, "HelloWorld");
    EXPECT_EQ(result.length, std::strlen(str1) + std::strlen(str2));

    string_result_free(&result);
}

TEST_F(StringUtilsTest, ConcatNullPointer)
{
    const char *str1 = "Hello";
    StringResult result1 = string_concat(nullptr, str1);
    EXPECT_EQ(result1.error, STR_NULL_POINTER);

    StringResult result2 = string_concat(str1, nullptr);
    EXPECT_EQ(result2.error, STR_NULL_POINTER);
}

TEST_F(StringUtilsTest, ConcatEmptyStrings)
{
    const char *empty = "";
    StringResult result = string_concat(empty, empty);

    ASSERT_EQ(result.error, STR_OK);
    ASSERT_NE(result.data, nullptr);
    EXPECT_STREQ(result.data, "");
    EXPECT_EQ(result.length, 0);

    string_result_free(&result);
}

TEST_F(StringUtilsTest, LengthSuccessful)
{
    const char *str = "Hello";
    StringResult result = string_length(str, 100);

    ASSERT_EQ(result.error, STR_OK);
    EXPECT_EQ(result.length, std::strlen(str));
}

TEST_F(StringUtilsTest, LengthNullPointer)
{
    StringResult result = string_length(nullptr, 100);
    EXPECT_EQ(result.error, STR_NULL_POINTER);
}

TEST_F(StringUtilsTest, LengthInvalidMaxLen)
{
    const char *str = "Hello";
    StringResult result = string_length(str, 0);
    EXPECT_EQ(result.error, STR_INVALID_LENGTH);
}

TEST_F(StringUtilsTest, LengthBufferOverflow)
{
    const char *str = "Hello";
    StringResult result = string_length(str, 3);
    EXPECT_EQ(result.error, STR_BUFFER_OVERFLOW);
}

TEST_F(StringUtilsTest, ReverseSuccessful)
{
    const char *original = "Hello";
    StringResult result = string_reverse(original);

    ASSERT_EQ(result.error, STR_OK);
    ASSERT_NE(result.data, nullptr);
    EXPECT_STREQ(result.data, "olleH");
    EXPECT_EQ(result.length, std::strlen(original));

    string_result_free(&result);
}

TEST_F(StringUtilsTest, ReverseNullPointer)
{
    StringResult result = string_reverse(nullptr);
    EXPECT_EQ(result.error, STR_NULL_POINTER);
}

TEST_F(StringUtilsTest, ReverseSingleCharacter)
{
    const char *single = "A";
    StringResult result = string_reverse(single);

    ASSERT_EQ(result.error, STR_OK);
    ASSERT_NE(result.data, nullptr);
    EXPECT_STREQ(result.data, "A");

    string_result_free(&result);
}

TEST_F(StringUtilsTest, ReverseEmptyString)
{
    const char *empty = "";
    StringResult result = string_reverse(empty);

    ASSERT_EQ(result.error, STR_OK);
    ASSERT_NE(result.data, nullptr);
    EXPECT_STREQ(result.data, "");
    EXPECT_EQ(result.length, 0);

    string_result_free(&result);
}

TEST_F(StringUtilsTest, ResultFreeNullSafe)
{
    StringResult result = {STR_OK, nullptr, 0};
    EXPECT_NO_THROW(string_result_free(&result));
    EXPECT_NO_THROW(string_result_free(nullptr));
}
