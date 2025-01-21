/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:16:22 by ilevy             #+#    #+#             */
/*   Updated: 2025/01/20 18:02:13 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/libft.h"

//Searches for the first instance of character <character> in string <s1> and returns the string starting at the index.
//If the character isn't found in the string, return NULL
char	*ft_strchr(const char *s1, int character)
{
	unsigned int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == (char)character)
			return ((char *)s1 + i);
		i++;
	}
	if (s1[i] == (char)character)
		return ((char *)(s1 + i));
	return (NULL);
}
