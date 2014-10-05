/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 18:43:57 by vjung             #+#    #+#             */
/*   Updated: 2014/10/03 18:43:58 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static int		zero_flags(t_ls *info)
{
	info->flag_l = FALSE;
	info->flag_rev = FALSE;
	info->flag_a = FALSE;
	info->flag_rec = FALSE;
	info->flag_t = FALSE;
	info->mono = TRUE;
	info->first = TRUE;
	return (0);
}

static int		set_flags(char flag, t_ls *info)
{
	if (flag == 'l')
		info->flag_l = TRUE;
	else if (flag == 'r')
		info->flag_rev = TRUE;
	else if (flag == 'a')
		info->flag_a = TRUE;
	else if (flag == 'R')
		info->flag_rec = TRUE;
	else if (flag == 't')
		info->flag_t = TRUE;
	else
	{
		ft_putstr("/bin/ls: illegal option -- ");
		ft_putchar(flag);
		ft_putchar('\n');
		ft_putstr("> usage: ls [-ABCFGHLOPRSTUWabcdefghi");
		ft_putendl("klmnopqrstuwx1] [file ...]");
		return (-1);
	}
	return (0);
}

static int		detect_flags(char *flags, t_ls *info)
{
	int				i;

	i = 0;
	while (flags[++i])
	{
		if (set_flags(flags[i], info) < 0)
			return (1);
	}
	return (0);
}

static int		fetch_targets(t_ls *info, int ac, char **av, t_fifo **dirlst)
{
	int				i;
	int				flag_set;

	flag_set = FALSE;
	i = 0;
	while (++i < ac)
	{
		if (!flag_set && av[i][0] == '-')
			detect_flags(av[i], info);
		else
		{
			flag_set = TRUE;
			push_fifo(dirlst, av[i]);
		}
	}
	if (!*dirlst)
		push_fifo(dirlst, ".");
	if ((*dirlst)->next)
		info->mono = FALSE;
	return (0);
}

int				read_command(int ac, char **av, t_ls *info)
{
	zero_flags(info);
	info->dirlst = NULL;
	fetch_targets(info, ac, av, &(info->dirlst));
	return (0);
}
