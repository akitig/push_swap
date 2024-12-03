/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:04:27 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/15 21:21:31 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	a;

	a = 'a';
	printf("lib:%d own:%d\n", isalnum(a), ft_isalnum(a));
	a = '1';
	printf("lib:%d own:%d\n", isalnum(a), ft_isalnum(a));
	return (0);
}
*/
