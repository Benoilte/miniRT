/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:12:51 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/14 13:24:26 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_input(t_input_data *input, int argc, char **argv)
{
	if (!input || !argv)
		return (input_error(input, "init_input", INVALID_POINTER));
	if (argc != 2)
		return (input_error(input, NULL, INPUT_ERR_USAGE), 2);
	if (validate_file(argv[1], &input->fd) != 0)
		return (3);
	if (lexer(input) != 0)
		return (4);
	if (parser(input) != 0)
		return (5);
	return (0);
}
