/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:47:15 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/18 18:08:34 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// 重複チェック
int	is_duplicate(t_stk *stack, int num)
{
	t_stk	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->num == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// 数値をパースしてバリデートする関数
int	parse_and_validate_number(char *arg, long long *num)
{
	char	*endptr;

	*num = ft_strtoll(arg, &endptr, 10);
	if (*endptr != '\0' || *num > INT_MAX || *num < INT_MIN)
		return (0);
	return (1);
}

// 新しいスタック要素を作成する関数
t_stk	*create_new_element(int num)
{
	t_stk	*new_elem;

	new_elem = malloc(sizeof(t_stk));
	if (!new_elem)
		return (NULL);
	new_elem->num = num;
	new_elem->index = -1;
	new_elem->pos = -1;
	new_elem->target_pos = -1;
	new_elem->cost_a = -1;
	new_elem->cost_b = -1;
	new_elem->next = NULL;
	return (new_elem);
}

// 引数をチェックし、スタックに積む関数
void	check_and_stack_element(char *arg, t_var *var)
{
	long long	num;
	t_stk		*new_elem;

	if (!parse_and_validate_number(arg, &num))
	{
		var->error = 1;
		return ;
	}
	if (is_duplicate(var->a, (int)num))
	{
		var->error = 1;
		return ;
	}
	new_elem = create_new_element((int)num);
	if (!new_elem)
	{
		var->error = 1;
		return ;
	}
	stack_add_back(&var->a, new_elem);
	var->a_size++;
}

void	check_and_stack_argv(int argc, char **argv, t_var *var)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		check_and_stack_element(argv[i], var);
		if (var->error)
			return ;
		i++;
	}
}
