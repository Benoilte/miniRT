/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:44:36 by bebrandt          #+#    #+#             */
/*   Updated: 2024/10/23 01:45:31 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
	Added: RIGHT (D) LEFT (A) UP (E) and DOWN (Q) controls
	FORWARD (W) | BACK (S)
*/

void	print_movement(char *mode)
{
	print_bold_italic(TAB_TAB_PRESS_KEY, "W");
	ft_printf(" to move %s FORWARD\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "S");
	ft_printf(" to move %s BACKWARD\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "D");
	ft_printf(" to move %s RIGHT\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "A");
	ft_printf(" to move %s LEFT\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "E");
	ft_printf(" to move %s UP\n", mode);
	print_bold_italic(TAB_TAB_PRESS_KEY, "Q");
	ft_printf(" to move %s DOWN\n", mode);
}

/*
	YAW_LEFT = spin left
	YAW_RIGHT = spin right
	PITCH_UP = tilt up
	PITCH_DOWN = tilt down
	ROLL_LEFT = tilt left
	ROLL_RIGHT = tilt right

    YAW     :       LEFT (4) | RIGHT (6)
    PITCH   :       UP (8) | DOWN (5)
    ROLL    :       LEFT (7) | RIGHT (9)
*/

void	print_rotation(void)
{
	print_bold_italic(TAB_TAB_PRESS_NUM, "4");
	ft_printf(" to SPIN LEFT\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "6");
	ft_printf(" to SPIN RIGHT\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "8");
	ft_printf(" to TILT UP\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "5");
	ft_printf(" to TILT DOWN\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "7");
	ft_printf(" to TILT LEFT\n");
	print_bold_italic(TAB_TAB_PRESS_NUM, "9");
	ft_printf(" to TILT RIGHT\n");
}
