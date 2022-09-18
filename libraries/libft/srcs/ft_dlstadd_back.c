/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:44:47 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 19:41:07 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new_elem)
{
	t_dlist	*iter;

	iter = *dlst;
	while (iter && iter->next)
	{
		iter = iter->next;
	}
	new_elem->prev = iter;
	iter->next = new_elem;
}
