/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:42:16 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/27 01:19:42 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;
	t_list	*new_tmp;

	if (lst == NULL)
		return ;
	new = *lst;
	while (new != NULL)
	{
		new_tmp = new->next;
		ft_lstdelone(new, del);
		new = new_tmp;
	}
	*lst = NULL;
}
