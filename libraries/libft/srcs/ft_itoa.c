/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:51:51 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 18:06:36 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_digits(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	ft_fill(char *str, int num)
{
	if (num < 0)
		*str = '0' - num % 10;
	else
		*str = '0' + num % 10;
	if (num / 10 != 0)
		ft_fill(str - 1, num / 10);
	else if (num < 0)
		*(str - 1) = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		d;

	d = ft_get_digits(n);
	str = (char *) malloc(sizeof(char) * (d + (n < 0) + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		if (n > -10)
		{
			str[0] = '-';
			str[1] = '0' - n;
		}
		else
			ft_fill(str + d, n);
		str[d + 1] = 0;
	}
	else
	{
		ft_fill(str + d - 1, n);
		str[d] = 0;
	}
	return (str);
}
