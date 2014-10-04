/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 17:04:19 by vjung             #+#    #+#             */
/*   Updated: 2014/09/09 17:04:19 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"
#include <stdlib.h>

void			ft_list_clear(t_list **begin_list)
{
	t_list			*tmp;
	t_list			*tmp2;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp)
		{
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
		*begin_list = NULL;
	}
}
