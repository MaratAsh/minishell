/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:38:54 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/12 09:50:08 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long	t_size;

int	ft_memcmp(const void *s1, const void *s2, t_size n)
{
	t_size			i;
	unsigned char	*s1_;
	unsigned char	*s2_;

	s1_ = (unsigned char *) s1;
	s2_ = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	if (s1_ == 0 && s2_ == 0)
		return (0);
	while (n--)
	{
		if (s1_[i] != s2_[i])
			return (s1_[i] - s2_[i]);
		++i;
	}
	return (*s1_ - *s2_);
}
