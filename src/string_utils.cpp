#include "string_utils.hpp"
#include <algorithm>
#include <cctype>

std::string StringUtils::duplicate(const std::string &src)
{
    if(src.empty())
    {
        throw StringException("Cannot duplicate empty string");
    }
    return src;
}

std::string StringUtils::concat(const std::string &str1, const std::string &str2)
{
    if(str1.empty() || str2.empty())
    {
        throw StringException("Cannot concatenate with empty string");
    }
    return str1 + str2;
}

size_t StringUtils::length(const std::string &str, size_t max_len)
{
    if(str.empty())
    {
        throw StringException("Cannot measure length of empty string");
    }

    if(str.length() > max_len)
    {
        throw StringException("String length exceeds maximum allowed length");
    }

    return str.length();
}

std::string StringUtils::reverse(const std::string &src)
{
    if(src.empty())
    {
        throw StringException("Cannot reverse empty string");
    }

    std::string reversed = src;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

std::string StringUtils::toUpperCase(const std::string &src)
{
    if(src.empty())
    {
        throw StringException("Cannot transform empty string");
    }

    std::string result = src;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}

std::string StringUtils::toLowerCase(const std::string &src)
{
    if(src.empty())
    {
        throw StringException("Cannot transform empty string");
    }

    std::string result = src;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}
