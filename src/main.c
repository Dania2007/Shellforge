#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/history.h>
#include <readline/readline.h>

#include "lexer.h"

int main(void)
{
    char *line;

    printf("=====================================\n");
    printf("             Shellforge\n");
    printf("    A Unix Style Shell written in C\n");
    printf("=====================================\n");

    while (1)
    {
        line = readline("shellforge$ ");

        if (line == NULL)
        {
            printf("\nGoodbye!\n");
            break;
        }

        if (strlen(line) == 0)
        {
            free(line);
            continue;
        }

        add_history(line);

        if (strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        const char *input = line;
        Token token;
        int index = 0;

        printf("\n------------- TOKENS -------------\n");

        while (1)
        {
            token = get_next_token(&input);

            if (token.type == TOKEN_END)
            {
                printf("%d : END          END\n", index);
                break;
            }

            printf("%d : WORD         %s\n",
                   index,
                   token.value);

            index++;
        }

        printf("----------------------------------\n");

        free(line);
    }

    return 0;
}
