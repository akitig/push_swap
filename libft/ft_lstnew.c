/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:42:41 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/23 13:46:48 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ans;

	ans = (t_list *)malloc(sizeof(t_list));
	if (ans == NULL)
		return (NULL);
	ans->content = content;
	ans->next = NULL;
	return (ans);
}

/*
#include <string.h>
#include <stdio.h>
int main()
{
	puts("----ft_lstnew------");
	char	test11[] = "12345";
//	char	test21[] = "abcde";
//	char	test31[] = "123\n";

	t_list	*ans = ft_lstnew(test11);
	
	while ()
	{
		t_list	*p;
		p = ans.next;
		printf("%s",ans.next);

}
*/
