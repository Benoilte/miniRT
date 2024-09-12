/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:53:19 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 15:31:59 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**get_element(t_list *token_list, t_id id)
{
	t_token	*token;

	if (!token_list)
		return (print_error("get_element", INVALID_POINTER), NULL);
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->identifier == id)
			return (token->args);
		token_list = token_list->next;
	}
	print_error("get_element", "could not find element in token list");
	return (NULL);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit_error(data, "Failed to allocate memory for data");
	if(init_input(&data->input, argc, argv) != 0)
		exit_error(data, "Failed to initialize input data");
	data->world = init_world();
	if (!data->world)
		exit_error(data, "Failed to initialize world");
	data->camera = init_camera(get_element(data->input.token_list, ID_CAMERA));
	if (!data->camera)
		exit_error(data, "Failed to allocate memory for camera");
	data->mlx = init_mlx();
	if (!data->mlx)
		exit_error(data, "Failed to initialize mlx data");
	return (data);
}
