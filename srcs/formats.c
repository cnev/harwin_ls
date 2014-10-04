/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 22:17:43 by vjung             #+#    #+#             */
/*   Updated: 2014/10/03 22:17:44 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void			test_links(t_display *display, t_list *elem)
{
	int				nb_links;
	int				size;
	t_file			*data;

	size = 1;
	data = elem->data;
	nb_links = data->sstat->st_nlink / 10;
	while (nb_links > 0)
	{
		size++;
		nb_links /= 10;
	}
	if (display->links < size)
		display->links = size;
}

void			test_owner(t_display *display, t_list *elem)
{
	int				len;
	t_file			*data;
	struct passwd	*pwd;

	data = elem->data;
	pwd = getpwuid(data->sstat->st_uid);
	len = ft_strlen(pwd->pw_name);
	if (display->owner < len)
		display->owner = len;
}

void			test_group(t_display *display, t_list *elem)
{
	int				len;
	t_file			*data;
	struct group	*grp;

	data = elem->data;
	grp = getgrgid(data->sstat->st_gid);
	len = ft_strlen(grp->gr_name);
	if (display->group < len)
		display->group = len;
}

void			test_size(t_display *display, t_list *elem)
{
	int				filesize;
	int				str_size;
	t_file			*data;

	str_size = 1;
	data = elem->data;
	filesize = data->sstat->st_size / 10;
	while (filesize > 0)
	{
		str_size++;
		filesize /= 10;
	}
	if (display->size < str_size)
		display->size = str_size;
}
