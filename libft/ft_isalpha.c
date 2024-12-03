/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:49:46 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/15 21:18:22 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	a;

	a = 'a';
	printf("lib:%d own:%d\n", isalpha(a), ft_isalpha(a));
	a = '1';
	printf("lib:%d own:%d\n", isalpha(a), ft_isalpha(a));
	return (0);
}
*/