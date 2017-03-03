/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 17:02:47 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/13 17:03:12 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_names_validity(t_env *env)
{
	DIR		*odir_ret;
	int		o_ret;
	int		i;

	i = 0;
	if (env->names->nb > 1)
		env->err = 1;
	while (env->names->list[i])
	{
		if ((odir_ret = opendir(env->names->list[i])))
			closedir(odir_ret);
		else if ((o_ret = open(env->names->list[i], O_RDONLY)) != -1)
			close(o_ret);
		else
		{
			if (errno == 13)
				ft_errmess_noright(env->names->list[i]);
			else
				ft_errmess_wrong_name(env->names->list[i]);
			take_off_name_from_list(env, i);
			i--;
		}
		i++;
	}
}

void	take_off_name_from_list(t_env *env, int i)
{
	while (env->names->list[i + 1])
	{
		env->names->list[i] = env->names->list[i + 1];
		i++;
	}
	env->names->list[i] = NULL;
}

void	take_names(t_env *env)
{
	int i;
	int y;

	y = 0;
	i = 1;
	while (i < env->ac)
	{
		if (env->av[i][0] == '-' && env->av[i][1])
			i++;
		else
			break ;
	}
	while (i < env->ac)
	{
		env->names->list[y] = ft_strdup(env->av[i]);
		i++;
		y++;
	}
	env->names->list[y] = NULL;
}

int		count_names(t_env *env)
{
	int i;

	i = 1;
	while (i < env->ac)
	{
		if (env->av[i][0] == '-' && env->av[i][1])
			i++;
		else
			break ;
	}
	env->names->nb = (env->ac - i);
	return ((env->ac) - i);
}
