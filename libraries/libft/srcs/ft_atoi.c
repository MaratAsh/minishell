/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:31:12 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/14 21:05:14 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_skip(char *str, int *flg)
{
	int	i;

	i = 0;
	*flg = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		i++;
		*flg = 1;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long long	res;
	long long	nxt_res;
	int			flg;

	str += ft_skip((char *) str, &flg);
	res = 0;
	nxt_res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (flg)
			nxt_res = res * 10 - (*str - '0');
		else
			nxt_res = res * 10 + (*str - '0');
		if (flg == 1 && nxt_res > 0)
			return (0);
		if (flg == 0 && nxt_res < 0)
			return (-1);
		res = nxt_res;
		str++;
	}
	return ((int) res);
}
