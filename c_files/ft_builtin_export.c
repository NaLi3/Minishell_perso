/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:47:12 by ilevy             #+#    #+#             */
/*   Updated: 2025/01/17 18:56:55 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_minishell.h"

int    ft_builtin_export(t_data *data, char *name, char *arg)
{
	t_var	*var;

	var = ft_var_new(name, arg , 1);
	if (!var)
	{
		free(var);
		return (-1);
	}

}
