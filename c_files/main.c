/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:07:59 by ilevy             #+#    #+#             */
/*   Updated: 2025/01/18 02:14:53 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char	*line;

	(void) argc;
	(void) argv;
	if (ft_initialize_data(&data, env) == -1) // Prendre les donnees de l'environement de depart et les ajouter a un struct data.
		return (errno); // Rendre un message derreur si on ne trouve pas l'environment.
	while (1)
	{
		line = readline("minishell> "); //Cree un prompte affichant "minishell >"
		if (!line)
		{
			ft_free_all(data, line);
			printf("exiting minishell.\n"); //Si on a pas de place pour la ligne vu que readline est associe a malloc
			return (MALLOC_ERROR);
		}
		else if (ft_empty_line(line) == 1)
		{
			free(line); // on libere la ligne pour une prochaine exec.
			continue ; //On skip les commandes nulles.
		}
		add_history(line); //On ajoute la ligne a l'histoire des lignes precedentes donnees par l'utilisateur
		if (ft_line_to_data(data, line) == -1) //On prend l'input de l'utilisateur, et on le tokenize pour faciliter l'execution.
				continue ; // Si la ligne est incoherente genre "wgfwijghw"
		ft_exec1_exectree_recurr(data, data->root, 0);
		ft_erase_tokens(data); //On efface les infos donnees par la ligne qu'on vient d'executer.
		free(line); // on libere la ligne pour une prochaine exec.
	}
	rl_clear_history();
	ft_free_all(data, line);
	return (0);
}
