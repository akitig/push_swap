/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:58:43 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/16 15:19:13 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// 移動を実行する関数
void	move_both_stacks(t_var *var, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(var);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(var);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	move_stack_a(t_var *var, int cost_a)
{
	while (cost_a > 0)
	{
		ra(var);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(var);
		cost_a++;
	}
}

void	move_stack_b(t_var *var, int cost_b)
{
	while (cost_b > 0)
	{
		rb(var);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(var);
		cost_b++;
	}
}

void	execute_moves(t_var *var, int cost_a, int cost_b)
{
	move_both_stacks(var, &cost_a, &cost_b);
	move_stack_a(var, cost_a);
	move_stack_b(var, cost_b);
	pa(var);
}

// 最小の操作コストを持つ要素を移動する関数
void	execute_cheapest_move(t_var *var)
{
	int	cost_a;
	int	cost_b;

	cost_a = 0;
	cost_b = 0;
	find_cheapest_move(var, &cost_a, &cost_b);
	execute_moves(var, cost_a, cost_b);
}
