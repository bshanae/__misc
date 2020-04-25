#include "ftp_control_functions.h"

static void			ftp_ctrl_spc_functor_call(t_ftp_control *me)
{
	buffer_extern_in(&me->buffer);
	me->buffer.extern_end++;
	if (!ft_strncmp(me->buffer.extern_end, "func", 4))
		me->buffer.extern_end += 5;
	else if (!ft_strncmp(me->buffer.extern_end, "functor", 7))
		me->buffer.extern_end += 7;
	else
		me->buffer.extern_end++;
	while (is_space(me->buffer.extern_end))
		me->buffer.extern_end++;
	if (*me->buffer.extern_end == ':')
		me->buffer.extern_end++;
	while (is_space(me->buffer.extern_end))
		me->buffer.extern_end++;
	ftp_control_functor(me);
	while (*me->buffer.extern_end)
		if (*(me->buffer.extern_end++) == '}')
			break;
}

static void			ftp_ctrl_spc_color_call(t_ftp_control *me)
{
	buffer_extern_in(&me->buffer);
	me->buffer.extern_end++;
	if (!ft_strncmp(me->buffer.extern_end, "color", 5))
		me->buffer.extern_end += 5;
	else if (!ft_strncmp(me->buffer.extern_end, "col", 53))
		me->buffer.extern_end += 3;
	else
		me->buffer.extern_end++;
	while (is_space(me->buffer.extern_end))
		me->buffer.extern_end++;
	if (*me->buffer.extern_end == ':')
		me->buffer.extern_end++;
	while (is_space(me->buffer.extern_end))
		me->buffer.extern_end++;
	ftp_control_color(me);
	while (*me->buffer.extern_end)
		if (*(me->buffer.extern_end++) == '}')
			break;
}

void				ftp_control_special(t_ftp_control *me)
{
	if (me->buffer.extern_end[1] == 'c')
		ftp_ctrl_spc_color_call(me);
	else if (me->buffer.extern_end[1] == 'f')
		ftp_ctrl_spc_functor_call(me);
	else
	{
		buffer_custom_in_char(&me->buffer, '{', 1);
		me->buffer.extern_begin = me->buffer.extern_end++;
		return ;
	}
	me->buffer.extern_begin = me->buffer.extern_end;
}