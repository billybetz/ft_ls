/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 21:37:25 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/13 12:38:54 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/include/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <limits.h>

# define NAME_MAXLEN 256
# define NB_OPTIONS_GERE env->nb_options_geres
# define OPTIONS_GERE env->options->options_gere
# define LOL tdnr->files->data[tdnr->y]
# define DATA_GET_DATA tdr->files->data[tdr->y]
# define NAME tdr->files->data[tdr->y]->file_name
# define NAME_GET_DATA env->names->list[i]
# define NAME_SORT_DATA files->data[y]->file_name

typedef struct	s_data
{
	struct stat		*stats;
	struct passwd	*user;
	struct group	*group;
	char			*user_name;
	int				user_name_len;
	char			*group_name;
	int				group_name_len;
	char			*path;
	time_t			time;
	char			*mtime;
	char			type;
	int				nlink;
	int				nlink_len;
	long long int	nb_blocks;
	long long int	size_int;
	int				is_device;
	char			*major;
	char			*minor;
	int				major_len;
	int				minor_len;
	int				maj_min_len;
	char			*size;
	int				size_len;
	char			*file_name;
	char			*link_name;
	int				file_name_len;
}				t_data;

typedef struct	s_files_ls
{
	t_data			**data;
	long long int	total_blocks;
	int				nb_files;
}				t_files_ls;

typedef struct	s_options
{
	char			*options_gere;
	char			*list;
	int				nb;
}				t_options;

typedef struct	s_names
{
	char			**list;
	int				nb;
}				t_names;

typedef struct	s_tdr
{
	t_files_ls		*files;
	DIR				*odir_ret;
	struct dirent	*r_ret;
	int				y;
}				t_tdr;

typedef struct	s_tdnr
{
	t_files_ls		*files;
	DIR				*odir_ret;
	struct dirent	*r_ret;
	int				y;
}				t_tdnr;

typedef struct	s_env
{

	int				ac;
	char			**av;
	t_options		*options;
	t_names			*names;
	int				nb_options_geres;
	int				nlink_lenmax;
	int				size_lenmax;
	int				user_name_lenmax;
	int				group_name_lenmax;
	int				file_name_lenmax;
	int				major_lenmax;
	int				minor_lenmax;
	int				maj_min_lenmax;
	short			err;
	short			first_write;
}				t_env;

/*
**	===========	 **
**	 MAIN_FUNC	 **
**	===========	 **
*/

void			get_args(t_env *env, char **av, int ac);
void			get_data(t_env *env);
void			free_all(t_env *env);
void			check_names_validity(t_env *env);

/*
**	===========  **
**	 NAME_FUNC   **
**	===========  **
*/

void			init_lens(t_env *env);
void			init_data(t_data **data);
void			init_env(t_env *env);

/*
**	===============  **
**	 GET_DATA_FUNC	 **
**	===============  **
*/

int				take_data_no_recursif(t_env *env, char *name);
int				take_data_recursif(t_env *env, char *path, char *name);
void			get_file_data(t_env *env, t_data **data, char *path, char *n);
char			*ft_get_name_to_path(const char *path);
char			ft_get_type(t_data *data);
char			*ft_get_major(dev_t dev);
char			*ft_get_minor(dev_t dev);
int				ft_count_files(char *path);

/*
**	=================  **
**	 MODIF_DATA_FUNC   **
**	=================  **
*/

void			init_lens(t_env *env);
char			*ft_modif_time(char *time);
char			*cut_last_file_to_path(char *path);

/*
**	===========  **
**	 SORT_FUNC	 **
**	===========  **
*/

void			sort_names(t_env *env);
void			sort_files(t_env *env, t_files_ls *files);
void			sort_files_name(t_files_ls *files);
void			sort_files_reverse(t_files_ls *files);
void			sort_files_time_modif(t_files_ls *files);
void			sort_files_size(t_files_ls *files);

/*
**	============  **
**	 PRINT_FUNC	  **
**	============  **
*/

void			print_data(t_env *env, t_files_ls *files);
void			print_data_l(t_env *env, t_data *data);
void			print_name(t_env *env, t_data *data, int i);

/*
**	============  **
**	 ERROR_FUNC	  **
**	============  **
*/

void			exit_wrong_option(t_env *env, char c);
void			ft_errmess_wrong_name(char *name);
void			ft_errmess_noright(char *name);

/*
**	=============  **
**	 OPTION_FUNC   **
**	=============  **
*/

void			take_options(t_env *env);
void			add_option(t_env *env, char c);
int				option_exist(t_env *env, char c);
int				count_options(t_env *env);

/*
**	===========  **
**	 NAME_FUNC   **
**	===========  **
*/

void			take_names(t_env *env);
int				count_names(t_env *env);
void			take_off_name_from_list(t_env *env, int i);

/*
**	==========  **
**	 CMP_FUNC   **
**	==========  **
*/

long int		ft_time_cmp(time_t time1, time_t time2);
long int		ft_size_cmp(long long int size1, long long int size2);

/*
**	============  **
**	 CLEAR_FUNC	  **
**	============  **
*/

void			free_data(t_files_ls **files);

#endif
