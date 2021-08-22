// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>

#define eprintf(args...) fprintf(stderr, ##args)

int match(const char *regexp, const char *text);
int matchstar(int c, const char *regexp, const char *text);
int matchhere(const char *regexp, const char *text);

/* matchstar: search for c*regexp at beginning of text */
int matchstar(int c, const char *regexp, const char *text)
{
    do { /* a * matches zero or more instances */
        if (matchhere(regexp, text)) {
            return 1;
        }
    } while (*text != '\0' && (*text++ == c || c == '.'));

    return 0;
}

/* matchhere: search for regexp at beginning of text */
int matchhere(const char *regexp, const char *text)
{
    if (regexp[0] == '\0') {
        return 1;
    }

    if (regexp[1] == '*') {
        return matchstar(regexp[0], regexp+2, text);
    }

    if (regexp[0] == '$' && regexp[1] == '\0') {
        return *text == '\0';
    }

    if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text)) {
        return matchhere(regexp+1, text+1);
    }

    return 0;
}

/* match: search for regexp anywhere in text */
int match(const char *regexp, const char *text)
{
    if (regexp[0] == '^') {
        return matchhere(regexp+1, text);
    }

    do { /* must look even if string is empty */
        if (matchhere(regexp, text)) {
            return 1;
        }
    } while (*text++ != '\0');

    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc < 3) {
        eprintf("You SHOULD give a pattern and a text");

        return EXIT_FAILURE;
    }

    const char *pattern = argv[1];
    const char *text = argv[2];

    if (match(pattern, text)) {
        printf("Match!\n");
    } else {
        printf("Oops!\n");
    }

    return 0;
}
