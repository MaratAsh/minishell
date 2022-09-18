/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:40:01 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 19:41:03 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstadd_after(t_dlist *dlst, t_dlist *new_elem)
{
	t_dlist	*next_elem;

	if (!dlst || !new_elem)
		return ;
	next_elem = dlst->next;
	new_elem->next = next_elem;
	new_elem->prev = dlst;
	dlst->next = new_elem;
	if (next_elem)
		next_elem->prev = new_elem;
}
