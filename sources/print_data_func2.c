/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_func2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 19:32:10 by bbetz             #+#    #+#             */
/*   Updated: 2016/09/08 19:32:12 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_name_color(t_data *data, int i)
{
	if (data->type == 'd')
		ft_putcolor(data->file_name, CYAN);
	else if (data->type == '-' && (data->stats->st_mode & S_IXOTH))
		ft_putcolor(data->file_name, RED);
	else if (data->type == 'c')
		ft_putcolor(data->file_name, YELLOW);
	else if (data->type == 'b')
		ft_putcolor(data->file_name, BLUE);
	else if (data->type == '-')
		ft_putcolor(data->file_name, WHITE);
	else if (data->type == 'f')
		ft_putcolor(data->file_name, BROWN);
	else if (data->type == 'l' && i == 2)
	{
		ft_putcolor(data->file_name, PURPLE);
		ft_putstr(" -> ");
		ft_putstr(data->link_name);
	}
	else if (data->type == 'l' && i == 1)
		ft_putcolor(data->file_name, PURPLE);
	else if (data->type == 's')
		ft_putcolor(data->file_name, GREEN);
}

void		print_name(t_env *env, t_data *data, int i)
{
	if (i == 1)
		env->err = 1;
	if (ft_strfindchar(env->options->list, 'G') != -1)
		print_name_color(data, i);
	else
		ft_putstr(data->file_name);
	if (ft_strfindchar(env->options->list, 'p') != -1 && data->type == 'd')
		ft_putchar('/');
	ft_putchar('\n');
}
