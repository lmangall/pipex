/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:37:09 by lmangall          #+#    #+#             */
/*   Updated: 2023/04/16 21:46:17 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static int	file_open(char *file, int mode, t_data data)
{
	int	i;

	i = 0;
	if (mode == IN)
		i = (open(file, O_RDONLY));
	else
		i = (open(file, O_TRUNC | O_CREAT | O_RDWR, 0644));
	if (i < 0)
		error(data);
	return (i);
}

static char	*get_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

static void	fill_list(t_data *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->fd_in = -1;
	data->pid1 = -2;
	data->pid2 = -2;
	data->pipe_status = -2;
	data->fd_out = -1;
	data->path = get_path(envp);
	data->cmd_path = ft_split(data->path, ':');
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		status;

	fill_list(&data, argc, argv, envp);
	if (argc != 5)
		error_args(data);
	data.fd_in = file_open(argv[1], IN, data);
	data.fd_out = file_open(argv[4], OUT, data);
	error_file(data);
	data.pipe_status = pipe(data.pipe_fd);
	error(data);
	data.pid1 = fork();
	if (data.pid1 == 0)
		first_child(data);
	data.pid2 = fork();
	if (data.pid2 == 0)
		second_child(data);
	error(data);
	close(data.pipe_fd[0]);
	close(data.pipe_fd[1]);
	waitpid(data.pid1, &status, 0);
	waitpid(data.pid2, &status, 0);
	free_parent(&data);
	return (WEXITSTATUS(status));
}
