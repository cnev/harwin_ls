/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nev_ls.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 17:45:54 by cnev              #+#    #+#             */
/*   Updated: 2014/10/03 17:45:55 by cnev             ###   ########.fr       */
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
	int				flag_r;
	int				flag_a;
	int				flag_R;
	int				flag_t;
	t_fifo			*dirlst;
}					t_ls;

/*
** argchecks.c
*/
int				read_command(int ac, char **av, t_ls *info);

/*
** ls.c
*/
int				begin_ls(t_ls *info);

#endif
