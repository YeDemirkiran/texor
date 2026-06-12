/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texor.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:31:52 by yademirk          #+#    #+#             */
/*   Updated: 2026/06/12 18:33:47 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXOR_H
# define TEXOR_H

# include <time.h>
# include <termios.h>

# define TEXOR_VERSION "0.0.1"
# define TEXOR_TAB_STOP 8
# define TEXOR_QUIT_TIMES 2

# define CTRL_KEY(k) ((k) & 0x1f)

typedef enum e_editor_key
{
	BACKSPACE = 127,
	ARROW_LEFT = 1000,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	DEL_KEY,
	HOME_KEY,
	END_KEY,
	PAGE_UP,
	PAGE_DOWN
}	t_editor_key;

typedef enum e_editor_highlight
{
	HL_NORMAL = 0,
	HL_COMMENT,
	HL_MLCOMMENT,
	HL_KEYWORD1,
	HL_KEYWORD2,
	HL_STRING,
	HL_NUMBER,
	HL_MATCH
}	t_editor_highlight;

#define HL_HIGHLIGHT_NUMBERS (1 << 0)
#define HL_HIGHLIGHT_STRINGS (1 << 1)

/*** data ***/

typedef struct s_editor_syntax
{
	char *file_type;
	char **file_match;
	char **keywords;
	char *singleline_comment_start;
	char *multiline_comment_start;
	char *multiline_comment_end;
	int flags;
}	t_editor_syntax;

typedef struct s_e_row
{
	int index;
	int size;
	int rendered_size;
	char *characters;
	char *rendered_characters;
	unsigned char *highlight;
	int highlight_open_comment;
} t_e_row;

typedef struct s_editor_config
{
	int				file_position_x;
	int				file_position_y;
	int				screen_position_x;
	int				row_offset;
	int				column_offset;
	int				screen_rows;
	int				screen_columns;
	int				number_of_rows;
	t_e_row			*row;
	int				dirty;
	char			*filename;
	char			status_message[80];
	time_t			status_message_time;
	t_editor_syntax	*syntax;
	struct termios	orig_termios;
}	t_editor_config;

#endif
