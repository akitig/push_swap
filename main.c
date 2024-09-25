/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:59:12 by akunimot          #+#    #+#             */
/*   Updated: 2024/09/25 18:59:15 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_var
{
	int	len;
	int	size;
}		t_var;

void	push_swap(t_var *var, int argc, char **argv)
{
	(void)var;
	(void)argc;
	(void)argv;
	printf("push_swap!\n");
}

t_var	*init_var(t_var *var)
{
	var->len = 0;
	var->size = 0;
	return (var);
}

int	main(int argc, char **argv)
{
	t_var *var;

	var = malloc(sizeof(t_var));
	if (var == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	var = init_var(var);
	push_swap(var, argc, argv);

	free(var);
	var = NULL;

	return (0);
}