#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

/* Error handling - modern pattern using error codes */
typedef enum
{
    STR_OK = 0,
    STR_NULL_POINTER = 1,
    STR_INVALID_LENGTH = 2,
    STR_BUFFER_OVERFLOW = 3,
    STR_ALLOCATION_FAILED = 4,
} StringError;

/* Structure for safe string operations result */
typedef struct
{
    StringError error;
    char *data;
    size_t length;
} StringResult;

/**
 * Safely duplicate a string.
 * Modern pattern: caller must free the returned data if error is STR_OK.
 *
 * @param src Source string to duplicate
 * @return StringResult containing error code and duplicated string
 */
StringResult string_duplicate(const char *src);

/**
 * Safely concatenate two strings into a new buffer.
 * Modern pattern: bounds checking and clear error reporting.
 *
 * @param str1 First string
 * @param str2 Second string
 * @return StringResult containing error code and concatenated string
 */
StringResult string_concat(const char *str1, const char *str2);

/**
 * Calculate string length safely.
 * Modern pattern: wrapper function for safer bounds
 *
 * @param str String to measure
 * @param max_len Maximum length to check (prevents scanning too far)
 * @return StringResult containing length or error
 */
StringResult string_length(const char *str, size_t max_len);

/**
 * Reverse a string safely.
 * Modern pattern: allocates new buffer instead of in-place modification
 *
 * @param src Source string to reverse
 * @return StringResult containing error code and reversed string
 */
StringResult string_reverse(const char *src);

/**
 * Free memory allocated by string operations.
 * Modern pattern: explicit cleanup function
 *
 * @param result StringResult to clean up
 */
void string_result_free(StringResult *result);

#endif /* STRING_UTILS_H */
