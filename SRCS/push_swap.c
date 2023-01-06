/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:31:20 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/06 11:45:18 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_stack(t_stack *stack_a, int ato)
{
	t_node	*current;

	current = stack_a->head;
	while (current && current->value != ato)
		current = current->next;
	if (current)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	valid_stack(t_stack *stack_a, char **list, int i)
{
	int	check;
	int	ato;

	check = 0;
	while (list[i])
	{
		ato = ft_atoi(list[i], &check);
		check_stack(stack_a, ato);
		stack_push(stack_a, ato);
		if (check)
		{
			write (2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted;
	int		i;
	int		check;

	stack_a = stack_init();
	stack_b = stack_init();
	i = 1;
	check = 0;
	if (ac == 2)
	{
		splitted = ft_split(av[1], ' ');
		valid_stack(stack_a, splitted, 0);
	}
	else
		valid_stack(stack_a, av, 1);
	// system("leaks push_swap");
	return (0);
}
