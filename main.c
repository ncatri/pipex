#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // for EXIT_SUCCESS
#include "pipex.h"
#include <string.h>

int main(int argc, char **argv, char **env)
{
	int		fildes[2]; // fildes[0] is for reading, fildes[1] is for writing
	char	*cmd_path;

	if (parse_files(argc, argv, fildes) == ERROR)
		return (error("parsing error"));
	cmd_path = get_command_path(argv[2], env); 
	if (cmd_path == NULL)
		return (error("command not found\n"));
	return (EXIT_SUCCESS);
}

char	*get_command_path(char *cmd, char **env)
{
	char *env_path;
//	char **path_split;
	(void)cmd;
	
	env_path = extract_path_variable(env);
	printf("%s\n", env_path);
	//path_split = ft_split(env_path, ":");
	
	return (env_path);
}

char	*extract_path_variable(char **env)
{
	char	**split_path;
	char	*path_variable;

	if (!env)
		return (NULL);
	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
		{
			split_path = ft_split(*env, "=");
			if (split_path == NULL)
				return (NULL);
			path_variable = ft_strdup(split_path[1]);
			free_split(split_path);
			return (path_variable);
		}
		env++;
	}
	return (NULL);
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
