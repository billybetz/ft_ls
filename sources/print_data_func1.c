/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 19:36:43 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/13 19:36:44 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_data_l3(t_env *env, t_data *data, int *i)
{
	ft_putnbr(data->stats->st_nlink);
	ft_putchar(' ');
	ft_putstr(data->user_name);
	while (++(*i) < (2 + (env->user_name_lenmax - data->user_name_len)))
		ft_putchar(' ');
	*i = -1;
	ft_putstr(data->group_name);
}

static void	print_data_l2(t_env *env, t_data *data, int *i)
{
	*i = -1;
	env->err = 1;
	ft_putchar(data->type);
	ft_putchar((data->stats->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((data->stats->st_mode & S_IWUSR) ? 'w' : '-');
	if (data->stats->st_mode & S_ISUID)
		ft_putchar((data->stats->st_mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((data->stats->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((data->stats->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((data->stats->st_mode & S_IWGRP) ? 'w' : '-');
	if (data->stats->st_mode & S_ISGID)
		ft_putchar((data->stats->st_mode & S_IXGRP) ? 's' : 'l');
	else
		ft_putchar((data->stats->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((data->stats->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((data->stats->st_mode & S_IWOTH) ? 'w' : '-');
	if (data->stats->st_mode & S_ISVTX)
		ft_putchar((data->stats->st_mode & S_IXUSR) ? 't' : 'T');
	else
		ft_putchar((data->stats->st_mode & S_IXOTH) ? 'x' : '-');
	while (++(*i) < (1 + (env->nlink_lenmax - data->nlink_len)))
		ft_putchar(' ');
	*i = -1;
	print_data_l3(env, data, i);
}

static void	print_data_l_maj_min(t_env *env, t_data *data, int *i)
{
	if ((env->maj_min_lenmax) != 0)
	{
		while (++(*i) < (env->group_name_lenmax - data->group_name_len) +
				(env->size_lenmax - data->size_len) + env->maj_min_lenmax - 1)
			ft_putchar(' ');
	}
	else
	{
		while (++(*i) < 2 + (env->group_name_lenmax - data->group_name_len) +
				(env->size_lenmax - data->size_len))
			ft_putchar(' ');
	}
	ft_putstr(data->size);
}

void		print_data_l(t_env *env, t_data *data)
{
	int i;

	print_data_l2(env, data, &i);
	if (data->is_device == 1)
	{
		while (++i < (2 + (env->group_name_lenmax - data->group_name_len) +
				(env->major_lenmax - data->major_len)))
			ft_putchar(' ');
		i = -1;
		ft_putstr(data->major);
		while (++i < (1 + env->minor_lenmax - data->minor_len))
			ft_putchar(' ');
		ft_putstr(data->minor);
	}
	else
		print_data_l_maj_min(env, data, &i);
	ft_putchar(' ');
	ft_putstr(data->mtime);
	ft_putchar(' ');
	print_name(env, data, 2);
}
