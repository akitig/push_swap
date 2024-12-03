/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:26:34 by akunimot          #+#    #+#             */
/*   Updated: 2024/12/03 12:27:05 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_stk
{
	int				num;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stk	*next;
}					t_stk;

typedef struct s_var
{
	int				error;
	int				a_size;
	int				b_size;
	t_stk			*a;
	t_stk			*b;
}					t_var;

int					ft_abs(int n);
int					ft_min(int a, int b);
int					update_result(long long *result, int digit, int base);
long long			convert_digits(const char *str, char **endptr, int base,
						int sign);
long long			ft_strtoll(const char *str, char **endptr, int base);
void				swap(t_stk **stack);
void				print_error_message(void);
void				free_stk(t_stk **stk);
void				stack_add_back(t_stk **stack, t_stk *new_elem);
int					is_duplicate(t_stk *stack, int num);
void				check_and_stack_argv(int argc, char **argv, t_var *var);
t_var				*init_var(void);
void				sa(t_var *var);
void				sb(t_var *var);
void				ss(t_var *var);
void				pa(t_var *var);
void				pb(t_var *var);
void				ra(t_var *var);
void				rb(t_var *var);
void				rr(t_var *var);
void				rra(t_var *var);
void				rrb(t_var *var);
void				rrr(t_var *var);
void				sort_small_stack(t_var *var);
void				greedy_sort(t_var *var);
int					is_sorted(t_stk *stack);
void				index_stack(t_var *var);
void				get_target_positions(t_var *var);
void				calculate_cost(t_var *var);
void				execute_cheapest_move(t_var *var);
void				update_positions(t_var *var);
void				find_cheapest_move(t_var *var, int *cost_a, int *cost_b);
void				execute_moves(t_var *var, int cost_a, int cost_b);
void				move_both_stacks(t_var *var, int *cost_a, int *cost_b);
void				move_stack_a(t_var *var, int cost_a);
void				move_stack_b(t_var *var, int cost_b);
int					get_target(t_var *var, int index_b);
int					find_closest_higher_index(t_stk *stack, int index_b,
						int *target_index, int *target_pos);
void				find_smallest_index(t_stk *stack, int *target_index,
						int *target_pos);
void				push_chunks_to_b(t_var *var, int chunk_size);
void				rotate_stack_a_to_min(t_var *var);
int					*create_array_from_stack(t_var *var, int size);
void				bubble_sort(int *arr, int size);
void				assign_indices_to_stack(t_var *var, int *arr, int size);