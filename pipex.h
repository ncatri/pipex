#ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"

enum e_returns{SUCCESS, ERROR};

int	parse_files(int argc, char **argv, int *fildes_ptr);
int	error(char *msg);

char	*get_command_path(char *cmd, char **env);
char	*extract_path_variable(char **env);

#endif
