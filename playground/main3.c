#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// 関数プロトタイプ
void				print_error_message(void);
void				free_stk(t_stk **stk);
void				stack_add_back(t_stk **stack, t_stk *new_elem);
int					isduplicate(t_var *var, int num);
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
int					stack_size(t_stk *stack);
void				get_target_positions(t_var *var);
void				calculate_cost(t_var *var);
void				execute_cheapest_move(t_var *var);
void				update_positions(t_var *var);

// エラーメッセージを表示する関数
void	print_error_message(void)
{
	printf("Error\n");
}

// スタックを解放する関数
void	free_stk(t_stk **stk)
{
	t_stk	*tmp;

	while (*stk)
	{
		tmp = (*stk)->next;
		free(*stk);
		*stk = tmp;
	}
}

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
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem;
}

// 重複チェック
int	isduplicate(t_var *var, int num)
{
	t_stk	*tmp;

	tmp = var->a;
	while (tmp)
	{
		if (tmp->num == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// 引数をチェックし、スタックに積む関数
void	check_and_stack_argv(int argc, char **argv, t_var *var)
{
	long long	num;
	t_stk		*new_elem;
	char		*endptr;

	for (int i = 1; i < argc; i++)
	{
		num = strtoll(argv[i], &endptr, 10);
		if (*endptr != '\0' || num > INT_MAX || num < INT_MIN)
		{
			var->error = 1;
			return ;
		}
		if (isduplicate(var, (int)num))
		{
			var->error = 1;
			return ;
		}
		new_elem = (t_stk *)malloc(sizeof(t_stk));
		if (!new_elem)
		{
			var->error = 1;
			return ;
		}
		new_elem->num = (int)num;
		new_elem->index = -1;
		new_elem->pos = -1;
		new_elem->target_pos = -1;
		new_elem->cost_a = -1;
		new_elem->cost_b = -1;
		new_elem->next = NULL;
		stack_add_back(&var->a, new_elem);
		var->a_size++;
	}
}

// 初期化関数
t_var	*init_var(void)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		exit(1);
	var->error = 0;
	var->a_size = 0;
	var->b_size = 0;
	var->a = NULL;
	var->b = NULL;
	return (var);
}

// スワップ操作 (sa)
void	sa(t_var *var)
{
	t_stk	*first;
	t_stk	*second;

	if (!var->a || !var->a->next)
		return ;
	first = var->a;
	second = var->a->next;
	first->next = second->next;
	second->next = first;
	var->a = second;
	printf("sa\n");
}

// スワップ操作 (sb)
void	sb(t_var *var)
{
	t_stk	*first;
	t_stk	*second;

	if (!var->b || !var->b->next)
		return ;
	first = var->b;
	second = var->b->next;
	first->next = second->next;
	second->next = first;
	var->b = second;
	printf("sb\n");
}

// スワップ操作 (ss)
void	ss(t_var *var)
{
	sa(var);
	sb(var);
}

// プッシュ操作 (pa)
void	pa(t_var *var)
{
	t_stk	*tmp;

	if (!var->b)
		return ;
	tmp = var->b;
	var->b = var->b->next;
	tmp->next = var->a;
	var->a = tmp;
	var->a_size++;
	var->b_size--;
	printf("pa\n");
}

// プッシュ操作 (pb)
void	pb(t_var *var)
{
	t_stk	*tmp;

	if (!var->a)
		return ;
	tmp = var->a;
	var->a = var->a->next;
	tmp->next = var->b;
	var->b = tmp;
	var->a_size--;
	var->b_size++;
	printf("pb\n");
}

// ローテート操作 (ra)
void	ra(t_var *var)
{
	t_stk	*tmp;
	t_stk	*last;

	if (!var->a || !var->a->next)
		return ;
	tmp = var->a;
	var->a = var->a->next;
	tmp->next = NULL;
	last = var->a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	printf("ra\n");
}

// ローテート操作 (rb)
void	rb(t_var *var)
{
	t_stk	*tmp;
	t_stk	*last;

	if (!var->b || !var->b->next)
		return ;
	tmp = var->b;
	var->b = var->b->next;
	tmp->next = NULL;
	last = var->b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	printf("rb\n");
}

// ローテート操作 (rr)
void	rr(t_var *var)
{
	ra(var);
	rb(var);
}

// リバースローテート操作 (rra)
void	rra(t_var *var)
{
	t_stk	*prev;
	t_stk	*curr;

	if (!var->a || !var->a->next)
		return ;
	prev = NULL;
	curr = var->a;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = var->a;
	var->a = curr;
	printf("rra\n");
}

// リバースローテート操作 (rrb)
void	rrb(t_var *var)
{
	t_stk	*prev;
	t_stk	*curr;

	if (!var->b || !var->b->next)
		return ;
	prev = NULL;
	curr = var->b;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = var->b;
	var->b = curr;
	printf("rrb\n");
}

// リバースローテート操作 (rrr)
void	rrr(t_var *var)
{
	rra(var);
	rrb(var);
}

// スタックがソートされているか確認する関数
int	is_sorted(t_stk *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// スタックのサイズを取得する関数
int	stack_size(t_stk *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

// スタックをインデックス化する関数
void	index_stack(t_var *var)
{
	int		*arr;
	int		size;
	t_stk	*tmp;
	int		temp;

	size = var->a_size;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	tmp = var->a;
	for (int i = 0; i < size; i++)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
	}
	// 配列をソート
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	// スタック内の数値をインデックスに置き換える
	tmp = var->a;
	while (tmp)
	{
		for (int i = 0; i < size; i++)
		{
			if (tmp->num == arr[i])
			{
				tmp->index = i;
				break ;
			}
		}
		tmp = tmp->next;
	}
	free(arr);
}

// 小さいスタックをソートする関数
void	sort_small_stack(t_var *var)
{
	int		a;
	int		b;
	int		c;
	t_stk	*tmp;
	int		min_index;
	int		pos;
	int		min_pos;

	if (var->a_size == 2)
	{
		if (var->a->num > var->a->next->num)
			sa(var);
	}
	else if (var->a_size == 3)
	{
		a = var->a->index;
		b = var->a->next->index;
		c = var->a->next->next->index;
		if (a > b && b < c && a < c)
			sa(var);
		else if (a > b && b > c)
		{
			sa(var);
			rra(var);
		}
		else if (a > b && b < c && a > c)
			ra(var);
		else if (a < b && b > c && a < c)
		{
			sa(var);
			ra(var);
		}
		else if (a < b && b > c && a > c)
			rra(var);
	}
	else if (var->a_size <= 5)
	{
		while (var->a_size > 3)
		{
			tmp = var->a;
			min_index = tmp->index;
			pos = 0;
			min_pos = 0;
			while (tmp)
			{
				if (tmp->index < min_index)
				{
					min_index = tmp->index;
					min_pos = pos;
				}
				tmp = tmp->next;
				pos++;
			}
			if (min_pos == 0)
				pb(var);
			else if (min_pos <= var->a_size / 2)
			{
				for (int i = 0; i < min_pos; i++)
					ra(var);
				pb(var);
			}
			else
			{
				for (int i = 0; i < var->a_size - min_pos; i++)
					rra(var);
				pb(var);
			}
		}
		sort_small_stack(var);
		while (var->b_size > 0)
			pa(var);
	}
}

// 各要素の位置を更新する関数
void	update_positions(t_var *var)
{
	t_stk	*tmp;
	int		pos;

	pos = 0;
	tmp = var->a;
	while (tmp)
	{
		tmp->pos = pos;
		tmp = tmp->next;
		pos++;
	}
	pos = 0;
	tmp = var->b;
	while (tmp)
	{
		tmp->pos = pos;
		tmp = tmp->next;
		pos++;
	}
}

// スタックA内でのターゲット位置を見つける関数
int	get_target(t_var *var, int index_b)
{
	t_stk	*tmp_a;
	int		target_index;
	int		target_pos;

	target_index = INT_MAX;
	target_pos = -1;
	tmp_a = var->a;
	while (tmp_a)
	{
		if (tmp_a->index > index_b && tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_pos == -1)
	{
		tmp_a = var->a;
		while (tmp_a)
		{
			if (tmp_a->index < target_index)
			{
				target_index = tmp_a->index;
				target_pos = tmp_a->pos;
			}
			tmp_a = tmp_a->next;
		}
	}
	return (target_pos);
}

// 各要素のターゲット位置を設定する関数
void	get_target_positions(t_var *var)
{
	t_stk	*tmp_b;

	tmp_b = var->b;
	update_positions(var);
	while (tmp_b)
	{
		tmp_b->target_pos = get_target(var, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}

// 各要素の操作コストを計算する関数
void	calculate_cost(t_var *var)
{
	t_stk	*tmp_b;
	int		size_a;
	int		size_b;

	size_a = var->a_size;
	size_b = var->b_size;
	tmp_b = var->b;
	while (tmp_b)
	{
		if (tmp_b->pos < size_b / 2)
			tmp_b->cost_b = tmp_b->pos;
		else
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		if (tmp_b->target_pos < size_a / 2)
			tmp_b->cost_a = tmp_b->target_pos;
		else
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

// 最小の操作コストを持つ要素を見つけ、移動を実行する関数
void	execute_cheapest_move(t_var *var)
{
	t_stk	*tmp_b;
	int		cheapest;
	int		total_cost;
	int		cost_a;
	int		cost_b;

	cheapest = INT_MAX;
	cost_a = 0;
	cost_b = 0;
	tmp_b = var->b;
	while (tmp_b)
	{
		total_cost = abs(tmp_b->cost_a) + abs(tmp_b->cost_b);
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			cost_a = tmp_b->cost_a;
			cost_b = tmp_b->cost_b;
		}
		tmp_b = tmp_b->next;
	}
	// 操作を実行
	while (cost_a > 0 && cost_b > 0)
	{
		rr(var);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(var);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(var);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(var);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(var);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(var);
		cost_b++;
	}
	pa(var);
}

// Greedyアルゴリズムによるソート
void	greedy_sort(t_var *var)
{
	int		median;
	int		pushed;
	int		size;
	int		min_pos;
	t_stk	*tmp;
	int		min_index;

	median = var->a_size / 2;
	pushed = 0;
	size = var->a_size;
	// スタックAの半分をスタックBにプッシュ
	while (size-- && pushed < var->a_size / 2)
	{
		if (var->a->index <= median)
		{
			pb(var);
			pushed++;
		}
		else
			ra(var);
	}
	// スタックAに3つ残るまでプッシュ
	while (var->a_size > 3)
		pb(var);
	sort_small_stack(var);
	while (var->b_size > 0)
	{
		get_target_positions(var);
		calculate_cost(var);
		execute_cheapest_move(var);
	}
	// 最小値が先頭に来るようにスタックAを回転
	update_positions(var);
	min_pos = 0;
	tmp = var->a;
	min_index = INT_MAX;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (min_pos <= var->a_size / 2)
	{
		while (min_pos--)
			ra(var);
	}
	else
	{
		min_pos = var->a_size - min_pos;
		while (min_pos--)
			rra(var);
	}
}

// メイン関数
int	main(int argc, char **argv)
{
	t_var *var;

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
	free(var);
	return (0);
}