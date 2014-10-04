/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_results2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/04 16:45:56 by vjung             #+#    #+#             */
/*   Updated: 2014/10/04 16:46:14 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

int				file_cmp(t_file *c1, t_file *c2)
{
	return (ft_strcmp(c1->name, c2->name));
}

int				time_cmp(t_file *c1, t_file *c2)
{
	return (c2->sstat->st_mtime - c1->sstat->st_mtime);
}

void			init_display(t_display *display)
{
	display->mode = 11;
	display->links = 0;
	display->owner = 0;
	display->group = 0;
	display->size = 0;
	display->month = 3;
	display->day = 2;
	display->hour = 2;
	display->min = 2;
}

void			find_len(t_list **lst, t_display *display)
{
	t_list			*tmp;

	tmp = *lst;
	while (tmp)
	{
		test_links(display, tmp);
		test_owner(display, tmp);
		test_group(display, tmp);
		test_size(display, tmp);
		tmp = tmp->next;
	}
}
