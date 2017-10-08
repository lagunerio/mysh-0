#include "utils.h"
#include "string.h"

#define COMAND_SIZE 8096



void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char s[2] = {" "};
	int count = 0;
	char *token[COMMAND_SIZE/2] = {""};	// Max arguments' is COMMAND_SIZE / 2
	const char *cp_command = *command;

	token[count] = strtok(cp_command, s);

	while (token[count] != NULL) {
		argv[count] = &token[count];
		token[++count] = strtok(NULL, s);
	}

	argc = &count;

	return;


}
