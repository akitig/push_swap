#include "libft/libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_stk
{
	int				num;
	struct s_stk	*nxt;
	struct s_stk	*prv;
}					t_stk;

typedef struct s_var
{
	int				error;
	int				len;
	int				size;
	t_stk			*a;
	t_stk			*b;
}					t_var;

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
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new_elem;
	new_elem->prv = tmp;
}

// スタックの先頭2つの要素を入れ替える（swap）
void	swap(t_stk **stack)
{
	t_stk	*first;
	t_stk	*second;

	if (*stack && (*stack)->nxt)
	{
		first = *stack;
		second = first->nxt;
		first->nxt = second->nxt;
		if (second->nxt)
			second->nxt->prv = first;
		second->nxt = first;
		second->prv = NULL;
		first->prv = second;
		*stack = second;
		printf("swap\n");
	}
}

// a と b のスタックを同時にスワップ
void	ss(t_stk **a, t_stk **b)
{
	swap(a);
	swap(b);
}

// b の先頭を a にプッシュ
void	pa(t_var *var)
{
	t_stk	*tmp;

	if (var->b)
	{
		tmp = var->b;
		var->b = var->b->nxt;
		if (var->b)
			var->b->prv = NULL;
		tmp->nxt = var->a;
		if (var->a)
			var->a->prv = tmp;
		var->a = tmp;
		printf("pa\n");
	}
}

// a の先頭を b にプッシュ
void	pb(t_var *var)
{
	t_stk	*tmp;

	if (var->a)
	{
		tmp = var->a;
		var->a = var->a->nxt;
		if (var->a)
			var->a->prv = NULL;
		tmp->nxt = var->b;
		if (var->b)
			var->b->prv = tmp;
		var->b = tmp;
		printf("pb\n");
	}
}

// a の要素を1つ回転（rotate）
void	ra(t_var *var)
{
	t_stk	*tmp;

	if (var->a && var->a->nxt)
	{
		tmp = var->a;
		var->a = var->a->nxt;
		var->a->prv = NULL;
		stack_add_back(&var->a, tmp);
		tmp->nxt = NULL;
		printf("ra\n");
	}
}

// b の要素を1つ回転（rotate）
void	rb(t_var *var)
{
	t_stk	*tmp;

	if (var->b && var->b->nxt)
	{
		tmp = var->b;
		var->b = var->b->nxt;
		var->b->prv = NULL;
		stack_add_back(&var->b, tmp);
		tmp->nxt = NULL;
		printf("rb\n");
	}
}

// a と b を同時に回転
void	rr(t_var *var)
{
	ra(var);
	rb(var);
}

// a の要素を1つ逆回転
void	rra(t_var *var)
{
	t_stk	*tmp;

	if (var->a && var->a->nxt)
	{
		tmp = var->a;
		while (tmp->nxt)
			tmp = tmp->nxt;
		if (tmp->prv)
			tmp->prv->nxt = NULL;
		tmp->nxt = var->a;
		tmp->prv = NULL;
		var->a->prv = tmp;
		var->a = tmp;
		printf("rra\n");
	}
}

// b の要素を1つ逆回転
void	rrb(t_var *var)
{
	t_stk	*tmp;

	if (var->b && var->b->nxt)
	{
		tmp = var->b;
		while (tmp->nxt)
			tmp = tmp->nxt;
		if (tmp->prv)
			tmp->prv->nxt = NULL;
		tmp->nxt = var->b;
		tmp->prv = NULL;
		var->b->prv = tmp;
		var->b = tmp;
		printf("rrb\n");
	}
}

// a と b を同時に逆回転
void	rrr(t_var *var)
{
	rra(var);
	rrb(var);
}

// ソートアルゴリズムのスタブ（簡単な例）
void	simple_sort(t_var *var)
{
	if (var->a && var->a->nxt && var->a->num > var->a->nxt->num)
		swap(&var->a);
}

// メインのプログラム
void	push_swap(t_var *var, int argc, char **argv)
{
	check_and_stack_argv(argc, argv, var);
	if (var->error)
	{
		free_stk(&var->a);
		print_error_message(var->error);
		exit(EXIT_FAILURE);
	}
	else
	{
		simple_sort(var); // ソートを実行
		printf("push_swap executed successfully!\n");
	}
}

int	main(int argc, char **argv)
{
	t_var *var;

	if (argc < 2)
	{
		printf("Error: No arguments provided.\n");
		return (EXIT_FAILURE);
	}

	var = init_var();
	push_swap(var, argc, argv);

	free_stk(&var->a);
	free(var);
	return (0);
}