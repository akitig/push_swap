/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:45:52 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/16 14:47:43 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// スタックを解放する関数
void	free_stk(t_stk **stk)
{
	t_stk	*tmp;

	while (*stk)
	{
		tmp = (*stk)->next;
		free(*stk);
		*stk = tmp;
	}
}

// スタックに新しい要素を追加する関数
void	stack_add_back(t_stk **stack, t_stk *new_elem)
{
	t_stk	*tmp;

	if (!*stack)
	{
		*stack = new_elem;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem;
}
