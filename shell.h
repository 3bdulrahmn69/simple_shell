#ifndef SHeLL_H
#define SHELL_H

			/* Libraris */
#include <stdio.h> /* for printf*/
#include <unistd.h> /* for fork, execve*/
#include <stdlib.h>
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h> /* for errno and perror */
#include <sys/types.h> /* for type pid */
#include <sys/wait.h> /* for wait */
#include <sys/stat.h> /* for use of stat function */
#include <signal.h> /* for signal management */
#include <fcntl.h> /* for open files*/
			/* Buffers */
#define PROMPT_MSG "$" /* Needed to work with signal */
#define UNUSED __attribute__((unused)) /* Resume from the unused attibute */
#define BUFFER_SIZE 1024
#define SIGINT 2
#define SIGILL 4


/************* FORMATTED STRING FOR HELP BUILT IN **************/

#define HELP_CD_MSG "cd=\n"\
"cd:\tcd [dir]\n\n"\
"	Change the shell working directory.\n\n"\
"	If no argument is given to cd the command will be interpreted\n"\
"	as cd $HOME.\n"\
"	if the argumenthelp is - (cd -), the command will be interpreted\n"\
"	as cd $OLDPWD.\n\n"

#define HELP_EXIT_MSG "exit=\n"\
"exit:\texit [STATUS]\n\n"\
"	Exit of the simple-shell.\n\n"\
"	Exits the shell with a status of N.  If N is omitted, the exit status\n"\
"	is that of the last command executed.\n\n"

#define HELP_ENV_MSG "env=\n"\
"env:\tenv \n\n"\
"	Print environment.\n\n"\
"	The env command will be print a complete list of enviroment variables.\n\n"

#define HELP_SETENV_MSG "setenv=\n"\
"setenv:\tsetenv VARIABLE VALUE\n\n"\
"	Change or add an environment variable.\n\n"\
"	initialize a new environment variable, or modify an existing one\n"\
"	When there are not correct numbers of arguments print error message.\n\n"

#define HELP_UNSETENV_MSG "unsetenv=\n"\
"unsetenv:\tunsetenv VARIABLE\n\n"\
"	The unsetenv function deletes one variable from the environment.\n\n"\
"	Wen there are not correct numbers of arguments print error message.\n\n"

#define HELP_MSG "help=\n"\
"help:\thelp [BUILTIN_NAME]\n\n"\
"	Display information about builtin commands.\n\n"\
"	Displays brief summaries of builtin commands.  If BUILTIN_NAME is\n"\
"	specified, gives detailed help on all commands matching BUILTIN_NAME,\n"\
"	otherwise the list of help topics is printed BUILTIN_NAME list.\n"\
"	Arguments:\n\n"\
"	BUILTIN_NAME specifiying a help topic.\n\n"\
"	cd\t[dir]\n"\
"	exit\t[status]\n"\
"	env\n"\
"	setenv\t[variable value]\n"\
"	unset\t[variable]\n"\
"	help\t[built_name]\n\n"

			/* Struct*/
/**
 * struct info- struct for the program's data
 * @program_name: the name of the executable
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of excecuted comands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases.
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;


/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;

			/* Prototypes */
int builtin_env(data_of_program *data);
int builtin_set_env(data_of_program *data);
int builtin_unset_env(data_of_program *data);

int builtins_list(data_of_program *data);

int builtin_alias(data_of_program *data);
int builtin_cd(data_of_program *data);
int builtin_exit(data_of_program *data);
int builtin_help(data_of_program *data);
int set_work_directory(data_of_program *data, char *new_dir);

char *env_get_key(char *key, data_of_program *data);
int env_remove_key(char *key, data_of_program *data);
int env_set_key(char *key, char *value, data_of_program *data);
void print_environ(data_of_program *data);

int buffer_add(char *buffer, char *str_to_add);
void expand_alias(data_of_program *data);
void expand_variables(data_of_program *data);

int execute(data_of_program *data);

int check_file(char *full_path);
int find_program(data_of_program *data);
char **tokenize_path(data_of_program *data);

void free_recurrent_data(data_of_program *data);
void free_all_data(data_of_program *data);
void free_array_of_pointers(char **array);

void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);

int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_of_program *data);

int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *string1, char *string2, int number);
char *str_concat(char *string1, char *string2);
void str_reverse(char *string);

char *get_alias(data_of_program *data, char *name);
int print_alias(data_of_program *data, char *alias);
int set_alias(char *alias_string, data_of_program *data);

int my_getline(data_of_program *data);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);

char *_strtok(char *line, char *delim);

void tokenize(data_of_program *data);

void sisifo(char *prompt, data_of_program *data);
void inicialize_data(data_of_program *data, int argc, char *argv[], char **env);
void handle_ctrl_c(int opr UNUSED);



#endif /* SHELL_H */
