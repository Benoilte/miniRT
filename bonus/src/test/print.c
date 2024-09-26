/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:06:53 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/25 11:28:52 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_color(t_color c, char *msg)
{
	printf("\t%-10s: rd: %- 10.5f green: %- 10.5f ", msg, c.red, c.green);
	printf("blue: %- 10.5f\n", c.blue);
}

void	print_tuple(t_tuple a, char *msg)
{
	printf("\t%-20s: x: %- 10.5f y: %- 10.5f ", msg, a.x, a.y);
	printf("z: %- 10.5f w: %- 10.5f\n", a.z, a.w);
}

void	print_args(char **args)
{
	int	i;

	if (!args)
		ft_printf("No args");
	i = 0;
	while (args[i])
		ft_printf("[%s] ", args[i++]);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	print_token(void *content)
{
	t_token	*token;

	if (!content)
		return ;
	token = (t_token *)content;
	ft_printf("=== <TOKEN> ===\n");
	ft_printf("identifier:\t%d\n", token->identifier);
	ft_printf("args:\t\t");
	print_args(token->args);
	ft_printf("line:\t\t%d\n", token->line);
	ft_printf("=== <END> ===\n\n");
}
