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

typedef struct		s_queue
{
	char			*dir;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_ls
{
	int				flag_l;
	int				flag_r;
	int				flag_a;
	int				flag_R;
	int				flag_t;
	t_queue			*dirlst;
}					t_ls;

#endif
