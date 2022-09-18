/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/04 18:09:42 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

static int	ft_get_digits(int num)
{
	if (num < 0)
		return (1 + ft_get_digits(-(num / 10)));
	else
	{
		if (num / 10 == 0)
			return (1);
		return (1 + ft_get_digits(num / 10));
	}
}

static int	ft_pow(int num, int power)
{
	int	res;

	res = 1;
	while (power--)
		res *= num;
	return (res);
}

static void	ft_next_num(int *n, int fd, int *curr_d, int *d)
{
	if (*n < 0)
		*n = - (*n % ft_pow(10, *curr_d - 1));
	else
		*n = *n % ft_pow(10, *curr_d - 1);
	*d = *curr_d;
	*curr_d = ft_get_digits(*n);
	while ((*n > 0 && *curr_d < *d - 1) || (*n == 0 && *curr_d < *d))
	{
		write(fd, "0", 1);
		(*d)--;
	}
}

void	ft_putnbr_fd_(int n, int fd, int curr_d, int d)
{
	char	c;

	while (curr_d > 1 || n > 0)
	{
		c = '0' + n / ft_pow(10, curr_d - 1);
		write(fd, &c, 1);
		ft_next_num(&n, fd, &curr_d, &d);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		d;
	int		curr_d;
	char	c;

	curr_d = ft_get_digits(n);
	d = curr_d;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n <= -10)
		{
			c = '0' - n / ft_pow(10, curr_d - 1);
			write(fd, &c, 1);
		}
		ft_next_num(&n, fd, &curr_d, &d);
	}
	ft_putnbr_fd_(n, fd, curr_d, d);
}
