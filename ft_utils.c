/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:46:01 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/18 18:14:21 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// ユーティリティ関数
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

// スワップ操作
void	swap(t_stk **stack)
{
	t_stk	*first;
	t_stk	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

// 配列をバブルソートする関数
void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
