/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:47:15 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/16 15:19:00 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// スタックがソートされているか確認
int	is_sorted(t_stk *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
