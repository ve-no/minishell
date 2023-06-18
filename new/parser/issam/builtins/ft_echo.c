/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchaf <ibouchaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:07:46 by ibouchaf          #+#    #+#             */
/*   Updated: 2023/06/14 14:21:17 by ibouchaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	check_flag(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '-')
		return (0);
	else if (!str[1])
		return (0);
	while (str[++i])
	{
		if (str[i] != 'n')
			return (0);
	}
	return (1);
}

void	ft_echo(t_prompt *p)
{
	int		flag;
	t_list	*lst;
	t_mini	*mini;

	lst = (t_list *) p->cmds;
	mini = lst->content;
	p->i = 0;
	flag = 0;
	if (mini->full_cmd[0] != NULL)
	{
		while (mini->full_cmd[++p->i])
		{
			if (check_flag(mini->full_cmd[p->i]))
			{
				flag = 1;
				continue ;
			}
			printf("%s", mini->full_cmd[p->i]);
			if (p->i != (int)ft_strlen_2(mini->full_cmd) - 1)
				printf(" ");
		}
	}
	if (!flag)
		printf("\n");
	return ;
}
