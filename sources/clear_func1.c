/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 17:08:56 by bbetz             #+#    #+#             */
/*   Updated: 2016/09/08 17:08:58 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_all(t_env *env)
{
	int		i;

	i = -1;
	while (env->av[++i])
		free(env->av[i]);
	free(env->av);
	i = -1;
	while (env->names->list[++i])
		free(env->names->list[i]);
	free(env->names->list);
	free(env->names);
	free(env->options->list);
	free(env->options);
	free(env);
}

void	free_data(t_files_ls **files)
{
	int i;

	i = 0;
	while ((*files) && (*files)->data && (*files)->data[i])
	{
		free((*files)->data[i]->stats);
		free((*files)->data[i]->user_name);
		free((*files)->data[i]->group_name);
		free((*files)->data[i]->path);
		free((*files)->data[i]->mtime);
		free((*files)->data[i]->file_name);
		free((*files)->data[i]);
		i++;
	}
}
