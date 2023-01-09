/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:24:41 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/09 20:14:41 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_sorted(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->head;
	if (stack_a->head == NULL)
		return (1);
	while (current->next)
	{
		if(current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	algo(t_stack *stack_a, t_stack *stack_b)
{
	int	checked;
	// Pushing two first value
	if (stack_a->size > 3)
	{
		pb(&stack_a->head, &stack_b->head);
		pb(&stack_a->head, &stack_b->head);
		stack_a->size = stack_a->size - 2;
		stack_b->size = stack_b->size + 2;
	}

	// Searching for the minus value and push it in B
	while (stack_a->size != 3)
	{
		if (stack_a->head->value < stack_a->head->next->value)
		{
			pb(&stack_a->head, &stack_b->head);
			stack_a->size--;
			stack_b->size++;
		}
		else
			ra(&stack_a->head);
	}
	//Now sorting stack_a with 3 numbers
	checked = check_sorted(stack_a);
	while(!checked)
	{
		checked = check_sorted(stack_a);
		if (stack_a->head->value > stack_a->head->next->value)
			sa(stack_a->head);
		if (stack_a->head->next->value > stack_a->head->next->next->value)
		{
			rra(&stack_a->head);
			sa(stack_a->head);
		}
	}
	//Now sorting the rest !
	t_node	*current;
	t_node	*comp;
	int	highest;
	while (stack_b->size != 0)
	{
		if (stack_b->head->value < stack_b->head->next->value)
		{
			//printf("Swaping value: %d and %d\n", stack_b->head->value, stack_b->head->next->value);
			sb(stack_b->head);
		}
		current = stack_b->head;
		comp = stack_b->head->next;
		highest = 1;
		while (comp)
		{
			if (current->value < comp->value)
				highest = 0;
			comp = comp ->next;
		}
		if (highest)
		{
			//printf("Pushing value: %d\n", stack_b->head->value);
			pa(&stack_a->head, &stack_b->head);
			stack_b->size--;
			if (stack_a->head->value > stack_a->head->next->value)
			{
				sa(stack_a->head);
				pb(&stack_a->head, &stack_b->head);
				checked = check_sorted(stack_a);
				while(!checked)
				{
					checked = check_sorted(stack_a);
					if (stack_a->head->value > stack_a->head->next->value)
						sa(stack_a->head);
					if (stack_a->head->next->value > stack_a->head->next->next->value)
					{
						rra(&stack_a->head);
						sa(stack_a->head);
					}
				}
			}
		}
		else
			rrb(&stack_b->head);
	}
	pa(&stack_a->head, &stack_b->head);
	
	
}