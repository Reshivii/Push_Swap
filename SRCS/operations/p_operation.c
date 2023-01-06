/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:36:46 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/06 12:00:38 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_node **head_a, t_node **head_b)
{
	push(head_a, head_b);
	write(1, "pa\n", 3);
}

void	pb(t_node **head_a, t_node **head_b)
{
	push(head_b, head_a);
	write(1, "pb\n", 3);
}
