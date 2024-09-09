/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:25:52 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/09 12:06:38 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include <fcntl.h>
# include <string.h>

//	INCLUDES

//	DEFINES

# define LX_SUFFIX ".rt"
# define LX_SUFFIX_LEN 3

# define LX_INVALID_PTR "invalid (null) pointer passed as argument"
# define LX_INVALID_FILENAME "invalid filename. Expected format: *.rt"
# define LX_INCOMPLETE "unable to complete lexical analysis"

# define STR_AMBIENT "A"
# define STR_CAMERA "C"
# define STR_LIGHT "L"

# define STR_SPHERE "sp"
# define STR_PLANE "pl"
# define STR_CYLINDER "cy"

//	TYPEDEFS

typedef enum e_info
{
	INFO_ID,
	INFO_LIGHT,
	INFO_COLOR,
	INFO_COORD,
	INFO_NORM_VECTOR,
	INFO_FOV,
	INFO_SIZE
}	t_info;

typedef enum e_id
{
	ID_INVALID = -1,
	ID_AMBIENT,
	ID_CAMERA,
	ID_LIGHT,
	ID_SPHERE,
	ID_PLANE,
	ID_CYLINDER,
	ID_VALID_COUNT,
}	t_id;

typedef enum e_value_type
{
	VT_REAL_NUM,
	VT_RATIO,
	VT_POS_NUM,
	VT_UINT8,
	VT_FOV
}	t_value_type;

typedef struct t_token
{
	char	**args;
	t_id	identifier;
	int		line_number;
}			t_token;

//	PROTOTYPES

//	file_validation.c
int		validate_file(const char *filename, int *fd);

//	lexer.c
int		lexer(int fd, t_list **token_list);

//	tokenize.c
int		tokenize_line(t_list **token_list, char *line);
int		tokenize_error(char *source);
void	delete_token(void *token);

#endif