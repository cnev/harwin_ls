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
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/stat.h>
# include <../includes/ft_list.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <stdio.h>
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
	int				mono;
	int				first;
}					t_ls;
typedef struct		s_file
{
	struct stat		*sstat;
	char			*name;
}					t_file;
typedef struct		s_dir
{
	struct stat		*sstat;
	char			*name;
	char			*path;
}					t_dir;
typedef struct		s_display
{
	int				mode;
	int				links;
	int				owner;
	int				group;
	int				size;
	int				month;
	int				day;
	int				hour;
	int				min;
}					t_display;
/*
** argchecks.c
*/
int					read_command(int ac, char **av, t_ls *info);

/*
** ls.c
*/
int					begin_ls(t_ls *info);

/*
** exec_ls.c
*/
int					exec_ls(t_ls *ls);
int					ls_dir(t_ls *ls, char *path);

/*
** recursive_ls.c
*/
int					recursive_ls(t_ls *ls, char *path);

/*
** display_result.c
*/
int					display_results(t_ls *ls, t_list **lst, char *path);

/*
** formats.c
*/
void				test_links(t_display *display, t_list *elem);
void				test_owner(t_display *display, t_list *elem);
void				test_group(t_display *display, t_list *elem);
void				test_size(t_display *display, t_list *elem);

/*
** print_l
*/
void				print_owner(uid_t uid, int max_size);
void				print_group(gid_t gid, int max_size);
void				print_size(off_t n, int max_size);
void				print_date(struct stat *sstat);
int					print_total(t_list *lst);

/*
** printl2
*/
void				print_perm(char *link, mode_t chmod);
void				print_links(nlink_t n, int max_size);

/*
** display_results2.c
*/
int					file_cmp(t_file *c1, t_file *c2);
int					time_cmp(t_file *c1, t_file *c2);
void				init_display(t_display *display);
void				find_len(t_list **lst, t_display *display);
#endif
