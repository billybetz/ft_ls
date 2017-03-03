/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 19:35:09 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/13 19:35:11 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	exit_wrong_option(t_env *env, char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-", 2);
	ft_putstr_fd(OPTIONS_GERE, 2);
	ft_putstr_fd("] [file ...]\n", 2);
	ft_putchar('\0');
	exit(0);
}

void	ft_errmess_wrong_name(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	ft_errmess_noright(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}
