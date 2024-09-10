/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:49:32 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/11 00:26:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <time.h>

int		set_default_scene(t_data *data);
int		add_walls_and_floor(t_data *data);
int		set_first_scene(t_data *data);
int		set_first_scene_with_plane(t_data *data);
int		test_shadow(t_data *data);
int		test_plane(void);
int		test_cylinder(void);
int		set_scene_with_cylinder(t_data *data);

void	timed_render(t_data *data)
{
	clock_t	start;
	double	end;

	start = clock();
	render(data);
	end = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("Render time: %.2f seconds\n", end);
}

int	test_code(char *test, t_data *data)
{
	if (ft_strncmp(test, "shadow", 7) == 0)
		return (test_shadow(data));
	else if (ft_strncmp(test, "plane", 6) == 0)
		return (test_plane());
	else if (ft_strncmp(test, "cylinder", 9) == 0)
		return (test_cylinder());
	return (1);
}

int	set_scene(char *test, t_data *data)
{
	if (ft_strncmp(test, "default", 8) == 0)
		return (set_default_scene(data));
	else if (ft_strncmp(test, "fscene", 7) == 0)
		return (set_first_scene(data));
	else if (ft_strncmp(test, "pscene", 7) == 0)
		return (set_first_scene_with_plane(data));
	else if (ft_strncmp(test, "clscene", 8) == 0)
		return (set_scene_with_cylinder(data));
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	printf("Hello, in test program!\n");
	if (argc != 2)
		return (0);
	data = init_data();
	if (test_code(argv[1], data) == 0)
	{
		destroy_data(data);
		return (0);
	}
	if (set_scene(argv[1], data) == 1)
	{
		destroy_data(data);
		return (0);
	}
	set_hooks(data);
	timed_render(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}
