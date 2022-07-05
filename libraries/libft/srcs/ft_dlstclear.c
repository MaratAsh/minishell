/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:59:33 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/12 17:07:23 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void*))
{
	t_dlist	*curr;
	t_dlist	*next;

	if (*dlst)
		return ;
	curr = *dlst;
	while (curr && curr->prev)
		curr = curr->prev;
	while (curr)
	{
		next = curr->next;
		if (del)
			(*del)(curr->content);
		free(curr);
		curr = next;
	}
	*dlst = NULL;
}
