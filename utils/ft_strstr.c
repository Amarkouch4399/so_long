/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:23:38 by ouamarko          #+#    #+#             */
/*   Updated: 2025/10/29 15:50:11 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*tab1;
	char	*tab2;
	size_t	i;
	size_t	j;

	tab1 = (char *)big;
	tab2 = (char *)little;
	i = 0;
	if (tab2[0] == '\0')
		return (tab1);
	while (tab1[i] != '\0')
	{
		if (tab1[i] == tab2[0])
		{
			j = 0;
			while (tab2[j] != '\0' && tab1[i + j] == tab2[j])
				j++;
			if (tab2[j] == '\0')
				return (&tab1[i]);
		}
		i++;
	}
	return (NULL);
}
