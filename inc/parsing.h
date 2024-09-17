/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:25:52 by bgolding          #+#    #+#             */
/*   Updated: 2024/09/17 22:13:01 by bgolding         ###   ########.fr       */
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

# define INPUT_ERR_USAGE	"Invalid input. Usage: ./miniRT <filename>"
# define INPUT_ERR_FILENAME "Invalid filename. Expected format: *.rt"
# define LX_INCOMPLETE 		"Unable to complete lexical analysis"
# define SYN_CHK_INCOMPLETE	"Unable to complete syntax check"
# define SYN_CHK_ERROR		"Syntax error(s) detected"
# define WORLD_ERROR_AMB	"Missing Ambient element (A)"
# define WORLD_ERROR_CAM	"Missing Camera element (C)"
# define WORLD_ERROR_LIGHT	"Missing Light element (L)"
# define WORLD_ERROR_SHAPE	"No shapes in world: must have at least 1"

# define STR_AMBIENT	"A"
# define STR_CAMERA		"C"
# define STR_LIGHT		"L"

# define STR_SPHERE		"sp"
# define STR_PLANE		"pl"
# define STR_CYLINDER	"cy"

# define AMBIENT_PARAMS		2
# define CAMERA_PARAMS 		3
# define LIGHT_PARAMS 		3
# define SPHERE_PARAMS 		3
# define PLANE_PARAMS 		3
# define CYLINDER_PARAMS	5

# define INPUT_ERROR_REPORT_LIMIT 50

# define ERRMSG_INVALID_ID 		"Invalid identifier"
# define ERRMSG_REAL_NUM 		"Invalid number format detected"
# define ERRMSG_RATIO 			"Invalid ratio [0.0 .. 1.0]"
# define ERRMSG_POS_NUM 		"Invalid number: expected positive number"
# define ERRMSG_COLOR 			"Invalid color [R,G,B ints in range [0 .. 255]]"
# define ERRMSG_FOV 			"Invalid camera field of view [0 .. 180]"
# define ERRMSG_DUPLICATE 		"Duplicate identifier (only one allowed)"
# define ERRMSG_VECTOR_RANGE	"Invalid vector element range [-1 .. 1]"
# define ERRMSG_RANGE_EXCESS 	"Value exceeds permitted range"
# define ERRMSG_ARG_MISSING 	"Missing parameter(s) for element"
# define ERRMSG_ARG_EXCESS		 "Too many parameters for element"
# define ERRMSG_VECTOR_ZERO		"Invalid vector: all zero values"

# define RANGE_MIN			-1000
# define RANGE_MAX			1000
# define FOV_MIN			0
# define FOV_MAX			180
# define VECTOR_RANGE_MIN	-1
# define VECTOR_RANGE_MAX	1
# define SHAPE_SIZE_MIN		0.1
# define SHAPE_SIZE_MAX		1000
# define COLOR_MIN			0
# define COLOR_MAX			255

//	TYPEDEFS

typedef enum e_info
{
	INFO_BRIGHTNESS,
	INFO_COLOR,
	INFO_COORD,
	INFO_VECTOR,
	INFO_FOV,
	INFO_SIZE,
	INFO_COUNT
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
	ERR_COLOR,
	ERR_FOV,
	ERR_DUPLICATE,
	ERR_VECTOR_RANGE,
	ERR_RANGE_LIMIT,
	ERR_ARG_MISSING,
	ERR_ARG_EXCESS,
	ERR_VECTOR_ZERO,
	ERR_CODE_LIMIT
}	t_error_code;

typedef struct t_token
{
	char	**args;
	t_id	identifier;
	int		line;
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

typedef int	(*t_validate_token)(t_token *, t_list **);
typedef int	(*t_validate_str)(const char *, int, t_list **);

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
void	free_args(char ***args);

//	parser.c
int		parser(t_input_data *input);

//	validate_single_element.c
int		validate_ambient(t_token *token, t_list **errors);
int		validate_camera(t_token *token, t_list **errors);
int		validate_light(t_token *token, t_list **errors);

//	validate_shape.c
int		validate_sphere(t_token *token, t_list **errors);
int		validate_plane(t_token *token, t_list **errors);
int		validate_cylinder(t_token *token, t_list **errors);

//	validate_info_1.c
int		validate_brightness(const char *str, int line, t_list **errors);
int		validate_color(const char *str, int line, t_list **errors);
int		validate_coordinate(const char *str, int line, t_list **errors);
int		validate_vector(const char *str, int line, t_list **errors);
int		validate_fov(const char *str, int line, t_list **errors);
int		validate_size(const char *str, int line, t_list **errors);

//	validate_utils.c
int		is_real_num(const char *str);
int		only_digits(const char *str);
int		in_range(float num, float min, float max);
int		validate_info(const char *str, int line, t_info info, t_list **errors);
int		count_args(const char **args);

#endif