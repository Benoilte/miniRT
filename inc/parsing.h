/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:25:52 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/10 14:12:51 by bgolding         ###   ########.fr       */
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

# define INPUT_ERR_USAGE "Invalid input. Usage: ./miniRT <filename>"
# define INPUT_ERR_FILENAME "Invalid filename. Expected format: *.rt"
# define LX_INCOMPLETE "Unable to complete lexical analysis"

# define STR_AMBIENT "A"
# define STR_CAMERA "C"
# define STR_LIGHT "L"

# define STR_SPHERE "sp"
# define STR_PLANE "pl"
# define STR_CYLINDER "cy"

# define INPUT_ERROR_REPORT_LIMIT 50

# define ERRMSG_INVALID_ID "Invalid identifier"
# define ERRMSG_REAL_NUM "Invalid number detected"
# define ERRMSG_RATIO "Invalid ratio [0.0 - 1.0]"
# define ERRMSG_POS_NUM "Invalid number: expected positive number"
# define ERRMSG_UINT8 "Invalid 8-bit integer [0 - 255]"
# define ERRMSG_FOV "Invalid camera field of view [0 - 180]"
# define ERRMSG_DUPLICATE "Duplicate identifier (only one allowed)"

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

typedef enum e_error_code
{
	ERR_INVALID_ID,
	ERR_REAL_NUM,
	ERR_RATIO,
	ERR_POS_NUM,
	ERR_UINT8,
	ERR_FOV,
	ERR_DUPLICATE,
	ERR_CODE_LIMIT
}	t_error_code;

typedef struct t_token
{
	char	**args;
	t_id	identifier;
	int		line_number;
}			t_token;

typedef struct t_error
{
	int		error_type;
	int		line;
}			t_error;

typedef struct s_input_data
{
	int		fd;
	t_list	*token_list;
	t_list	*errors;
}			t_input_data;

//	PROTOTYPES

//	file_validation.c
int		validate_file(const char *filename, int *fd);

//	lexer.c
int		lexer(t_input_data *input);

//	tokenize.c
int		tokenize_line(t_list **token_list, char *line);

//	token_utils.c
int		tokenize_error(char *source);
t_token	*new_token(char *str, int line);
void	delete_token(void *token);

#endif