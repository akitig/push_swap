/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:56:41 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/16 15:18:15 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// スタックA内でのターゲット位置を見つける関数
int	find_closest_higher_index(t_stk *stack, int index_b, int *target_index,
		int *target_pos)
{
	t_stk	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < *target_index)
		{
			*target_index = tmp->index;
			*target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (*target_pos != -1)
		return (1);
	else
		return (0);
}

void	find_smallest_index(t_stk *stack, int *target_index, int *target_pos)
{
	t_stk	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index < *target_index)
		{
			*target_index = tmp->index;
			*target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
}

int	get_target(t_var *var, int index_b)
{
	int	target_index;
	int	target_pos;
	int	found;

	target_index = INT_MAX;
	target_pos = -1;
	found = find_closest_higher_index(var->a, index_b, &target_index,
			&target_pos);
	if (!found)
	{
		target_index = INT_MAX;
		find_smallest_index(var->a, &target_index, &target_pos);
	}
	return (target_pos);
}

// 各要素のターゲット位置を設定する関数
void	get_target_positions(t_var *var)
{
	t_stk	*tmp_b;

	update_positions(var);
	tmp_b = var->b;
	while (tmp_b)
	{
		tmp_b->target_pos = get_target(var, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}
