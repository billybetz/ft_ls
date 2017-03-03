/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 11:05:03 by bbetz             #+#    #+#             */
/*   Updated: 2016/03/02 11:58:17 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putstr_n(char *s)
{
	write(1, s, ft_strlen(s));
}

void		ft_putcolor(char *s, char *color)
{
	ft_putchar('\0');
	ft_putstr_n(color);
	ft_putstr_n(s);
	ft_putstr_n(DEFAULT);
}
