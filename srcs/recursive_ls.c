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

#include <stdio.h>
#include "../includes/ls.h"

int				recursive_ls(t_ls *ls, char *path)
{
	void			*dir;
	struct dirent	*dir_name;
	struct stat		sstat;
	char			*filename;

	if (!(dir = opendir(path)))
		return (-1);
	while ((dir_name = readdir(dir)))
	{
		if (!ft_strcmp(dir_name->d_name, ".")
			|| !ft_strcmp(dir_name->d_name, ".."))
				continue ;
		filename = ft_strjoin(ft_strjoin(path, "/"), dir_name->d_name);
		if (stat(filename, &sstat) < 0)
			continue ;
		if (S_ISDIR(sstat.st_mode))
		{
			if (ls->first)
				ls->first = FALSE;
			else
				ft_putchar('\n');
			ls_dir(ls, filename);
		}
	}
	return (0);
}
