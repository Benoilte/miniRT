/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:34:16 by bebrandt          #+#    #+#             */
/*   Updated: 2024/08/16 17:36:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DBL_LST_H
# define FT_DBL_LST_H

typedef struct	s_dbl_lst
{
	void		*content;
	s_dbl_lst	*next;
	s_dbl_lst	*prev;
}	t_dbl_lst;

#endif