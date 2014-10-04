/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 18:44:12 by vjung             #+#    #+#             */
/*   Updated: 2014/10/03 18:44:12 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

int				main(int ac, char **av)
{
	t_ls			info;

	if ((read_command(ac, av, &info)) == -1)
		return (1);
	/*if ((begin_ls(&info)) == -1)
		return (1);*/
	exec_ls(&info);
	return (0);
}
