/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_func3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:58:21 by bbetz             #+#    #+#             */
/*   Updated: 2016/09/08 18:58:22 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_file_data_maj_min(t_env *env, t_data **data)
{
	(*data)->is_device = 1;
	(*data)->major = ft_get_major((*data)->stats->st_rdev);
	(*data)->minor = ft_get_minor((*data)->stats->st_rdev);
	(*data)->major_len = ft_strlen((*data)->major);
	(*data)->minor_len = ft_strlen((*data)->minor);
	if ((*data)->major_len > env->major_lenmax)
		env->major_lenmax = (*data)->major_len;
	if ((*data)->minor_len > env->minor_lenmax)
		env->minor_lenmax = (*data)->minor_len;
	(*data)->maj_min_len = (*data)->major_len + env->minor_lenmax;
	if ((*data)->maj_min_len > env->maj_min_lenmax)
		env->maj_min_lenmax = (*data)->maj_min_len;
}

static void	get_file_data2(t_env *env, t_data **data, char *name)
{
	int i;

	i = 0;
	if (S_ISCHR((*data)->stats->st_mode) || S_ISBLK((*data)->stats->st_mode))
		get_file_data_maj_min(env, data);
	else
	{
		(*data)->is_device = 0;
		(*data)->size_int = (*data)->stats->st_size;
		(*data)->size = ft_itoa((int)(*data)->size_int);
		(*data)->size_len = ft_strlen((*data)->size);
		if ((*data)->size_len > env->size_lenmax)
			env->size_lenmax = (*data)->size_len;
	}
	(*data)->file_name = ft_strdup(name);
	(*data)->file_name_len = ft_strlen(name);
	if ((*data)->file_name_len > env->file_name_lenmax)
		env->file_name_lenmax = (*data)->file_name_len;
	(*data)->link_name = malloc(sizeof(char) * (PATH_MAX + 1));
	if ((i = readlink((*data)->path, (*data)->link_name, PATH_MAX)) != -1)
		(*data)->link_name[i] = '\0';
}

void		get_file_data(t_env *env, t_data **data, char *path, char *name)
{
	(*data) = malloc(sizeof(t_data));
	init_data(data);
	(*data)->path = ft_strdup(ft_strjoin(path, "/"));
	(*data)->path = ft_strdup(ft_strjoin((*data)->path, name));
	(*data)->stats = malloc(sizeof(struct stat));
	lstat(((*data)->path), (*data)->stats);
	(*data)->user = getpwuid((*data)->stats->st_uid);
	(*data)->group = getgrgid((*data)->stats->st_gid);
	(*data)->user_name = ft_strdup((*data)->user->pw_name);
	(*data)->user_name_len = ft_strlen((*data)->user_name);
	if ((*data)->user_name_len > env->user_name_lenmax)
		env->user_name_lenmax = (*data)->user_name_len;
	(*data)->group_name = ft_strdup((*data)->group->gr_name);
	(*data)->group_name_len = ft_strlen((*data)->group_name);
	if ((*data)->group_name_len > env->group_name_lenmax)
		env->group_name_lenmax = (*data)->group_name_len;
	(*data)->time = (*data)->stats->st_mtime;
	(*data)->mtime = ft_modif_time(ctime(&((*data)->time)));
	(*data)->type = ft_get_type((*data));
	(*data)->nb_blocks = (*data)->stats->st_blocks;
	(*data)->nlink = (*data)->stats->st_nlink;
	(*data)->nlink_len = ft_nbrlen((*data)->nlink);
	if ((*data)->nlink_len > env->nlink_lenmax)
		env->nlink_lenmax = (*data)->nlink_len;
	get_file_data2(env, data, name);
}

int			ft_count_files(char *path)
{
	DIR				*odir_ret;
	struct dirent	*r_ret;
	int				i;
	int				o_ret;

	i = 0;
	odir_ret = opendir(path);
	if (!odir_ret)
	{
		if ((o_ret = open(path, O_RDONLY)) == -1)
			return (-1);
		else
		{
			close(o_ret);
			return (1);
		}
	}
	while ((r_ret = (readdir(odir_ret))))
		i++;
	closedir(odir_ret);
	return (i);
}
