/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:44:12 by akunimot          #+#    #+#             */
/*   Updated: 2024/11/16 15:00:59 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// 初期化関数
t_var	*init_var(void)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (!var)
		exit(1);
	var->error = 0;
	var->a_size = 0;
	var->b_size = 0;
	var->a = NULL;
	var->b = NULL;
	return (var);
}

// Greedyアルゴリズムによるソート
void	greedy_sort(t_var *var)
{
	int	size;
	int	chunk_count;
	int	chunk_size;

	size = var->a_size;
	chunk_count = 3;
	chunk_size = size / chunk_count + 1;
	push_chunks_to_b(var, chunk_size);
	sort_small_stack(var);
	while (var->b_size > 0)
	{
		get_target_positions(var);
		calculate_cost(var);
		execute_cheapest_move(var);
	}
	update_positions(var);
	rotate_stack_a_to_min(var);
}

// メイン関数
int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc < 2)
		return (0);
	var = init_var();
	check_and_stack_argv(argc, argv, var);
	if (var->error)
	{
		free_stk(&var->a);
		print_error_message();
		exit(EXIT_FAILURE);
	}
	index_stack(var);
	if (!is_sorted(var->a))
	{
		if (var->a_size <= 5)
			sort_small_stack(var);
		else
			greedy_sort(var);
	}
	free_stk(&var->a);
	free_stk(&var->b);
	free(var);
	return (0);
}
