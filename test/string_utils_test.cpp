#include "string_utils.hpp"
#include <gtest/gtest.h>

class StringUtilsTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        // Setup code if needed
    }

    void TearDown() override
    {
        // Cleanup is automatic with std::string
    }
};

// Duplicate tests
TEST_F(StringUtilsTest, DuplicateSuccessful)
{
    std::string original = "Hello, World!";
    std::string result = StringUtils::duplicate(original);

    EXPECT_EQ(result, original);
    EXPECT_EQ(result.length(), original.length());
}

TEST_F(StringUtilsTest, DuplicateEmptyString)
{
    EXPECT_THROW(StringUtils::duplicate(""), StringException);
}

// Concatenate tests
TEST_F(StringUtilsTest, ConcatSuccessful)
{
    std::string str1 = "Hello";
    std::string str2 = "World";
    std::string result = StringUtils::concat(str1, str2);

    EXPECT_EQ(result, "HelloWorld");
    EXPECT_EQ(result.length(), str1.length() + str2.length());
}

TEST_F(StringUtilsTest, ConcatNullFirstString)
{
    EXPECT_THROW(StringUtils::concat("", "World"), StringException);
}

TEST_F(StringUtilsTest, ConcatNullSecondString)
{
    EXPECT_THROW(StringUtils::concat("Hello", ""), StringException);
}

// Length tests
TEST_F(StringUtilsTest, LengthSuccessful)
{
    std::string str = "Hello";
    size_t result = StringUtils::length(str);

    EXPECT_EQ(result, 5);
}

TEST_F(StringUtilsTest, LengthEmptyString)
{
    EXPECT_THROW(StringUtils::length(""), StringException);
}

TEST_F(StringUtilsTest, LengthExceedsMaxLength)
{
    std::string str = "This is a very long string that exceeds the maximum";
    EXPECT_THROW(StringUtils::length(str, 10), StringException);
}

// Reverse tests
TEST_F(StringUtilsTest, ReverseSuccessful)
{
    std::string original = "Hello";
    std::string result = StringUtils::reverse(original);

    EXPECT_EQ(result, "olleH");
    EXPECT_EQ(result.length(), original.length());
}

TEST_F(StringUtilsTest, ReverseEmptyString)
{
    EXPECT_THROW(StringUtils::reverse(""), StringException);
}

TEST_F(StringUtilsTest, ReverseSingleCharacter)
{
    std::string original = "A";
    std::string result = StringUtils::reverse(original);

    EXPECT_EQ(result, "A");
}

// Uppercase tests
TEST_F(StringUtilsTest, ToUpperCaseSuccessful)
{
    std::string original = "Hello World";
    std::string result = StringUtils::toUpperCase(original);

    EXPECT_EQ(result, "HELLO WORLD");
}

TEST_F(StringUtilsTest, ToUpperCaseEmptyString)
{
    EXPECT_THROW(StringUtils::toUpperCase(""), StringException);
}

TEST_F(StringUtilsTest, ToUpperCaseMixedCase)
{
    std::string original = "HeLLo WoRLd";
    std::string result = StringUtils::toUpperCase(original);

    EXPECT_EQ(result, "HELLO WORLD");
}

// Lowercase tests
TEST_F(StringUtilsTest, ToLowerCaseSuccessful)
{
    std::string original = "Hello World";
    std::string result = StringUtils::toLowerCase(original);

    EXPECT_EQ(result, "hello world");
}

TEST_F(StringUtilsTest, ToLowerCaseEmptyString)
{
    EXPECT_THROW(StringUtils::toLowerCase(""), StringException);
}

TEST_F(StringUtilsTest, ToLowerCaseMixedCase)
{
    std::string original = "HeLLo WoRLd";
    std::string result = StringUtils::toLowerCase(original);

    EXPECT_EQ(result, "hello world");
}

// Integration tests
TEST_F(StringUtilsTest, ChainedOperations)
{
    std::string str = "hello";
    std::string upper = StringUtils::toUpperCase(str);
    std::string reversed = StringUtils::reverse(upper);

    EXPECT_EQ(reversed, "OLLEH");
}

TEST_F(StringUtilsTest, ExceptionHandling)
{
    try
    {
        StringUtils::duplicate("");
        FAIL() << "Expected StringException";
    }
    catch(const StringException &e)
    {
        EXPECT_STREQ(e.what(), "Cannot duplicate empty string");
    }
}
