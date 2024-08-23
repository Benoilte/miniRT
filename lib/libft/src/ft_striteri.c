/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:06:34 by bgolding          #+#    #+#             */
/*   Updated: 2023/11/14 09:53:21 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Applies the function 'f' to each character of the string passed as an argument, 
	passing its index as first argument. Each character is passed by address to 'f' 
	to be modified if necessary.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
