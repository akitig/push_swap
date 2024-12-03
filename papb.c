/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:50:39 by akunimot          #+#    #+#             */
/*   Updated: 2024/12/03 16:04:03 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// プッシュ操作
void	push(t_stk **from, t_stk **to, int *from_size, int *to_size)
{
	t_stk	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	(*from_size)--;
	(*to_size)++;
}

// pa, pb操作
void	pa(t_var *var)
{
	push(&var->b, &var->a, &var->b_size, &var->a_size);
	ft_printf("pa\n");
}

void	pb(t_var *var)
{
	push(&var->a, &var->b, &var->a_size, &var->b_size);
	ft_printf("pb\n");
}
