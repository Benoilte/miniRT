/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:25:52 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/17 07:49:30 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//	INCLUDES

# include "libft.h"
# include "error_handling.h"
# include <fcntl.h>
# include <string.h>

//	DEFINES

# define LX_SUFFIX 		".rt"
# define LX_SUFFIX_LEN 	3

# define STR_AMBIENT			"A"
# define STR_CAMERA				"C"
# define STR_LIGHT				"L"

# define STR_DEFAULT_MATERIAL	"M"
# define STR_RESOLUTION			"R"
# define STR_DEPTH				"D"
# define STR_A_ALIASING			"AA"

# define STR_SPHERE		"sp"
# define STR_PLANE		"pl"
# define STR_CYLINDER	"cy"
# define STR_CUBE		"cu"

# define AMBIENT_PARAMS		2
# define CAMERA_PARAMS 		3
# define LIGHT_PARAMS 		3

# define MATERIAL_PARAMS	6
# define RESOLUTION_PARAMS	2
# define DEPTH_PARAMS		2
# define A_ALIASING_PARAMS	1

# define SPHERE_PARAMS 		3
# define PLANE_PARAMS 		3
# define CYLINDER_PARAMS	5
# define CUBE_PARAMS		6

# define WORLD_SHAPE_LIMIT			70
# define INPUT_ERROR_REPORT_LIMIT	50

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
# define RATIO_MIN			0
# define RATIO_MAX			1
# define SHININESS_MIN		10
# define SHININESS_MAX		200
# define TRANSPARENCY_MIN	0
# define TRANSPARENCY_MAX	1
# define REFRACT_INDEX_MIN	1
# define REFRACT_INDEX_MAX	3
# define RES_RANGE_W_MIN	640
# define RES_RANGE_W_MAX	3200
# define RES_RANGE_H_MIN	480
# define RES_RANGE_H_MAX	1800
# define DEPTH_RANGE_MIN	1
# define DEPTH_RANGE_MAX	20
# define A_A_RANGE_MIN		0
# define A_A_RANGE_MAX		2

//	TYPEDEFS

typedef enum e_info
{
	INFO_BRIGHTNESS,
	INFO_COLOR,
	INFO_COORD,
	INFO_VECTOR,
	INFO_FOV,
	INFO_SIZE,
	INFO_DIFFUSE,
	INFO_SPECULAR,
	INFO_SHININESS,
	INFO_REFLECTIVE,
	INFO_TRANSPARENCY,
	INFO_REFRACT_INDEX,
	INFO_WIN_WIDTH,
	INFO_WIN_HEIGHT,
	INFO_DEPTH,
	INFO_A_ALIASING,
	INFO_COUNT
}	t_info;

typedef enum e_id
{
	ID_INVALID = -1,
	ID_AMBIENT,
	ID_CAMERA,
	ID_LIGHT,
	ID_MATERIAL,
	ID_RESOLUTION,
	ID_DEPTH,
	ID_A_ALIASING,
	ID_SPHERE,
	ID_PLANE,
	ID_CYLINDER,
	ID_CUBE,
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
	int		line;
}			t_token;

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

//	validate_single_element_1.c
int		validate_ambient(t_token *token, t_list **errors);
int		validate_camera(t_token *token, t_list **errors);
int		validate_light(t_token *token, t_list **errors);

//	validate_single_element_2.c
int		validate_default_material(t_token *token, t_list **errors);
int		validate_resolution(t_token *token, t_list **errors);
int		validate_depth(t_token *token, t_list **errors);
int		validate_a_aliasing(t_token *token, t_list **errors);

//	validate_shape.c
int		validate_sphere(t_token *token, t_list **errors);
int		validate_plane(t_token *token, t_list **errors);
int		validate_cylinder(t_token *token, t_list **errors);
int		validate_cube(t_token *token, t_list **errors);

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

//	validate_bonus.c
int		validate_material_parameters(char **args, int line, t_list **errors);
int		validate_resolution_parameters(char **args, int line, t_list **errors);
int		validate_depth_parameters(char **args, int line, t_list **errors);
int		validate_a_aliasing_parameters(char **args, int line, t_list **errors);

//	validate_bonus_info_1.c
int		validate_diffuse(const char *str, int line, t_list **errors);
int		validate_specular(const char *str, int line, t_list **errors);
int		validate_shininess(const char *str, int line, t_list **errors);
int		validate_reflective(const char *str, int line, t_list **errors);
int		validate_a_aliasing_value(const char *str, int line, t_list **errors);

//	validate_bonus_info_2.c
int		validate_transparency(const char *str, int line, t_list **errors);
int		validate_refraction_index(const char *str, int line, t_list **errors);
int		validate_window_width(const char *str, int line, t_list **errors);
int		validate_window_height(const char *str, int line, t_list **errors);
int		validate_depth_value(const char *str, int line, t_list **errors);

#endif
