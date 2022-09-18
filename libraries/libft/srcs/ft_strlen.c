/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:04 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/06 12:05:08 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long	t_size;

t_size	ft_strlen(char *s)
{
	t_size	sz;

	if (s == (void *) 0)
		return (0);
	sz = 0;
	while (s[sz])
		sz++;
	return (sz);
}
