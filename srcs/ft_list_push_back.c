/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 15:43:06 by vjung             #+#    #+#             */
/*   Updated: 2014/09/09 15:43:07 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"
t_list			*ft_create_elem(void *data);

void			ft_list_push_back(t_list **begin_list, void *data)
{
	t_list			*tmp;

	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
	}
}
