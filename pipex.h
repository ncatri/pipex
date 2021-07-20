#ifndef PIPEX_H
# define PIPEX_H

enum e_returns{SUCCESS, ERROR};

int	parse_files(int argc, char **argv, int *fildes_ptr);
int	error(char *msg);

#endif
