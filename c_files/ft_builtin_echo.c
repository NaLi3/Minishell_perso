/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:27:02 by ilevy             #+#    #+#             */
/*   Updated: 2025/01/14 17:36:27 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_minishell.h"

void    ft_echo(char *string, int n_option)
{
    ft_printf(1, "%s", string);
    if (!n_option)
        ft_printf(1, "\n");
    return ;
}