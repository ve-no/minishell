/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:57:21 by ibouchaf          #+#    #+#             */
/*   Updated: 2023/06/23 14:22:02 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **p)
{
	int	i;

	i = -1;
	if (!p)
		return ;
	while (p[++i] != NULL)
	{
		if (ft_strchr(p[i], '='))
			printf("%s\n", p[i]);
	}
	g_status = 0;
}