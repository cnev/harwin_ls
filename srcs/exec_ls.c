/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 18:05:43 by vjung             #+#    #+#             */
/*   Updated: 2014/10/03 18:05:43 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static t_file	*build_filedata(struct stat *sstat, char *name)
{
	t_file			*new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		exit(-1);
	new->sstat = sstat;
	new->name = name;
	return (new);
}

static int		ls_file(t_ls *ls, char *path)
{
	t_list			*lst;
	char			*name;
	struct stat		*sstat;

	if (!(sstat = (struct stat *)malloc(sizeof(struct stat))))
		exit(-1);
	if (stat(path, sstat) < 0)
		return (-1);
	name = (ft_strrchr(path, '/')) == NULL ? path : ft_strrchr(path, '/');
	lst = NULL;
	ft_list_push_back(&lst, build_filedata(sstat, name));
	display_results(ls, &lst, path);
	return (0);
}

static int		fetch_filedata(t_ls *ls, t_list **lst, char *path,
	struct dirent *dir)
{
	struct stat		*sstat;
	char			*file_path;
	char			*link;

	if (!(ls->flag_a) && dir->d_name[0] == '.')
		return (0);
	link = get_link(dir->d_name, path);
	file_path = ft_strjoin(ft_strjoin(path, "/"), dir->d_name);
	if (!(sstat = (struct stat *)malloc(sizeof(struct stat))))
		exit(-1);
	if (!link && stat(file_path, sstat) < 0)
		return (-1);
	else if (lstat(file_path, sstat) < 0)
		return (-1);
	ft_strdel(&file_path);
	ft_list_push_back(lst, build_filedata(sstat, ft_strdup(dir->d_name)));
	return (0);
}

int				ls_dir(t_ls *ls, char *path)
{
	void			*dir;
	struct dirent	*dir_name;
	t_list			*lst;
	char			*dirname;

	dirname = ft_strrchr(path, '/');
	lst = NULL;
	if (dirname && dirname[1] == '.')
	{
		ls->first = TRUE;
		recursive_ls(ls, path);
		return (0);
	}
	if (!(dir = opendir(path)))
		return (return_error(path));
	while ((dir_name = readdir(dir)))
		fetch_filedata(ls, &lst, path, dir_name);
	closedir(dir);
	display_results(ls, &lst, path);
	if (ls->flag_rec)
		recursive_ls(ls, path);
	return (0);
}

int				exec_ls(t_ls *ls)
{
	t_fifo			*tmp;
	struct stat		sstat;

	tmp = ls->dirlst;
	while (tmp)
	{
		if (ls->first)
			ls->first = FALSE;
		else
			ft_putchar('\n');
		if (stat(tmp->item, &sstat) < 0)
		{
			return_error(tmp->item);
			tmp = tmp->next;
			continue ;
		}
		if (S_ISDIR(sstat.st_mode))
			ls_dir(ls, tmp->item);
		else if (S_ISREG(sstat.st_mode))
			ls_file(ls, tmp->item);
		tmp = tmp->next;
	}
	return (0);
}
