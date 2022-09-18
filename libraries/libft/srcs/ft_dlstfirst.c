/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:39:10 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 19:41:25 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dlist	*ft_dlstfirst(t_dlist *dlst)
{
	while (dlst && dlst->prev)
		dlst = dlst->prev;
	return (dlst);
}
