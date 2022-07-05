/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:21:06 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/06 16:39:02 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long	t_size;

void	*ft_memset(void *b, int c, t_size len)
{
	unsigned char	*temp;

	temp = (unsigned char *) b;
	while (len)
	{
		temp[len - 1] = (unsigned char) c;
		len--;
	}
	return (b);
}
