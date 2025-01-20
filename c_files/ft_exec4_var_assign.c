/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec4_var_assign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:09:53 by ilevy             #+#    #+#             */
/*   Updated: 2025/01/18 01:09:54 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_minishell.h"

int	ft_exec4_var_assign(t_data *data) // PAS LA VERSION DEFINITIVE
{
	int		ind_equals;
	char	*tok;
	t_var	*var_new;

	if (data->nb_tokens >= 1 && data->tokens->type[0] == CMD)
	{
		tok = data->tokens->name[0];
		ind_equals = ft_strchrp_nonquoted(tok, '=', 2, 0);
		if (ind_equals != -1)
		{
			if (data->nb_tokens > 1)
				return (STOP_VAR_ASSIGN_NOTALONE);
			tok[ind_equals] = '\0';
			var_new = ft_var_new(tok, tok + ind_equals + 1, 0);
			if (!var_new)
				return (1);
			data->env = ft_var_push_back(data->env, var_new);
			return (STOP_VAR_ASSIGN);
		}
	}
	return (0);
}
