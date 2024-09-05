/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:49:32 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/05 08:52:02 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_default_scene(t_data *data);
void	set_first_scene(t_data *data);
void	test_shadow(t_data *data);

int	main(int argc, char **argv)
{
	t_data	*data;

	printf("Hello, in test program!\n");
	if (argc != 2)
		return (0);
	data = init_data();
	set_hooks(data);
	if (ft_strncmp(argv[1], "default", 8) == 0)
		set_default_scene(data);
	else if (ft_strncmp(argv[1], "fscene", 8) == 0)
		set_first_scene(data);
	else if (ft_strncmp(argv[1], "shadow", 8) == 0)
	{
		test_shadow(data);
		return (0);
	}
	else
		return (0);
	render(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}
