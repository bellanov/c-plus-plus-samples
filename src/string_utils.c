#include "string_utils.h"
#include <stdlib.h>
#include <string.h>

StringResult string_duplicate(const char *src)
{
    StringResult result = {STR_OK, NULL, 0};

    if(src == NULL)
    {
        result.error = STR_NULL_POINTER;
        return result;
    }

    size_t len = strlen(src);
    char *duplicate = (char *)malloc(len + 1);

    if(duplicate == NULL)
    {
        result.error = STR_ALLOCATION_FAILED;
        return result;
    }

    strcpy(duplicate, src);
    result.data = duplicate;
    result.length = len;

    return result;
}

StringResult string_concat(const char *str1, const char *str2)
{
    StringResult result = {STR_OK, NULL, 0};

    if(str1 == NULL || str2 == NULL)
    {
        result.error = STR_NULL_POINTER;
        return result;
    }

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t total_len = len1 + len2;

    /* Simple overflow check */
    if(total_len < len1 || total_len < len2)
    {
        result.error = STR_BUFFER_OVERFLOW;
        return result;
    }

    char *concatenated = (char *)malloc(total_len + 1);

    if(concatenated == NULL)
    {
        result.error = STR_ALLOCATION_FAILED;
        return result;
    }

    strcpy(concatenated, str1);
    strcat(concatenated, str2);

    result.data = concatenated;
    result.length = total_len;

    return result;
}

StringResult string_length(const char *str, size_t max_len)
{
    StringResult result = {STR_OK, NULL, 0};

    if(str == NULL)
    {
        result.error = STR_NULL_POINTER;
        return result;
    }

    if(max_len == 0)
    {
        result.error = STR_INVALID_LENGTH;
        return result;
    }

    size_t len = 0;
    while(len < max_len && str[len] != '\0')
    {
        len++;
    }

    if(len >= max_len && str[len] != '\0')
    {
        result.error = STR_BUFFER_OVERFLOW;
        return result;
    }

    result.length = len;
    return result;
}

StringResult string_reverse(const char *src)
{
    StringResult result = {STR_OK, NULL, 0};

    if(src == NULL)
    {
        result.error = STR_NULL_POINTER;
        return result;
    }

    size_t len = strlen(src);
    char *reversed = (char *)malloc(len + 1);

    if(reversed == NULL)
    {
        result.error = STR_ALLOCATION_FAILED;
        return result;
    }

    for(size_t i = 0; i < len; i++)
    {
        reversed[i] = src[len - 1 - i];
    }
    reversed[len] = '\0';

    result.data = reversed;
    result.length = len;

    return result;
}

void string_result_free(StringResult *result)
{
    if(result != NULL && result->data != NULL)
    {
        free(result->data);
        result->data = NULL;
        result->length = 0;
    }
}
