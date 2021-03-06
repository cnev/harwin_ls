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

static int		zero_flags(t_ls *info)
{
	info->flag_l = FALSE;
	info->flag_r = FALSE;
	info->flag_a = FALSE;
	info->flag_R = FALSE;
	info->flag_t = FALSE;
	return (0);
}

static int		detect_flags(char *flags, t_ls *info)
{
	int				i;

	zero_flags(info);
	if (flags[0] != '-')
		return (0);
	i = 0;
	while (flags[++i])
	{
		if (flags[i] == 'l')
			info->flag_l = TRUE;
		else if (flags[i] == 'r')
			info->flag_r = TRUE;
		else if (flags[i] == 'a')
			info->flag_a = TRUE;
		else if (flags[i] == 'R')
			info->flag_R = TRUE;
		else if (flags[i] == 't')
			info->flag_t = TRUE;
		else
			return (-1);
	}
	return (0);
}

static int		fetch_targets(int ac, char **av, t_fifo **dirlst)
{
	int				i;

	i = 1;
	if (ac == 1 || (ac == 2 && !ft_strcmp(av[1], "~")))
		push_fifo(dirlst, "~");
	else
	{
		if (av[1][0] != '-')
			push_fifo(dirlst, av[1]);
		while (++i < ac)
			push_fifo(dirlst, av[i]);
	}
	return (0);
}

int				read_command(int ac, char **av, t_ls *info)
{
	if (ac == 1)
		zero_flags(info);
	else
	{
		if ((detect_flags(av[1], info)) == -1)
			return (-1);
	}
	info->dirlst = NULL;
	fetch_targets(ac, av, &(info->dirlst));
	return (0);
}
