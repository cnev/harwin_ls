/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 15:29:26 by vjung             #+#    #+#             */
/*   Updated: 2014/09/09 15:29:27 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"

t_list			*ft_create_elem(void *data)
{
	t_list			*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		exit(-1);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}
