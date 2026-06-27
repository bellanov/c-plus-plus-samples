#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <stdexcept>
#include <string>

/**
 * Exception thrown by StringUtils operations.
 * Modern pattern: Exception-based error handling.
 */
class StringException : public std::runtime_error
{
  public:
    explicit StringException(const std::string &message) : std::runtime_error(message)
    {
    }
};

/**
 * Utility class for safe string operations.
 * Modern C++ patterns demonstrated:
 * - RAII (Resource Acquisition Is Initialization) with std::string
 * - Exception-based error handling
 * - Static utility methods
 * - No manual memory management
 */
class StringUtils
{
  public:
    /**
     * Safely duplicate a string.
     * Modern pattern: std::string handles memory automatically.
     *
     * @param src Source string to duplicate
     * @return Duplicated string
     * @throws StringException if src is empty
     */
    static std::string duplicate(const std::string &src);

    /**
     * Safely concatenate two strings.
     * Modern pattern: std::string operator+ handles concatenation safely.
     *
     * @param str1 First string
     * @param str2 Second string
     * @return Concatenated result
     * @throws StringException if either string is empty
     */
    static std::string concat(const std::string &str1, const std::string &str2);

    /**
     * Get string length safely.
     * Modern pattern: std::string provides built-in length() method.
     *
     * @param str String to measure
     * @return Length of the string
     * @throws StringException if string is empty or exceeds max length
     */
    static size_t length(const std::string &str, size_t max_len = 10000);

    /**
     * Reverse a string safely.
     * Modern pattern: Uses STL algorithms for safe operations.
     *
     * @param src Source string to reverse
     * @return Reversed string
     * @throws StringException if src is empty
     */
    static std::string reverse(const std::string &src);

    /**
     * Transform string to uppercase.
     * Bonus functionality demonstrating modern C++ patterns.
     *
     * @param src Source string
     * @return Uppercase string
     * @throws StringException if src is empty
     */
    static std::string toUpperCase(const std::string &src);

    /**
     * Transform string to lowercase.
     * Bonus functionality demonstrating modern C++ patterns.
     *
     * @param src Source string
     * @return Lowercase string
     * @throws StringException if src is empty
     */
    static std::string toLowerCase(const std::string &src);

  private:
    // Private constructor to prevent instantiation
    StringUtils() = delete;
    ~StringUtils() = delete;
};

#endif // STRING_UTILS_HPP
