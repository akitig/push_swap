/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mincost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:57:51 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/16 15:17:47 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// 各要素の操作コストを計算する関数
void	calculate_cost(t_var *var)
{
	t_stk	*tmp_b;
	int		size_a;
	int		size_b;

	size_a = var->a_size;
	size_b = var->b_size;
	tmp_b = var->b;
	while (tmp_b)
	{
		if (tmp_b->pos <= size_b / 2)
			tmp_b->cost_b = tmp_b->pos;
		else
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		if (tmp_b->target_pos <= size_a / 2)
			tmp_b->cost_a = tmp_b->target_pos;
		else
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

// 最小の操作コストを持つ要素を見つける関数
void	find_cheapest_move(t_var *var, int *cost_a, int *cost_b)
{
	t_stk	*tmp_b;
	int		cheapest;
	int		total_cost;

	tmp_b = var->b;
	cheapest = INT_MAX;
	while (tmp_b)
	{
		total_cost = ft_abs(tmp_b->cost_a) + ft_abs(tmp_b->cost_b);
		if ((tmp_b->cost_a > 0 && tmp_b->cost_b > 0) || (tmp_b->cost_a < 0
				&& tmp_b->cost_b < 0))
		{
			total_cost -= ft_min(ft_abs(tmp_b->cost_a), ft_abs(tmp_b->cost_b));
		}
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			*cost_a = tmp_b->cost_a;
			*cost_b = tmp_b->cost_b;
		}
		tmp_b = tmp_b->next;
	}
}
