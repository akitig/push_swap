/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:52:21 by akunimot          #+#    #+#             */
/*   Updated: 2024/12/03 16:04:33 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// リバースローテート操作
void	reverse_rotate(t_stk **stack)
{
	t_stk	*prev;
	t_stk	*curr;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	curr = *stack;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *stack;
	*stack = curr;
}

// rra, rrb, rrr操作
void	rra(t_var *var)
{
	reverse_rotate(&var->a);
	ft_printf("rra\n");
}

void	rrb(t_var *var)
{
	reverse_rotate(&var->b);
	ft_printf("rrb\n");
}

void	rrr(t_var *var)
{
	reverse_rotate(&var->a);
	reverse_rotate(&var->b);
	ft_printf("rrr\n");
}
