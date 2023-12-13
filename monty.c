#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


stack_t *stack = NULL;

void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number);

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        execute_instruction(line, &stack, line_number);
    }

    fclose(file);
    free(line);
    return 0;
}

void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
    char *token;
    int value;

    token = strtok(opcode, " \t\n");

    if (!token || token[0] == '#')
        return;

    if (strcmp(token, "push") == 0)
    {
        token = strtok(NULL, " \t\n");
        if (!token)
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        value = atoi(token);
        push(stack, value, line_number);
    }
    else if (strcmp(token, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
        exit(EXIT_FAILURE);
    }
}
