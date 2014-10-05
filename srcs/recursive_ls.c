/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 20:58:33 by vjung             #+#    #+#             */
/*   Updated: 2014/10/03 20:58:33 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static int		dir_cmp(t_dir *c1, t_dir *c2)
{
	return (ft_strcmp(c1->name, c2->name));
}

static int		dirtime_cmp(t_dir *c1, t_dir *c2)
{
	return (c2->sstat->st_mtime - c1->sstat->st_mtime);
}

static int		recurse_list(t_ls *ls, t_list **lst)
{
	t_list			*tmp;
	t_dir			*data;

	if (ls->flag_rev)
		ft_list_rsort(lst, dir_cmp);
	else
		ft_list_sort(lst, dir_cmp);
	if (ls->flag_rev && ls->flag_t)
		ft_list_rsort(lst, dirtime_cmp);
	else if (ls->flag_t)
		ft_list_sort(lst, dirtime_cmp);
	tmp = *lst;
	while (tmp)
	{
		if (ls->first)
			ls->first = FALSE;
		else
			ft_putchar('\n');
		data = tmp->data;
		ls_dir(ls, data->path);
		tmp = tmp->next;
	}
	return (0);
}

static t_dir	*build_dirdata(char *name, char *path, struct stat (*sstat))
{
	t_dir			*new;

	if (!(new = (t_dir *)malloc(sizeof(t_dir))))
		exit(-1);
	new->sstat = sstat;
	new->name = name;
	new->path = path;
	return (new);
}

int				recursive_ls(t_ls *ls, char *path)
{
	void			*dir;
	struct dirent	*dir_name;
	struct stat		*sstat;
	char			*filename;
	t_list			*lst;

	lst = NULL;
	if (!(dir = opendir(path)))
		return (-1);
	while ((dir_name = readdir(dir)))
	{
		if (!ft_strcmp(dir_name->d_name, ".")
			|| !ft_strcmp(dir_name->d_name, ".."))
			continue ;
		filename = ft_strjoin(ft_strjoin(path, "/"), dir_name->d_name);
		if (!(sstat = (struct stat *)malloc(sizeof(struct stat))))
			exit(-1);
		if (stat(filename, sstat) < 0)
			continue ;
		if (S_ISDIR(sstat->st_mode))
			ft_list_push_back(&lst,
				build_dirdata(dir_name->d_name, filename, sstat));
	}
	closedir(dir);
	return (recurse_list(ls, &lst));
}
