/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:28:28 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 18:03:01 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count < 1 || size < 1)
	{
		count = 1;
		size = 1;
	}
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * count);
	return (arr);
}
