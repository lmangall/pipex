/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:16:09 by lmangall          #+#    #+#             */
/*   Updated: 2023/04/18 14:56:44 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

# define IN 	0
# define OUT 	1
# define ARGS_MSG "Invalid number of arguments\n"
# define PIPE "Problems to create Pipe"
# define ACCESS_DEN "zsh: permission denied: "
# define INV_OUTF "Invalid output file"
# define NO_FILE "zsh: no such file or directory: "
# define FORK "Problem to fork process"
# define INV_CMD "command not found"
# define EXIT_INVCMD	127

typedef struct data
{
	int		argc;
	char	**argv;
	char	**envp;
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	**cmd_path;
	char	**cmd_args;
	char	*path;
	int		pipe_status;
}	t_data;

int		main(int argc, char **argv, char **envp);
void	error(t_data data);
void	error_file(t_data data);
void	error_args(t_data data);
void	first_child(t_data data);
void	second_child(t_data data);
void	free_child(t_data *data);
void	free_parent(t_data *data);
#endif
