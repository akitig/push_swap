/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:03:47 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/16 15:07:03 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// チャンクをスタックBにプッシュする関数
void	push_chunks_to_b(t_var *var, int chunk_size)
{
	int	current_chunk;

	current_chunk = 1;
	while (var->a_size > 3)
	{
		if (var->a->index < chunk_size * current_chunk)
		{
			pb(var);
			if (var->b->index < chunk_size * (current_chunk - 1))
				rb(var);
		}
		else
		{
			ra(var);
		}
		if (var->b_size == chunk_size * current_chunk)
			current_chunk++;
	}
}

// スタックAの最小インデックスの位置を見つける関数
int	find_min_index_position(t_var *var)
{
	int		min_pos;
	int		min_index;
	t_stk	*tmp;

	min_pos = 0;
	min_index = INT_MAX;
	tmp = var->a;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

// スタックAを最小値が先頭に来るように回転する関数
void	rotate_stack_a_to_min(t_var *var)
{
	int	min_pos;

	min_pos = find_min_index_position(var);
	if (min_pos <= var->a_size / 2)
	{
		while (min_pos > 0)
		{
			ra(var);
			min_pos--;
		}
	}
	else
	{
		min_pos = var->a_size - min_pos;
		while (min_pos > 0)
		{
			rra(var);
			min_pos--;
		}
	}
}
