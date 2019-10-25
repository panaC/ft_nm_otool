/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:19:26 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 21:45:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>

# define STR_FORMAT_CHAR "sSpdDioOuUxXcC%"

typedef enum		e_length
{
	code_none = 1,
	code_hh,
	code_h,
	code_l,
	code_ll,
	code_j,
	code_z
}					t_length;

typedef struct		s_format
{
	t_bool			attr_dieze;
	t_bool			attr_0;
	t_bool			attr_plus;
	t_bool			attr_moins;
	t_bool			attr_space;
	int				length_field;
	int				precision;
	t_length		length_type;
	char			op;
	va_list			arg;
	int				val_ret;
	t_bool			flag_pc;
}					t_format;

int					ft_vasprintf(char **ret, const char *s, va_list ap);
int					ft_printf(const char *s, ...);
int					ft_sprintf(char **str, const char *s, ...);
int					search_next_format(const char *s);
char				*fill_length_param(char *s, char car, t_bool is_left,
		size_t size);
t_format			*init_struct(void);

#endif
