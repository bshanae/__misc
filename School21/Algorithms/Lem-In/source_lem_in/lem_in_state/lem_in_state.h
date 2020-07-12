/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_state.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:43:51 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STATE_H
# define LEM_IN_STATE_H

typedef enum		e_lem_in_state
{
	lem_in_not_seen = 0,
	lem_in_seen,
	lem_in_visited
}					t_lem_in_state;

#endif
