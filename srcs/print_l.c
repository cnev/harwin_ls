/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/04 16:41:16 by vjung             #+#    #+#             */
/*   Updated: 2014/10/04 16:41:16 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void			print_owner(uid_t uid, int max_size)
{
	int				len;
	struct passwd	*pwd;
	int				i;

	pwd = getpwuid(uid);
	len = ft_strlen(pwd->pw_name);
	i = max_size - len + 1;
	while (--i > 0)
		ft_putchar(' ');
	ft_putstr(pwd->pw_name);
	ft_putstr("  ");
}

void			print_group(gid_t gid, int max_size)
{
	int				len;
	struct group	*grp;
	int				i;

	grp = getgrgid(gid);
	len = ft_strlen(grp->gr_name);
	i = max_size - len + 1;
	while (--i > 0)
		ft_putchar(' ');
	ft_putstr(grp->gr_name);
	ft_putstr("  ");
}

void			print_size(off_t n, int max_size)
{
	int				size;
	int				i;
	int				tmp;

	size = 1;
	tmp = n / 10;
	while (tmp > 0)
	{
		size++;
		tmp /= 10;
	}
	i = max_size - size + 1;
	while (--i > 0)
		ft_putchar(' ');
	ft_putnbr(n);
	ft_putchar(' ');
}

void			print_date(struct stat *sstat)
{
	time_t			tps;
	char			*buf;
	time_t			now;

	tps = sstat->st_mtimespec.tv_sec;
	buf = ctime(&tps);
	time(&now);
	if (now > tps + 15811200 || now < tps - 3600)
	{
		buf[ft_strlen(buf) - 14] = ' ';
		buf[ft_strlen(buf) - 13] = '\0';
		ft_putstr(buf + 4);
		buf[24] = ' ';
		buf[25] = '\0';
		ft_putstr(buf + 20);
		return ;
	}
	buf[ft_strlen(buf) - 9] = ' ';
	buf[ft_strlen(buf) - 8] = '\0';
	ft_putstr(buf + 4);
}

int				print_total(t_list *lst)
{
	int				i;
	t_file			*data;

	i = 0;
	while (lst)
	{
		data = lst->data;
		i += data->sstat->st_blocks;
		lst = lst->next;
	}
	return (i);
}
