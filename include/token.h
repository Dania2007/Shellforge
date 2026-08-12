#ifndef TOKEN_H
#define TOKEN_H

#define MAX_TOKEN_LENGTH 64

typedef enum {
    TOKEN_WORD,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

#endif
