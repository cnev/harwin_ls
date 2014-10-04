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


#include <stdio.h>
#include "../includes/ls.h"

static int		ls_file(t_ls *ls, char *file)
{
	(void)ls;
	ft_putendl(file);
	return (0);
}

static t_file	*build_filedata(struct stat *sstat, char *name)
{
	t_file			*new;

	new = (t_file *)malloc(sizeof(t_file));
	new->sstat = sstat;
	new->name = name;
	return (new);
}

static int		fetch_filedata(t_ls *ls, t_list **lst, char *path,
	struct dirent *dir)
{
	struct stat		*sstat;
	char			*file_path;

	if (!(ls->flag_a) && dir->d_name[0] == '.')
		return (0);
	file_path = ft_strjoin(ft_strjoin(path, "/"), dir->d_name);
	sstat = (struct stat *)malloc(sizeof(struct stat));
	stat(file_path, sstat);
	ft_strdel(&file_path);
	ft_list_push_back(lst, build_filedata(sstat, ft_strdup(dir->d_name)));
	return (0);
}

int				ls_dir(t_ls *ls, char *path)
{
	void			*dir;
	struct dirent	*dir_name;
	t_list			*lst;

	lst = NULL;
	if (!(dir = opendir(path)))
		return (-1);
	while ((dir_name = readdir(dir)))
	{
		fetch_filedata(ls, &lst, path, dir_name);
	}
	/*t_list *test = lst;
	t_file *testfile;
	printf("Current path: %s\n", path);
	while (test)
	{
		testfile = test->data;
		if (!ft_strcmp(testfile->name, ".")
			|| !ft_strcmp(testfile->name, ".."))
		{
			test = test->next;
			continue ;
		}
		printf("%s %lld\n", testfile->name, testfile->sstat->st_size);
		test = test->next;
	}
	printf("\n");*/
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
