/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:34:57 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/23 14:34:59 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long int		ft_time_cmp(time_t time1, time_t time2)
{
	return (time1 - time2);
}

long int		ft_size_cmp(long long int size1, long long int size2)
{
	return (size1 - size2);
}
