/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:48:51 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/09 15:04:06 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

/*
​ 	​function​ local_intersect(ray, plane)
​ 	  ​if​ abs(ray.direction.y) < EPSILON
​ 	    ​return​ () ​# empty set -- no intersections​
​ 	  ​end​ ​if​
​ 	
​ 	  t ← -ray.origin.y / ray.direction.y
​ 	  ​return​ ( intersection(t, plane) )
​ 	​end​ ​function
*/

bool	intersect_plane(t_ray *ray, t_shape *shape, t_report *report)
{
    if (!ray || !shape || !report)
		return (false);
    if (fabsf(ray->direction.y) < EPSILON)
        return (false);
    report->t[0] = -ray->origin.y / ray->direction.y;
    report->count = 1;
    return (true);
}
