/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nev_argchecks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 17:48:57 by cnev              #+#    #+#             */
/*   Updated: 2014/10/03 17:48:57 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

int				read_command(int ac, char **av, t_ls *info)
{
	if (ac == 1)
		zero_flags(info);
	else if (ac == 2)
	{
		if ((detect_flags(info)) == -1)
			return (-1);
	}
	info->dirlst = NULL;
	return (0);
}
