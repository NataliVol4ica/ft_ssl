/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:38:07 by nkolosov          #+#    #+#             */
/*   Updated: 2018/01/22 14:38:08 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include "funcs.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	size_t		i;
	t_params	*p;

	if (ac < 2)
	{
		ft_printf("Invalid number of arguments\n");
		exit (1);
	}
	i = -1;
	while (++i < NUM_OF_FUNCS)
	{
		if (ft_strcmp(av[1], g_parse_funcs[i].name) == 0)
		{
			p = new_param(ac, av);
			g_parse_funcs[i].func((void*)p);
			break;
		}
	}
	if (i == NUM_OF_FUNCS)
		ft_printf("Unknow command: %s\n", av[1]);
	return (0);
}
