/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:57:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/02 19:40:37 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_list_error(t_intersect_list **list)
{
	dbl_lstclear(list, clear_intersection);
	exit(EXIT_FAILURE);
}

static int    add_intersects_to_list(t_intersect_list **list,\
									t_intersect_report report,\
									t_shape *shape)
{
	t_intersection        *new_intersect;
	t_intersect_list    *new_node;

	new_intersect = new_intersection(shape, report.t[report.count]);
	if (!new_intersect)
	{
		perror("add_intersects_to_list");
		return (1);
	}
	new_node = dbl_lstnew(new_intersect);
	if (!new_node)
	{
		perror("add_intersects_to_list");
		free(new_intersect);
		return (2);
	}
	dbl_lstadd_ordered(list, new_node, add_new_before_lst);
	return (0);
}

static t_ray    transform_ray(t_ray *r, t_m4x4 m)
{
	return (ray(mx_mult_tuple(m, r->origin), mx_mult_tuple(m, r->direction)));
}

t_intersect_list    *get_ray_intersections(t_ray *r, t_shape_list *nodes)
{
	t_intersect_list	*intersect_list;
	t_shape				*shape;
	t_intersect_report	report;
	t_ray				transformed_ray;

	intersect_list = NULL;
	while (nodes)
	{
		shape = (t_shape *)nodes->content;
		transformed_ray = transform_ray(r, shape->inverse);
		if (shape->f->intersect(&transformed_ray, shape, &report))
		{
			while (report.count--)
				if (add_intersects_to_list(&intersect_list, report, shape) != 0)
					intersect_list_error(&intersect_list);
			ft_bzero(&report, sizeof(report));
		}
		nodes = nodes->next;
	}
	return (intersect_list);
}

t_color	color_at(t_world *world, t_ray *ray)
{
	t_intersect_list	*intersects;
	t_intersect_list	*first_hit;
	t_color				color;
	t_intersect_details	details;

	intersects = get_ray_intersections(ray, world->shapes);
	first_hit = dbl_lstgetone(&intersects, is_hit_positive);
	if (!first_hit)
		color = rgb_set(0, 0, 0);
	else
	{
		details = set_intersect_details(first_hit->content, *ray);
		color = lighting(&details, world->light);
	}
	dbl_lstclear(&intersects, clear_intersection);
	return (color);	
}

void render_draft(t_data *data)
{
	int		x;
	int 	y;
	t_ray	ray;
	t_color	color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			ray = ray_for_pixel(*data->camera, x, y);
			color = color_at(data->world, &ray);
			set_pixel_color(data, x, y, rgb_stoi(color));
			y++;
		}
		x++;
	}
}

void change_shape(void *self)
{
	t_shape	*shape = (t_shape *)self;

	shape->transform = mx_translation(-10, 0, 0);
	update_inverse(shape);
	shape->material.color = rgb_itos(CYAN);
}

void	render(t_data *data)
{
	t_point	from = point(0, 0, -15);
	t_point to = point(0, 0, 0);
	t_vector up = vector(0, 1, 0);
	
	reset_image(data);
	add_new_shape_to_world(data->world, SPHERE);
	change_shape(data->world->shapes->content);
	data->camera->transform = view_transform(from, to, up);
	data->camera->transform_inverse = mx_inversion(data->camera->transform);
	render_draft(data);
	mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, \
							data->mlx->img, 0, 0);
}
