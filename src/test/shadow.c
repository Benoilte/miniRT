/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:44:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/09/05 08:53:31 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
​ 	​Scenario​: Lighting with the surface in shadow
​ 	  ​Given​ eyev ← vector(0, 0, -1)
​ 	    ​And​ normalv ← vector(0, 0, -1)
​ 	    ​And​ light ← point_light(point(0, 0, -10), color(1, 1, 1))
​ 	    ​And​ in_shadow ← true
​ 	  ​When​ result ← lighting(m, light, position, eyev, normalv, in_shadow)
​ 	  ​Then​ result = color(0.1, 0.1, 0.1)
 */

void	test_shadow(t_data *data)
{
	(void)data;
	printf("test_shadow\n");
}
