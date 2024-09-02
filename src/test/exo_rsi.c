/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exo_rsi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:12:58 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/02 14:41:32 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

t_ray	transform_ray(t_ray r, t_m4x4 m)
{
	return (ray(mx_mult_tuple(m, r.origin), mx_mult_tuple(m, r.direction)));
}

t_intersect_list	*generate_list_intersections(t_shape *sp1, t_ray ray_transformed)
{
	t_intersection		*new_intersect;
	t_intersect_list	*new_dlist;
	t_intersect_report	report;
	t_intersect_list	*i_list;


	i_list = NULL;
	if (sp1->f->intersect(&ray_transformed, sp1, &report))
	{
		while (report.count--)
        {
            new_intersect = new_intersection(sp1, report.t[report.count]);
			new_dlist = dbl_lstnew(new_intersect);
            dbl_lstadd_ordered(&i_list, new_dlist, add_new_before_lst);
        }
	}
	return (i_list);
}

int	print_sp(t_point r_origin, t_m4x4 transform, t_data *data)
{
	float		wall_z = 10;
	float		wall_size = 7;
	float		pixel_size = wall_size / WIN_HEIGHT;
	float		half = wall_size / 2;
	t_color		color = rgb_itos(RED);
	t_shape	*sp = create_new_shape(SPHERE);
	float		y;
	float		x;
	float		world_y;
	float		world_x;
	t_point		position;
	t_ray		r1;
	t_ray		r2;
	t_intersect_list	*hit;
	t_intersect_list	*i_list;

	sp->material.color = color;
	sp->transform = mx_mult(sp->transform, transform);
    update_inverse(sp);
	y = 0;
	while (y < (WIN_HEIGHT - 1))
	{
		world_y = half - pixel_size * y;
		x = 0;
		while (x < (WIN_WIDTH -1))
		{
			i_list = NULL;
			world_x = -half + pixel_size * x;
			position = point(world_x, world_y, wall_z);
			r1 = ray(r_origin, tp_normalize(tp_subtract(position, r_origin)));
			r2 = transform_ray(r1, sp->inverse);
			i_list = generate_list_intersections(sp, r2);
			hit = dbl_lstgetone(&i_list, is_hit_positive);
			if (hit)
            {
				set_pixel_color(data, x, y, rgb_stoi(sp->material.color));
            }
			dbl_lstclear(&i_list, clear_intersection);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, data->mlx->img, 0, 0);
	destroy_shape(sp);
	return (0);
}

int	main(void)
{
	t_data	*data;
	t_m4x4	m;

	m = mx_scaling(1, 0.5, 1);
	m = mx_add_rotation(m, M_PI / 4, Z_AXIS);
	// m = mx_rotation(M_PI / 4, Z_AXIS);
	// m = mx_add_scaling(m, 1, 0.5, 1);
	// m = mx_add_shearing(m , (t_shear_params){1, 0, 0, 0, 0, 0});
	data = init_data();
	print_sp(point(0, 0, -5), m, data);
	set_hooks(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	printf("test mlx project template\n");
	return (0);
}