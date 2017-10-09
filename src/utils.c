#include "utils.h"
#include "string.h"
#include <stdio.h>
#include <malloc.h>

#define COMMAND_SIZE 8096


void mysh_parse_command(const char *command, int *argc, char ***argv)
{

	char s[3] = { " \n" };
	char commands[COMMAND_SIZE];
	char **arguments;
	int count = 0;
	int len; // string length
	char *token;

	//strtok use commands as command; command is const variable
	strcpy(commands, command); 
	len = strlen(commands);

	//Memory Allocation
	*argv = (char **)malloc(sizeof(char*)*len);

	if (*argv == NULL) {
		fprintf(stderr, "no enough memory\n");
		return;
	}

	//Read first argument
	token = strtok(commands, s);

	while (token != NULL) {

		(*argv)[count++] = strdup(token);
		// Increase memory and free old memory when in error.
		arguments = (char **)realloc(*argv, sizeof(char*)*len*(count + 1));
		*argv = arguments;

		if (arguments == NULL) {
			fprintf(stderr, "no enough memory\n");
			// Free old memory.
			for (int i = 0; i < count; i++) {
				free((*argv)[i]);
			}
			free(*argv);
			return;
		}
		// Read next argument
		token = strtok(NULL, s);
	}

	*argc = count;

	return;

}
