/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_whitespaces.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:43:36 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/17 14:43:36 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_WHITESPACES_H
# define FTP_WHITESPACES_H

# include "ftp_buffer_main.h"

typedef struct	s_ftp_whitespaces
{
	int			prec_num;
	int			wid_num;
	char		wid_type;
}				t_ftp_whitespaces;

#endif
