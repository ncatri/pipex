#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // for EXIT_SUCCESS
#include "pipex.h"

int main(int argc, char **argv)
{
	int		fildes[2]; // fildes[0] is for reading, fildes[1] is for writing
	pid_t	childpid;

	if (parse_files(argc, argv, fildes) == ERROR)
		return (error("parsing error"));
	childpid = 4;
//	create_pipe();

	return (EXIT_SUCCESS);
}

int	parse_files(int argc, char **argv, int *fildes_ptr)
{
	if (argc != 5)
		return (ERROR);
	fildes_ptr[0] = open(argv[1], O_RDONLY);
	if (fildes_ptr[0] == -1)
		return (ERROR);
	fildes_ptr[1] = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (fildes_ptr[1] == -1)
	{
		close(fildes_ptr[0]);
		return (ERROR);
	}
	return (SUCCESS);
}

int	error(char *msg)
{
	printf("%s\n", msg);
	return (ERROR);
}
