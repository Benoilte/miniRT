/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:52:04 by bgolding          #+#    #+#             */
/*   Updated: 2024/10/08 09:18:05 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

//	INCLUDES

# include "forward_declarations.h"
# include "minirt.h"

//	DEFINES

# define INVALID_POINTER "invalid (null) pointer passed as argument"

# define CORE_COUNT_ERROR \
"Unable to detect online cpu cores : using default setting"

# define RES_RENDER_WARN	"Warning: Resolution height not optimal"

# define INPUT_ERR_USAGE	"Invalid input. Usage: ./miniRT <filename>"
# define INPUT_ERR_FILENAME "Invalid filename. Expected format: *.rt"
# define LX_INCOMPLETE 		"Unable to complete lexical analysis"
# define SYN_CHK_INCOMPLETE	"Unable to complete syntax check"
# define SYN_CHK_ERROR		"Syntax error(s) detected"
# define WORLD_ERROR_AMB	"Missing Ambient element (A)"
# define WORLD_ERROR_CAM	"Missing Camera element (C)"
# define WORLD_ERROR_LIGHT	"Missing Light element (L)"
# define WORLD_ERROR_SHAPE	"No shapes in world: must have at least 1"
# define WORLD_ERROR_LIMIT	"Too many shapes in world"

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
# define ERRMSG_ARG_EXCESS		"Too many parameters for element"
# define ERRMSG_VECTOR_ZERO		"Invalid vector: all zero values"
# define ERRMSG_B_MAT_ARG_MISS	"Missing paremeter(s) for material (bonus)"
# define ERRMSG_B_SHINE_RANGE	"Invalid shininess range [10 .. 200]"
# define ERRMSG_B_REFRACT_IDX	"Invalid refraction index range [1 .. 3]"
# define ERRMSG_RES_FORMAT		"Invalid resolution format detected"
# define ERRMSG_RES_WIDTH		"Invalid resolution width [640 .. 2048]"
# define ERRMSG_RES_HEIGHT		"Invalid resolution height [480 .. 1536]"

//	TYPEDEFS

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
	ERR_MAT_ARG_MISSING,
	ERR_B_SHINE_RANGE,
	ERR_B_REFRACT_IDX,
	ERR_RES_FORMAT,
	ERR_RES_WIDTH,
	ERR_RES_HEIGHT,
	ERR_CODE_LIMIT
}	t_error_code;

typedef struct t_error
{
	int		error_type;
	int		line;
}			t_error;

//	PROTOTYPES

//	error.c
int		print_error(const char *source, const char *msg);
void	exit_error(t_data *data, char *message);

//	input_error.c
int		input_error(t_input_data *input, const char *source, const char *msg);
int		log_error(t_list **errors, int type, int line);

#endif