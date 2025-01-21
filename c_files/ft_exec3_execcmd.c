/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec3_execcmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:09:32 by ilevy             #+#    #+#             */
/*   Updated: 2025/01/20 20:08:53 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_minishell.h"

//Searches for the execfile of command basename in the environment as well as any directories directly given
//Either being from <data.path_dirs> or <basename> containing a relative or direct path to a file.
//Then store the resulting filename in buffer <filename>
int	ft_exec3_find_execfile(t_data *data, char *basename, char *filename)
{
	if (!basename || !data || !filename)
		return (1);
	if (!ft_exec3_find_execfile_in_dir(data, basename, filename)
		|| !ft_exec3_find_exefile_in_path(data, basename, filename))
		return (0);
	ft_printf(LOGSV, "Couldn't find file %s in either PATH or directory.\n", basename);
	return (1);
}

int	ft_exec3_find_execfile_in_dir(t_data *data, char *basename, char *filename)
{
	char	*dir;
	int		i;

	if (basename[0] == '~')
	{
		i = 0;
		while (data->env)
		{
			if (ft_strncmp("HOME", data->env->name[i], 4) == 0)
				dir = data->env->name[i];
			i++;
		}
		if (!dir)
		{
			ft_printf(LOGSV, "Home directory not found\n");
			return (1);
		}
		filename[0] = '\0';
		ft_strcat(filename, dir);
		ft_strcat(filename, '/');
		ft_strcat(filename, basename + 1);
		if (access(filename, F_OK) == 0 && access(filename, X_OK) == 0)
		{
			ft_printf(LOGSV, "Found file in home directory\n");
			return (0);
		}
		ft_printf(LOGSV, "Could't find or execute file in home directory\n");
		return (1);
	}
	else if (ft_strchr(basename, '/'))
	{
		filename[0] = '\0';
		ft_strcat(filename, basename);
		if (access(filename, F_OK) == 0 && access(filename, X_OK) == 0)
		{
			ft_printf(LOGSV, "Found file with absolute or relative path.\n");
			return (0);
		}
	}
	ft_printf(LOGSV, "Couldn't find file\n");
	return (1);
}

// Searches for the executable file of command <basename>
// in the directories defined in <data.path_dirs>
// and stores the resulting filename in buffer <filename>
int	ft_exec3_find_execfile_in_path(t_data *data, char *basename, char *filename)
{
	int		ind;

	ind = 0;
	while (data->path_dirs[ind])
	{
		filename[0] = '\0';
		ft_strcat(filename, data->path_dirs[ind]);
		ft_strcat(filename, "/");
		ft_strcat(filename, basename);
		if (access(filename, F_OK) == 0 && access(filename, X_OK) == 0)
		{
			ft_printf(LOGSV, "Found file %s in directory %s with full path being %s", basename, data->path_dirs[ind], filename);
			return (0);
		}
		ind++;
	}
	return (1);
}

// Function called by child process created when a leaf node forks,
// 		so the child process is being waited by its leaf node parent,
// 			and its sole purpose is to transmogrify into another program
// 			thanks to <execve>
// To set up the transmogrification :
// 		1. determine the executable file for the command
// 			(if none is found, exits with adequate code)
// 		2. change the process' stdin and stdout with <dup>
// 			according to the node's <fdin> and <fdout>
// 		3. call execve and exit with adequate code if it fails
void	ft_exec3_execcmd(t_data *data, t_node *current)
{
	char	exec_file[PATH_MAX_LEN];

	if (ft_exec3_find_execfile(data, current->cmd_words[0], exec_file))
	{
		ft_printf(LOGSV, "[EXEC3] node type %d at %p - no execfile cmd %s\n",
			current->type, current, current->cmd_words[0]);
		exit(1);
	}
	free(current->cmd_words[0]);
	current->cmd_words[0] = ft_strdup(exec_file);
	if (!(current->cmd_words[0]))
		exit(1);
	ft_printf(LOGSV, "[EXEC3] node type %d at %p - found execfile named %s\n",
		current->type, current, exec_file);
	if (current->fd_in != 0)
		dup2(current->fd_in, 0);
	if (current->fd_out != 1)
		dup2(current->fd_out, 1);
	if (execve(current->cmd_words[0], current->cmd_words, NULL) == -1)
		exit(1);
}
