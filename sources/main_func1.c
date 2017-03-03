/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 17:14:45 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/13 17:14:46 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_data(t_env *env)
{
	int i;

	i = -1;
	if ((ft_strfindchar(env->options->list, 'R')) != -1)
	{
		if (env->names->nb == 0)
			take_data_recursif(env, ".\0", ".\0");
		else
		{
			while (env->names->list[++i])
				take_data_recursif(env, NAME_GET_DATA, NAME_GET_DATA);
		}
	}
	else
	{
		if (env->names->nb == 0)
			take_data_no_recursif(env, ".\0");
		else
		{
			while (env->names->list[++i])
				take_data_no_recursif(env, env->names->list[i]);
		}
	}
}

void		sort_files(t_env *env, t_files_ls *files)
{
	if (ft_strfindchar(env->options->list, 'f') != -1)
		return ;
	else
	{
		sort_files_name(files);
		if ((ft_strfindchar(env->options->list, 'S')) != -1)
			sort_files_size(files);
		else if ((ft_strfindchar(env->options->list, 't')) != -1)
			sort_files_time_modif(files);
		if ((ft_strfindchar(env->options->list, 'r')) != -1)
			sort_files_reverse(files);
	}
}

static void	print_data2(t_env *env, t_files_ls *files)
{
	int i;

	i = -1;
	while (files->data[++i])
	{
		if ((ft_strfindchar(env->options->list, 'a') != -1) ||
				(ft_strfindchar(env->options->list, 'f') != -1) ||
				files->data[i]->file_name[0] != '.')
			print_name(env, files->data[i], 1);
	}
}

void		print_data(t_env *env, t_files_ls *files)
{
	int i;

	i = -1;
	env->first_write = 1;
	sort_files(env, files);
	if ((ft_strfindchar(env->options->list, 'l')) != -1)
	{
		if (files->total_blocks != 0)
			ft_putstr("total ");
		if (files->total_blocks != 0)
			ft_putnbrendl((int)files->total_blocks);
		while (files->data[++i])
		{
			if ((ft_strfindchar(env->options->list, 'a') != -1) ||
					(ft_strfindchar(env->options->list, 'f') != -1) ||
					files->data[i]->file_name[0] != '.')
				print_data_l(env, files->data[i]);
		}
	}
	else
		print_data2(env, files);
}
