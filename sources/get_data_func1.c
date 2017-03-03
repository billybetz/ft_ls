/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_func1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:51:48 by bbetz             #+#    #+#             */
/*   Updated: 2016/09/08 16:51:49 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	take_data_recursif3(t_env *env, char *path, t_tdr *tdr)
{
	if (env->err == 1)
	{
		ft_putstr(path);
		ft_putchar(':');
		ft_putchar('\n');
	}
	print_data(env, tdr->files);
	tdr->y = -1;
	while (tdr->files->data[++tdr->y])
	{
		if (tdr->files->data[tdr->y]->type == 'd' && (ft_strcmp(NAME, ".\0")) &&
				(ft_strcmp(NAME, "..\0")))
		{
			path = ft_strjoin(path, "/\0");
			path = ft_strjoin(path, tdr->files->data[tdr->y]->file_name);
			if ((ft_strfindchar(env->options->list, 'a') != -1) ||
					(ft_strfindchar(env->options->list, 'f') != -1) ||
					tdr->files->data[tdr->y]->file_name[0] != '.')
				take_data_recursif(env, path, NAME);
			path = cut_last_file_to_path(path);
		}
	}
}

static void	take_data_recursif2(t_env *env, char *path, char *name, t_tdr *tdr)
{
	tdr->files->data = malloc(sizeof(t_data) * (tdr->files->nb_files + 1));
	tdr->files->data[tdr->files->nb_files] = NULL;
	tdr->odir_ret = opendir(path);
	if (tdr->odir_ret)
	{
		while ((tdr->r_ret = (readdir(tdr->odir_ret))))
		{
			get_file_data(env, &(DATA_GET_DATA), path, tdr->r_ret->d_name);
			if ((ft_strfindchar(env->options->list, 'a') != -1) ||
					tdr->files->data[tdr->y]->file_name[0] != '.')
				tdr->files->total_blocks += tdr->files->data[tdr->y]->nb_blocks;
			tdr->y++;
		}
		take_data_recursif3(env, path, tdr);
		closedir(tdr->odir_ret);
	}
	else
	{
		get_file_data(env, &(tdr->files->data[0]), ".\0", name);
		print_data(env, tdr->files);
	}
}

int			take_data_recursif(t_env *env, char *path, char *name)
{
	t_tdr	*tdr;

	tdr = malloc(sizeof(t_tdr));
	tdr->y = 0;
	init_lens(env);
	tdr->odir_ret = malloc(sizeof(DIR));
	tdr->r_ret = malloc(sizeof(struct dirent));
	tdr->files = malloc(sizeof(t_files_ls));
	tdr->files->nb_files = 0;
	tdr->files->total_blocks = 0;
	if (env->first_write == 1)
		ft_putchar('\n');
	if ((tdr->files->nb_files = ft_count_files(path)) == -1)
	{
		tdr->files = NULL;
		ft_putstr(path);
		ft_putstr(":\n");
		(EACCES) ? ft_errmess_noright(path) : ft_errmess_wrong_name(path);
		ft_putchar('\n');
	}
	else
		take_data_recursif2(env, path, name, tdr);
	return (0);
}

static void	take_data_no_recursif2(t_env *env, char *name, t_tdnr *tdnr)
{
	if (env->first_write == 1)
		ft_putchar('\n');
	if (env->err == 1)
	{
		ft_putstr(name);
		ft_putchar(':');
		ft_putchar('\n');
	}
	while ((tdnr->r_ret = (readdir(tdnr->odir_ret))))
	{
		get_file_data(env, &(LOL), name, tdnr->r_ret->d_name);
		if ((ft_strfindchar(env->options->list, 'a') != -1) ||
				tdnr->files->data[tdnr->y]->file_name[0] != '.')
			tdnr->files->total_blocks += tdnr->files->data[tdnr->y]->nb_blocks;
		tdnr->y++;
	}
	closedir(tdnr->odir_ret);
}

int			take_data_no_recursif(t_env *env, char *name)
{
	t_tdnr	*tdnr;

	tdnr = malloc(sizeof(t_tdr));
	init_lens(env);
	tdnr->y = 0;
	tdnr->r_ret = malloc(sizeof(struct dirent));
	tdnr->files = malloc(sizeof(t_files_ls));
	tdnr->files->nb_files = 0;
	tdnr->files->total_blocks = 0;
	if ((tdnr->files->nb_files = ft_count_files(name)) == -1)
	{
		ft_putcolor("OPEN FAILED\n", RED);
		exit(0);
	}
	tdnr->files->data = malloc(sizeof(t_data) * (tdnr->files->nb_files + 1));
	tdnr->files->data[tdnr->files->nb_files] = NULL;
	tdnr->odir_ret = opendir(name);
	if (tdnr->odir_ret)
		take_data_no_recursif2(env, name, tdnr);
	else
		get_file_data(env, &(tdnr->files->data[0]), ".\0", name);
	print_data(env, tdnr->files);
	return (0);
}
