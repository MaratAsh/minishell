/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:53:27 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/12 12:44:24 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long	t_size;

void	*ft_memmove(void *dst, const void *src, t_size len)
{
	char		*temp_dst;
	const char	*temp_src;

	temp_dst = (char *) dst;
	temp_src = (char *) src;
	if (dst == (void *) 0 && src == (void *) 0)
		return (dst);
	if (dst < src)
	{
		while (len--)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		temp_dst += len - 1;
		temp_src += len - 1;
		while (len--)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}
