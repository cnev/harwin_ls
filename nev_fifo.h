/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nev_fifo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 18:23:46 by cnev              #+#    #+#             */
/*   Updated: 2014/10/03 18:23:47 by cnev             ###   ########.fr       */
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

#endif
