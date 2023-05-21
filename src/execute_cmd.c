/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:32:56 by lmangall          #+#    #+#             */
/*   Updated: 2023/04/18 15:03:51 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	write(STDERR_FILENO, INV_CMD, ft_strlen(INV_CMD));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, "\n", 1);
	return (NULL);
}

static void	execute(t_data data)
{
	data.cmd = get_cmd(data.cmd_path, data.cmd_args[0]);
	if (!data.cmd)
	{
		free_child(&data);
		free_parent(&data);
		exit(EXIT_INVCMD);
	}
	execve(data.cmd, data.cmd_args, data.envp);
}

void	first_child(t_data data)
{
	dup2(data.pipe_fd[1], OUT);
	close(data.pipe_fd[0]);
	dup2(data.fd_in, IN);
	data.cmd_args = ft_split(data.argv[2], ' ');
	execute(data);
}

void	second_child(t_data data)
{
	dup2(data.pipe_fd[0], IN);
	close(data.pipe_fd[1]);
	dup2(data.fd_out, OUT);
	data.cmd_args = ft_split(data.argv[3], ' ');
	execute(data);
}
