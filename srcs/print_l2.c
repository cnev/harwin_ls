/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/04 16:42:15 by vjung             #+#    #+#             */
/*   Updated: 2014/10/04 16:42:15 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void			print_perm(char *link, mode_t chmod)
{
	char			str[12];

	str[0] = link ? 'l' : '-';
	str[0] = S_ISDIR(chmod) ? 'd' : str[0];
	str[1] = chmod & S_IRUSR ? 'r' : '-';
	str[2] = chmod & S_IWUSR ? 'w' : '-';
	str[3] = chmod & S_IXUSR ? 'x' : '-';
	str[4] = chmod & S_IRGRP ? 'r' : '-';
	str[5] = chmod & S_IWGRP ? 'w' : '-';
	str[6] = chmod & S_IXGRP ? 'x' : '-';
	str[7] = chmod & S_IROTH ? 'r' : '-';
	str[8] = chmod & S_IWOTH ? 'w' : '-';
	str[9] = chmod & S_IXOTH ? 'x' : '-';
	str[10] = !S_ISLNK(chmod) ? '@' : ' ';
	str[11] = 0;
	ft_putstr(str);
	ft_putchar(' ');
}

void			print_links(nlink_t n, int max_size)
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
