#include "stringLibrary.h"

#define UNUSED(a) ((void) (a))

size_t stringLength(const char *str)
{
    if (!str)
        return 0;
    unsigned int len = 0;
    while (str[len])
        len++;

    return len;
}

char *stringCopy(char *result, const char *origin)
{
    if (!origin)
        return NULL;
    unsigned int i;
    for (i = 0; origin[i] != '\0'; i++)
        result[i] = origin[i];
    result[i] = '\0';

    return result;
}

size_t stringCountChar(const char *string, char ch)
{
    if (!string)
        return 0;
    unsigned int counter = 0;
    for (unsigned int i = 0; string[i] != '\0'; i++)
        if (string[i] == ch)
            counter++;

    return counter;
}

int stringCompare(const char *first, const char *second)
{
    unsigned int i;
    for (i = 0; first[i] != '\0' && second[i] != '\0'; i++) {
        if (first[i] < second[i])
            return -1;
        if (first[i] > second[i])
            return 1;
    }
    if (first[i] < second[i])
        return -1;
    if (first[i] > second[i])
        return 1;
    return 0;
}

int stringCompareN(const char *first, const char *second, size_t n)
{
    if (n > stringLength(first) || n > stringLength(second)) {
        if (stringLength(first) > stringLength(second))
            n = stringLength(second);
        else
            n = stringLength(first);
    }
    for (unsigned int i = 0; i < n; i++)
        if (first[i] != second[i])
            return 1;

    return 0;
}

size_t stringCountSubstring(const char *original, const char *substring)
{

    return 0;
}


const char *stringFindChar(const char *original, const char ch)
{
    for (unsigned int i = 0; original[i] != '\0'; i++)
        if (original[i] == ch)
            return original+i;

    return NULL;
}

const char *stringFindSubstring(const char *orig, const char *sub)
{
    unsigned int len = stringLength(sub);
    unsigned int i, j;
    for (i = 0; i < stringLength(orig); i++) {
        for (j = 0; j < len; j++) {
            if (orig[i+j] != sub[j] )
                break;
        }
        if (j == len)
            return orig+i;
    }
    return NULL;
}

char *stringToUpper(const char *origin, char *result)
{
    int i = 0;
    while (*(origin+i)) {
        if (*(origin+i) >= 'a' && *(origin+i) <= 'z')
            *(result+i) = *(origin+i) - 32;
        else
            *(result+i) = *(origin+i);
        i++;
    }
    *(result+i) = '\0';

    return result;
}

char *stringToLower(const char *origin, char *result)
{
    int i = 0;
    while (*(origin+i)) {
        if (*(origin+i) >= 'A' && *(origin+i) <= 'Z')
            *(result+i) = *(origin+i) + 32;
        else
            *(result+i) = *(origin+i);
        i++;
    }
    *(result+i) = '\0';

    return result;
}
