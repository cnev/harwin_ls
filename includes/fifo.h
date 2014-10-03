/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 18:42:30 by vjung             #+#    #+#             */
/*   Updated: 2014/10/03 18:42:30 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFO_H
# define FIFO_H
# include <stdlib.h>
# include "libft.h"

typedef struct		s_fifo
{
	void			*item;
	struct s_fifo	*next;
}					t_fifo;

void				push_fifo(t_fifo **first, void *item);
t_fifo				*pop_fifo(t_fifo **first);

#endif
