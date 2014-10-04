/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_results.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 21:39:51 by vjung             #+#    #+#             */
/*   Updated: 2014/10/03 21:39:52 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static void		display_filedata(t_display *display, t_list *file)
{
	t_file			*data;
	struct stat		*sstat;

	data = file->data;
	sstat = data->sstat;
	print_perm(sstat->st_mode);
	print_links(sstat->st_nlink, display->links);
	print_owner(sstat->st_uid, display->owner);
	print_group(sstat->st_gid, display->group);
	print_size(sstat->st_size, display->size);
	print_date(sstat);
	ft_putendl(data->name);
}



static void		display_l(t_list **lst, char *path)
{
	t_display		display;
	t_list			*tmp;
	struct stat		sstat;

	init_display(&display);
	find_len(lst, &display);
	stat(path, &sstat);
	if (*lst)
	{
		ft_putstr("total ");
		ft_putnbr(print_total(*lst));
		ft_putchar('\n');
	}
	tmp = *lst;
	while (tmp)
	{
		display_filedata(&display, tmp);
		tmp = tmp->next;
	}
}

static void		display_path(t_ls *ls, char *path)
{
	if (ls->mono)
		ls->mono = FALSE;
	else
	{
		ft_putstr(path);
		ft_putendl(":");
	}
}
int				display_results(t_ls *ls, t_list **lst, char *path)
{
	t_list			*tmp;
	t_file			*data;

	display_path(ls, path);
	if (ls->flag_rev)
		ft_list_rsort(lst, file_cmp);
	else
		ft_list_sort(lst, file_cmp);
	if (ls->flag_rev && ls->flag_t)
		ft_list_rsort(lst, time_cmp);
	else if (ls->flag_t)
		ft_list_sort(lst, time_cmp);
	if (ls->flag_l)
		display_l(lst, path);
	else
	{
		tmp = *lst;
		while (tmp)
		{
			data = tmp->data;
			ft_putendl(data->name);
			tmp = tmp->next;
		}
	}
	return (0);
}
