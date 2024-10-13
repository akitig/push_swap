/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:59:12 by akunimot          #+#    #+#             */
/*   Updated: 2024/10/04 17:15:47 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_var
{
	int	len;
	int	size;
}		t_var;

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] || s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

bool	ft_ispos_char(char *numchar)
{
	int	i;

	i = 0;
	if (numchar[0] == '\0')
		return (false);
	if (numchar[0] == '+' || numchar[0] == '-')
		return (false);
	while (numchar[i])
	{
		if (!ft_isdigit(numchar[i]))
			return (false);
		i++;
	}
	return (true);
}

void	free_arg(char **arg)
{
	if (*arg)
		free(*arg);
	*arg = NULL;
}

bool	isduplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
	{
		printf("not argc");
		return (1);
	}
	while (i < argc)
	{
		if (!ft_ispos_char(argv[i]))
		{
			printf("is not positive\n");
			return (1);
		}
		i++;
	}
	if (isduplicate(argc, argv) == true)
	{
		printf("is duplicate argvs\n");
		return (1);
	}
	return (0);
}

void	input_argv_to_var(t_var *var, char **argv)
{
	(void)var;
	(void)argv;
}

void	push_swap(t_var *var, int argc, char **argv)
{
	int	error;
	int	cnt;

	error = 0;
	cnt = 1;
	error = check_argv(argc, argv);
	while (!error && cnt < argc)
	{
		input_argv_to_var(var, argv);
		cnt++;
	}
	if (error)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("push_swap!\n");
		exit(EXIT_SUCCESS);
	}
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