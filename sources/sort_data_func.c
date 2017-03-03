/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 20:18:11 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/13 20:18:13 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_files_name(t_files_ls *files)
{
	int		y;
	t_data	*tmp;

	y = 0;
	while (files && files->data && files->data[y] && files->data[y + 1])
	{
		if (ft_strcmp(NAME_SORT_DATA, files->data[y + 1]->file_name) > 0)
		{
			tmp = files->data[y];
			files->data[y] = files->data[y + 1];
			files->data[y + 1] = tmp;
			if (y > 0)
				y--;
		}
		else
			y++;
	}
}

void		sort_files_time_modif(t_files_ls *files)
{
	int		y;
	t_data	*tmp;

	y = 0;
	while (files->data && files->data[y] && files->data[y + 1])
	{
		if (ft_time_cmp(files->data[y]->time, files->data[y + 1]->time) < 0)
		{
			tmp = files->data[y];
			files->data[y] = files->data[y + 1];
			files->data[y + 1] = tmp;
			if (y > 0)
				y--;
		}
		else
			y++;
	}
}

void		sort_files_reverse(t_files_ls *files)
{
	int		y;
	int		end;
	t_data	*tmp;

	y = 0;
	end = files->nb_files - 1;
	while (y < end)
	{
		tmp = files->data[y];
		files->data[y] = files->data[end];
		files->data[end] = tmp;
		y++;
		end--;
	}
}

void		sort_files_size(t_files_ls *files)
{
	int		y;
	t_data	*tmp;

	y = 0;
	while (files->data && files->data[y] && files->data[y + 1])
	{
		if (ft_size_cmp(files->data[y]->size_int,
				files->data[y + 1]->size_int) < 0)
		{
			tmp = files->data[y];
			files->data[y] = files->data[y + 1];
			files->data[y + 1] = tmp;
			if (y > 0)
				y--;
		}
		else
			y++;
	}
}

void		sort_names(t_env *env)
{
	int		y;
	char	*tmp;

	y = 0;
	while (env->names->list[y + 1])
	{
		if (ft_strcmp(env->names->list[y], env->names->list[y + 1]) > 0)
		{
			tmp = env->names->list[y];
			env->names->list[y] = env->names->list[y + 1];
			env->names->list[y + 1] = tmp;
			y = 0;
		}
		else
			y++;
	}
}
