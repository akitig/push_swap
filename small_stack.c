/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:59:30 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/16 15:22:07 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// 2要素のスタックをソートする関数
void	sort_two_elements(t_var *var)
{
	if (var->a->index > var->a->next->index)
		sa(var);
}

// 3要素のスタックをソートする関数
void	sort_three_elements(t_var *var)
{
	int	a;
	int	b;
	int	c;

	a = var->a->index;
	b = var->a->next->index;
	c = var->a->next->next->index;
	if (a > b && b < c && a < c)
		sa(var);
	else if (a > b && b > c)
	{
		sa(var);
		rra(var);
	}
	else if (a > b && b < c && a > c)
		ra(var);
	else if (a < b && b > c && a < c)
	{
		sa(var);
		ra(var);
	}
	else if (a < b && b > c && a > c)
		rra(var);
}

// 小さいスタックをソートする関数
void	sort_small_stack(t_var *var)
{
	if (var->a_size == 2)
		sort_two_elements(var);
	else if (var->a_size == 3)
		sort_three_elements(var);
}
