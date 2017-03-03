/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:13:25 by bbetz             #+#    #+#             */
/*   Updated: 2016/01/16 18:56:35 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putchar(char c)
{
	static int	i = -1;
	static char str[4096];

	if (c == '\0')
	{
		write(1, str, ft_strlen(str));
		ft_strclr(str);
		i = -1;
		str[0] = c;
	}
	else
	{
		if (++i < 4096)
		{
			str[i] = c;
			str[i + 1] = '\0';
		}
		else
		{
			write(1, str, ft_strlen(str));
			ft_strclr(str);
			i = -1;
		}
	}
}
