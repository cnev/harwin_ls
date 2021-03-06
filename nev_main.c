/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 17:41:16 by cnev              #+#    #+#             */
/*   Updated: 2014/10/03 17:41:17 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

int				main(int ac, char **av)
{
	t_ls			info;

	if ((read_command(ac, av, &info)) == -1)
		return (1);
	if ((begin_ls(&info)) == -1)
		return (1);
	return (0);
}
