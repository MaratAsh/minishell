/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:45:00 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/06 18:11:07 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long	t_size;

char	*ft_strnstr(const char *haystack, const char *needle, t_size len)
{
	t_size	i;
	t_size	j;

	i = 0;
	if (*needle == 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j]
				&& needle[j] != 0 && i + j < len)
				j++;
			if (needle[j] == 0)
				return ((char *) haystack + i);
		}
		i++;
	}
	return ((void *) 0);
}
