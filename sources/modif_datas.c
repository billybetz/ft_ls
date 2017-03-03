/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_datas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:56:07 by bbetz             #+#    #+#             */
/*   Updated: 2016/09/08 16:56:09 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_modif_time(char *time)
{
	char	*str;
	int		i;
	int		y;

	i = 4;
	y = 0;
	str = malloc(sizeof(char) * 13);
	while (time && time[i] && i < 16)
	{
		str[y] = time[i];
		i++;
		y++;
	}
	str[y] = '\0';
	return (str);
}

char		*cut_last_file_to_path(char *path)
{
	int		i;
	int		y;
	char	*new_path;

	y = 0;
	i = ft_strlen(path) - 1;
	while (path[i] > 0 && path[i] != '/')
		i--;
	new_path = malloc(sizeof(char) * (i + 1));
	while (y < i)
	{
		new_path[y] = path[y];
		y++;
	}
	new_path[y] = '\0';
	return (new_path);
}
