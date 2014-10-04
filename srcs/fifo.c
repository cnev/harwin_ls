/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 18:44:05 by vjung             #+#    #+#             */
/*   Updated: 2014/10/03 18:44:06 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fifo.h"

static t_fifo	*new_fifo(void *item)
{
	t_fifo			*new;

	if (!(new = (t_fifo *)malloc(sizeof(t_fifo))))
		exit(-1);
	new->item = item;
	new->next = NULL;
	return (new);
}

void			push_fifo(t_fifo **first, void *item)
{
	t_fifo			*tmp;

	if (!*first)
	{
		*first = new_fifo(item);
		return ;
	}
	tmp = *first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_fifo(item);
}

t_fifo			*pop_fifo(t_fifo **first)
{
	t_fifo			*tmp;
	t_fifo			*next;

	if (!*first)
		return (NULL);
	if ((*first)->next == NULL)
	{
		tmp = *first;
		*first = NULL;
		return (tmp);
	}
	tmp = *first;
	next = tmp->next;
	*first = next;
	return (tmp);
}
