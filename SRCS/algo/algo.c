/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:22:17 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/10 13:22:41 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	algo(t_stack *stack_a, t_stack *stack_b)
{
	(void) stack_b;
	if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	return ;	
}