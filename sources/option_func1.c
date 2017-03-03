/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 16:51:09 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/13 16:51:11 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		count_options(t_env *env)
{
	int i;
	int nb_options;

	nb_options = 0;
	i = 1;
	while (i < env->ac)
	{
		if (env->av[i][0] == '-' && env->av[i][1])
			nb_options++;
		else
			return (nb_options);
		i++;
	}
	return (nb_options);
}

int		option_exist(t_env *env, char c)
{
	int i;

	i = 0;
	while (env->options->list[i])
	{
		if (env->options->list[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	add_option(t_env *env, char c)
{
	int i;

	i = 0;
	while (env->options->list[i])
		i++;
	env->options->list[i] = c;
	env->options->list[++i] = '\0';
}

void	take_options(t_env *env)
{
	int i;
	int y;

	i = 1;
	y = 1;
	while (i < env->ac)
	{
		if (env->av[i][0] == '-' && env->av[i][1])
		{
			while (env->av[i][y])
			{
				if ((ft_strfindchar(OPTIONS_GERE, env->av[i][y])) == -1)
					exit_wrong_option(env, env->av[i][y]);
				if (!option_exist(env, env->av[i][y]))
					add_option(env, env->av[i][y]);
				y++;
			}
		}
		else
			break ;
		i++;
		y = 1;
	}
	env->options->nb = ft_strlen(env->options->list);
}
