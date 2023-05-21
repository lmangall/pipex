/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:55:17 by lmangall          #+#    #+#             */
/*   Updated: 2023/04/21 20:16:02 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	error(t_data data)
{
	if (data.pid1 == -1 || data.pid2 == -1)
	{
		perror(FORK);
		exit(1);
	}
	if (data.pipe_status == -1)
	{
		free_parent(&data);
		perror(PIPE);
		exit(1);
	}
}

void	error_file(t_data data)
{
	if (data.fd_in == -1)
	{
		free_parent(&data);
		write(STDERR_FILENO, ACCESS_DEN, ft_strlen(ACCESS_DEN));
		write(STDERR_FILENO, data.argv[1], ft_strlen(data.argv[1]));
		exit(0);
		if (access(data.argv[1], F_OK))
		{
			write(STDERR_FILENO, NO_FILE, ft_strlen(NO_FILE));
			write(STDERR_FILENO, data.argv[1], ft_strlen(data.argv[1]));
			exit(0);
		}
	}
	if (data.fd_out == -1)
	{
		free_parent(&data);
		write(STDERR_FILENO, ACCESS_DEN, ft_strlen(ACCESS_DEN));
		write(STDERR_FILENO, data.argv[4], ft_strlen(data.argv[4]));
		exit(127);
	}
}

void	error_args(t_data data)
{
	free_parent(&data);
	ft_putstr_fd(ARGS_MSG, STDERR_FILENO);
	exit(1);
}

void	free_parent(t_data *data)
{
	int	i;

	i = 0;
	close(data->fd_in);
	close(data->fd_out);
	while (data->cmd_path[i])
	{
		free(data->cmd_path[i]);
		i++;
	}
	free(data->cmd_path);
}

void	free_child(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_args[i])
	{
		free(data->cmd_args[i]);
		i++;
	}
	free(data->cmd_args);
	free(data->cmd);
}
