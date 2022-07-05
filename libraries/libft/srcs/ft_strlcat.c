/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:24:05 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 18:00:10 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	i;

	i = 0;
	size_dst = 0;
	while (dst[size_dst])
		size_dst++;
	if (size_dst >= size)
		return (ft_strlen((char *) src) + size);
	while (src[i] && size_dst + i + 1 < size)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	if (size_dst + i == size && size != 0)
		i--;
	dst[size_dst + i] = 0;
	return (size_dst + ft_strlen((char *) src));
}
