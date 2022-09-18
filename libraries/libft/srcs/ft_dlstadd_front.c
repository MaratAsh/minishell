/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:19:57 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 19:41:11 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new_elem)
{
	new_elem->next = *lst;
	new_elem->next->prev = new_elem;
	*lst = new_elem;
}
