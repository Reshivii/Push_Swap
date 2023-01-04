/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:55:03 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/03 15:03:26 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_push(t_stack *stack, int value)
{
	t_node *new;

	new = (t_node*) malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->next = stack->head;
	stack->head = new;
	stack->size++;
	return (1);
}