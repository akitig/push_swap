/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:20:40 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/18 18:32:41 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// スペースをスキップする関数
const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	return (str);
}

// 符号を解析する関数
const char	*parse_sign(const char *str, int *sign)
{
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	else
		*sign = 1;
	return (str);
}

// 基数を判定する関数
const char	*parse_base(const char *str, int *base)
{
	if (*base == 0)
	{
		if (*str == '0')
		{
			if (*(str + 1) == 'x' || *(str + 1) == 'X')
			{
				*base = 16;
				str += 2;
			}
			else
			{
				*base = 8;
				str++;
			}
		}
		else
			*base = 10;
	}
	else if (*base == 16)
	{
		if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
			str += 2;
	}
	return (str);
}

// メイン関数
long long	ft_strtoll(const char *str, char **endptr, int base)
{
	int			sign;
	long long	result;

	sign = 1;
	str = skip_whitespace(str);
	str = parse_sign(str, &sign);
	str = parse_base(str, &base);
	result = convert_digits(str, endptr, base, sign);
	return (result);
}
