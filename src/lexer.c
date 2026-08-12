#include <ctype.h>
#include "lexer.h"

Token get_next_token(const char **input)
{
    Token token;
    int i = 0;

    /* Skip spaces and tabs */
    while (**input == ' ' || **input == '\t') {
        (*input)++;
    }

    /* End of input */
    if (**input == '\0') {
        token.type = TOKEN_END;
        token.value[0] = '\0';
        return token;
    }
    token.type=TOKEN_WORD;

     while (**input != '\0' &&
           **input != ' ' &&
           **input != '\t') {

        if (i < MAX_TOKEN_LENGTH - 1) {
            token.value[i++] = **input;
        }

        (*input)++;
    }

    token.value[i] = '\0';

    return token;
}
