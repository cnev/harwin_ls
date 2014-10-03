/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 18:42:36 by vjung             #+#    #+#             */
/*   Updated: 2014/10/03 18:42:37 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H
# include <stdlib.h>
# include "../includes/fifo.h"
# define TRUE 		1
# define FALSE		0

typedef struct		s_ls
{
	int				flag_l;
	int				flag_rev;
	int				flag_a;
	int				flag_rec;
	int				flag_t;
	t_fifo			*dirlst;
}					t_ls;

/*
** argchecks.c
*/
int					read_command(int ac, char **av, t_ls *info);

/*
** ls.c
*/
int					begin_ls(t_ls *info);

#endif
