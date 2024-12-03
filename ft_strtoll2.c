/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:22:03 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/18 18:26:22 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// オーバーフローをチェックして結果を更新する関数
int	update_result(long long *result, int digit, int base)
{
	if (*result > (LLONG_MAX - digit) / base)
	{
		*result = LLONG_MAX;
		return (0);
	}
	*result = *result * base + digit;
	return (1);
}

// 文字を数字に変換する関数
int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	else
		return (-1);
}

// 数字を変換して結果を累積する関数
long long	convert_digits(const char *str, char **endptr, int base, int sign)
{
	long long	result;
	int			digit;

	result = 0;
	while (*str)
	{
		digit = char_to_digit(*str);
		if (digit == -1 || digit >= base)
			break ;
		if (!update_result(&result, digit, base))
			break ;
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (sign * result);
}
