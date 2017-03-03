/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 17:07:35 by bbetz             #+#    #+#             */
/*   Updated: 2016/09/08 17:07:36 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_major(dev_t dev)
{
	char	*ret;
	int		octet_poid_fort;

	octet_poid_fort = dev >> 24 & 0xff;
	ret = ft_itoa(octet_poid_fort);
	ret = ft_strjoin(ret, ",");
	return (ret);
}

char	*ft_get_minor(dev_t dev)
{
	char	*ret;
	int		octet_poid_faible;

	octet_poid_faible = dev & 0xff;
	ret = ft_itoa(octet_poid_faible);
	return (ret);
}

char	*ft_get_name_to_path(const char *path)
{
	int		i;
	int		y;
	int		size;
	char	*name;

	y = 0;
	i = ft_strlen(path);
	size = i;
	while (i > 0 && path[i] != '/')
		i--;
	name = malloc(sizeof(char) * (size - i + 1));
	while (path[i])
	{
		name[y] = path[i];
		i++;
		y++;
	}
	name[y] = '\0';
	return (name);
}

char	ft_get_type(t_data *data)
{
	if (S_ISDIR(data->stats->st_mode))
		return ('d');
	else if (S_ISCHR(data->stats->st_mode))
		return ('c');
	else if (S_ISBLK(data->stats->st_mode))
		return ('b');
	else if (S_ISFIFO(data->stats->st_mode))
		return ('f');
	else if (S_ISLNK(data->stats->st_mode))
		return ('l');
	else if (S_ISSOCK(data->stats->st_mode))
		return ('s');
	else if (S_ISREG(data->stats->st_mode))
		return ('-');
	return ('a');
}

void	get_args(t_env *env, char **av, int ac)
{
	int		i;

	i = -1;
	env->ac = ac;
	env->av = malloc(sizeof(char*) * (ac + 1));
	while (++i < ac)
		env->av[i] = ft_strdup(av[i]);
	env->options->list = malloc(sizeof(char*) * (count_options(env) + 1));
	env->options->list[0] = '\0';
	env->names->list = malloc(sizeof(char*) * (count_names(env) + 1));
	env->names->list[0] = NULL;
	take_options(env);
	take_names(env);
	check_names_validity(env);
	if (env->names->nb > 1)
		sort_names(env);
}
