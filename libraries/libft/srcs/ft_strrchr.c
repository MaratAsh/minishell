/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:55:02 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 18:01:43 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	int		len;

	len = ft_strlen((char *) s);
	if (c == 0)
		return ((char *) s + len);
	ptr = (void *) 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			ptr = (char *) s + i;
		i++;
	}
	return (ptr);
}
