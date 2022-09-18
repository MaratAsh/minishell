/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:06:43 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/09 14:29:22 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

typedef unsigned long	t_size;

static t_size	ft_strlen(char *s)
{
	t_size	sz;

	sz = 0;
	while (s[sz])
		sz++;
	return (sz);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen((char *) s1);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		return (str);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
