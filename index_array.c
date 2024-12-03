/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:54:07 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/16 15:18:40 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// スタックをインデックス化する関数
void	index_stack(t_var *var)
{
	int	*arr;
	int	size;

	size = var->a_size;
	arr = create_array_from_stack(var, size);
	if (!arr)
		exit(1);
	bubble_sort(arr, size);
	assign_indices_to_stack(var, arr, size);
	free(arr);
}

// スタックから配列を作成する関数
int	*create_array_from_stack(t_var *var, int size)
{
	int		*arr;
	t_stk	*tmp;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = var->a;
	i = 0;
	while (i < size && tmp)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

// スタックにインデックスを割り当てる関数
void	assign_indices_to_stack(t_var *var, int *arr, int size)
{
	t_stk	*tmp;
	int		i;

	tmp = var->a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->num == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

/// 各要素の位置を更新する関数
void	update_positions(t_var *var)
{
	t_stk	*tmp;
	int		pos;

	pos = 0;
	tmp = var->a;
	while (tmp)
	{
		tmp->pos = pos;
		tmp = tmp->next;
		pos++;
	}
	pos = 0;
	tmp = var->b;
	while (tmp)
	{
		tmp->pos = pos;
		tmp = tmp->next;
		pos++;
	}
}
