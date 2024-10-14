/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:18:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/14 15:45:03 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_input(t_input_data *input)
{
	if (!input)
		return ;
	if (input->fd >= 0 && close(input->fd) != 0)
		print_error("destroy_input", strerror(errno));
	ft_lstclear(&input->errors, free);
	ft_lstclear(&input->token_list, delete_token);
}
