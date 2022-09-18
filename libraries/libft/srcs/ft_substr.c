/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:58:34 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 18:03:39 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	fact_len;
	char	*str;

	if (!s)
		return (NULL);
	fact_len = ft_strlen((char *) s);
	if (fact_len < start)
		str = ft_calloc(1, 1);
	else
	{
		fact_len = fact_len - start + 1;
		if (fact_len > len)
			fact_len = len;
		str = (char *) malloc(sizeof(char) * (fact_len + 1));
		if (str == (char *) 0)
			return (NULL);
		ft_strlcpy(str, s + start, fact_len + 1);
	}
	return (str);
}
