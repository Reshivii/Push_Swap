/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:31:20 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/05 16:37:00 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(t_stack *stack_a, int ato)
{
	t_node	*current;
	
	current = stack_a->head;
	while(current && current->value != ato)
		current = current->next;
	if (current)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	return (0);	
}


int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		check;

	stack_a = stack_init();
	i = 1;
	check = 0;
	while (i < ac)
	{
		int ato = ft_atoi(av[i], &check);
		check_stack(stack_a, ato);
		stack_push(stack_a, ato);
		if (check)
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}

	t_node *current;

	current = stack_a->head;
	while (current)
	{
	    printf("%d ", current->value);
	    current = current->next;
	}

	return (0);
}
