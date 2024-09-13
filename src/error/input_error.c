/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:16:41 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/12 12:33:22 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	report_error(void *error_node)
{
	const char	*msg[ERR_CODE_LIMIT] = {\
	ERRMSG_INVALID_ID, ERRMSG_REAL_NUM, ERRMSG_RATIO, ERRMSG_POS_NUM, \
	ERRMSG_COLOR, ERRMSG_FOV, ERRMSG_DUPLICATE, ERRMSG_VECTOR_RANGE, \
	ERRMSG_RANGE_EXCESS, ERRMSG_ARG_MISSING, ERRMSG_ARG_EXCESS};
	t_error		*error;

	if (!error_node)
		return ;
	error = (t_error *)error_node;
	ft_printf("\tLine\t%d\t:\t", error->line);
	if (error->error_type >= 0 && error->error_type < ERR_CODE_LIMIT)
		ft_printf("%s\n", msg[error->error_type]);
	else
		ft_printf("unknown error code\n");
}

int	input_error(t_input_data *input, const char *source, const char *msg)
{
	print_error(source, msg);
	if (input)
		ft_lstiter(input->errors, report_error);
	return (1);
}

int	log_error(t_list **errors, int type, int line)
{
	t_error	*new;
	t_list	*node;

	if (!errors)
		return (-1);
	new = ft_calloc(1, sizeof(t_error));
	if (!new)
		return (-1);
	new->error_type = type;
	new->line = line;
	node = ft_lstnew(new);
	if (!node)
	{
		free(new);
		return (-1);
	}
	ft_lstadd_back(errors, node);
	return (1);
}
