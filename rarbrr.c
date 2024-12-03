/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarbrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:12:12 by akunimot          #+#    #+#             */
/*   Updated: 2024/12/03 16:04:21 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// ローテート操作
void	rotate(t_stk **stack)
{
	t_stk	*tmp;
	t_stk	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

// ra, rb, rr操作
void	ra(t_var *var)
{
	rotate(&var->a);
	ft_printf("ra\n");
}

void	rb(t_var *var)
{
	rotate(&var->b);
	ft_printf("rb\n");
}

void	rr(t_var *var)
{
	rotate(&var->a);
	rotate(&var->b);
	ft_printf("rr\n");
}
