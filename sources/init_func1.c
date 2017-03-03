/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 16:43:53 by bbetz             #+#    #+#             */
/*   Updated: 2016/09/02 16:43:54 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_env(t_env *env)
{
	env->options = malloc(sizeof(t_options));
	env->names = malloc(sizeof(t_names));
	OPTIONS_GERE = ft_strdup("lRartSpfG1");
	NB_OPTIONS_GERE = ft_strlen(OPTIONS_GERE);
	env->options->list = malloc(sizeof(char) * NB_OPTIONS_GERE + 1);
	init_lens(env);
	env->err = 0;
	env->first_write = 0;
}

void	init_lens(t_env *env)
{
	env->nlink_lenmax = 0;
	env->size_lenmax = 0;
	env->user_name_lenmax = 0;
	env->group_name_lenmax = 0;
	env->file_name_lenmax = 0;
	env->major_lenmax = 0;
	env->minor_lenmax = 0;
	env->maj_min_lenmax = 0;
}

void	init_data(t_data **data)
{
	(*data)->is_device = 0;
}
