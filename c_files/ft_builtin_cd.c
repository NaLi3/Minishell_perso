/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:59:14 by ilevy             #+#    #+#             */
/*   Updated: 2025/01/14 18:02:44 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_minishell.h"

int ft_cd(char *pathname)
{
    if (chdir(pathname) == -1)
    {
        ft_printf(2, "%s\n", strerror(errno));
        return (-1);
    }
    return (0);
}