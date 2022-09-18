/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:10:52 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/11 14:47:56 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_dlstmap_(t_dlist *dlst, void *(*f)(void *),
			void (*del)(void *), t_dlist *start)
{
	t_dlist	*curr;

	curr = start;
	if (dlst)
		dlst = dlst->next;
	while (dlst)
	{
		if (curr)
		{
			curr->next = ft_dlstnew(f(dlst->content));
			if (del)
				(*del)(dlst->content);
		}
		else
			break ;
		if (curr && curr->next)
		{
			curr->next->prev = curr;
			curr = curr->next;
		}
		dlst = dlst->next;
	}
}

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*start;

	start = NULL;
	if (dlst)
	{
		start = ft_dlstnew(f(dlst->content));
		if (del)
			(*del)(dlst->content);
		dlst = dlst->next;
	}
	ft_dlstmap_(dlst, f, del, start);
	return (start);
}
