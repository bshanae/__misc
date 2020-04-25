/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vo_term_translate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:55:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:55:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vo.h"

static char		vo_term_translate_add_c(t_vo *vo, int key)
{
	if (key == KEY_0)
		return (vo->shift_mod ? ')' : '0');
	if (key == KEY_1)
		return ('1');
	if (key == KEY_2)
		return ('2');
	if (key == KEY_3)
		return ('3');
	if (key == KEY_4)
		return ('4');
	if (key == KEY_5)
		return ('5');
	if (key == KEY_6)
		return ('6');
	if (key == KEY_7)
		return ('7');
	if (key == KEY_8)
		return ('8');
	if (key == KEY_9)
		return (vo->shift_mod ? '(' : '9');
	if (key == KEY_TILDA && vo->shift_mod)
		return ('~');
	return ('*');
}

static char		vo_term_translate_add_b(t_vo *vo, int key)
{
	if (key == KEY_N)
		return ('n' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_M)
		return ('m' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_SPACE)
		return (' ');
	if (key == KEY_DOT)
		return ('.');
	if (key == KEY_SLASH)
		return ('/');
	if (key == KEY_MINUS_1)
		return (vo->shift_mod ? '_' : '-');
	return (vo_term_translate_add_c(vo, key));
}

static char		vo_term_translate_add_a(t_vo *vo, int key)
{
	if (key == KEY_W)
		return ('w' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_E)
		return ('e' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_R)
		return ('r' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_Y)
		return ('y' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_T)
		return ('t' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_O)
		return ('o' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_U)
		return ('u' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_I)
		return ('i' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_P)
		return ('p' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_L)
		return ('l' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_J)
		return ('j' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_K)
		return ('k' - (vo->shift_mod ? 32 : 0));
	return (vo_term_translate_add_b(vo, key));
}

char			vo_term_translate(t_vo *vo, int key)
{
	if (key == KEY_A)
		return ('a' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_S)
		return ('s' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_D)
		return ('d' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_F)
		return ('f' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_H)
		return ('h' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_G)
		return ('g' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_Z)
		return ('z' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_X)
		return ('x' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_C)
		return ('c' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_V)
		return ('v' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_B)
		return ('b' - (vo->shift_mod ? 32 : 0));
	if (key == KEY_Q)
		return ('q' - (vo->shift_mod ? 32 : 0));
	return (vo_term_translate_add_a(vo, key));
}
