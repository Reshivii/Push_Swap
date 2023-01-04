/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:31:20 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/03 15:02:09 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;

	stack_a = stack_init();
	i = 1;
	while (i < ac)
	{
		stack_push(stack_a, ft_atoi(av[i]));
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
