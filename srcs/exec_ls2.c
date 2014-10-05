/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ls2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/05 17:07:55 by vjung             #+#    #+#             */
/*   Updated: 2014/10/05 17:07:55 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

char			*get_link(char *name, char *path)
{
	char			*filepath;
	int				ret;
	char			buf[5000];

	filepath = ft_strjoin(ft_strjoin(path, "/"), name);
	if ((ret = readlink(filepath, buf, 5000)) < 0)
		return (NULL);
	buf[ret] = 0;
	return (ft_strdup(buf));
}
