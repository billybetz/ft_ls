/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 21:48:14 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/13 12:39:27 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_env	*env;

	env = malloc(sizeof(t_env ));
	init_env(env);
	get_args(env, av, ac);
	get_data(env);
	ft_putchar('\0');
	return (0);
}
