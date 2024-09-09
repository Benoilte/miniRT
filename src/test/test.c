/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:49:32 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/09 16:01:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <time.h>

void	set_default_scene(t_data *data);
void	set_first_scene(t_data *data);
void	set_first_scene_with_plane(t_data *data);
void	test_shadow(t_data *data);
int		test_plane(void);

void	timed_render(t_data *data)
{
	clock_t	start;
	double	end;

	start = clock();
	render(data);
	end = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("Render time: %.2f seconds\n", end);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	printf("Hello, in test program!\n");
	if (argc != 2)
		return (0);
	if (ft_strncmp(argv[1], "plane", 6) == 0)
		return (test_plane());
	data = init_data();
	set_hooks(data);
	if (ft_strncmp(argv[1], "default", 8) == 0)
		set_default_scene(data);
	else if (ft_strncmp(argv[1], "fscene", 7) == 0)
		set_first_scene(data);
	else if (ft_strncmp(argv[1], "shadow", 7) == 0)
		test_shadow(data);
	else if (ft_strncmp(argv[1], "pscene", 7) == 0)
		set_first_scene_with_plane(data);
	else
		return (0);
	timed_render(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}
