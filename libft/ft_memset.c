/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:40:35 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/27 01:31:00 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t len)
{
	size_t			i;
	unsigned char	*ans;

	i = 0;
	ans = (unsigned char *)buf;
	while (i < len)
	{
		ans[i] = ch;
		i++;
	}
	return (ans);
}
