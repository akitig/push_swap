/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 06:12:10 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/23 13:47:06 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cp;

	s_cp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_cp[i] == (unsigned char)c)
			return ((void *)(s_cp + i));
		i++;
	}
	return (NULL);
}
