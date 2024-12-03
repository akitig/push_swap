/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasbss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:50:11 by akunimot          #+#    #+#             */
/*   Updated: 2024/12/03 16:04:42 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// sa, sb, ss操作
void	sa(t_var *var)
{
	swap(&var->a);
	ft_printf("sa\n");
}

void	sb(t_var *var)
{
	swap(&var->b);
	ft_printf("sb\n");
}

void	ss(t_var *var)
{
	swap(&var->a);
	swap(&var->b);
	ft_printf("ss\n");
}
