/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:45:20 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/06 16:22:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long	t_size;

void	*ft_memcpy(void *dst, const void *src, t_size n)
{
	t_size	i;
	char	*temp_dst;

	if (dst == (void *) 0 && src == (void *) 0)
		return (dst);
	temp_dst = (char *) dst;
	i = 0;
	while (i < n)
	{
		temp_dst[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}
