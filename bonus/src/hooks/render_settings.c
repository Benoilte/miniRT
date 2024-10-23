/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:48:15 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/23 09:57:30 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	increment_anti_aliasing(t_render *r)
{
	const int	wrap = A_A_RANGE_MAX + 1;

	r->master_aa_precision = (r->master_aa_precision + 1) % wrap;
	ft_printf("Anti aliasing [0|1|2] set to : %d\n", r->master_aa_precision);
}

static void	increment_reflective_depth(t_render *r)
{
	const int	wrap = DEPTH_RANGE_MAX + 1;

	r->master_reflective_depth = (r->master_reflective_depth + 1) % wrap;
	ft_printf("Reflective depth [0..20] set to : %d\n", \
				r->master_reflective_depth);
}

static void	increment_refractive_depth(t_render *r)
{
	const int	wrap = DEPTH_RANGE_MAX + 1;

	r->master_refractive_depth = (r->master_refractive_depth + 1) % wrap;
	ft_printf("Refractive depth [0..20] set to : %d\n", \
				r->master_refractive_depth);
}

static void	update_render_blocks(t_render *render)
{
	int	i;

	i = 0;
	while (i < render->thread_count)
	{
		render->blocks[i].aa_sample_precision = render->master_aa_precision;
		render->blocks[i].reflective_depth = render->master_reflective_depth;
		render->blocks[i].refractive_depth = render->master_refractive_depth;
		i++;
	}
}

int	apply_render_settings_control(int keycode, t_render *render)
{
	if (keycode == A_KEY)
		increment_anti_aliasing(render);
	else if (keycode == Q_KEY)
		increment_reflective_depth(render);
	else if (keycode == W_KEY)
		increment_refractive_depth(render);
	else
		return (1);
	update_render_blocks(render);
	return (0);
}
