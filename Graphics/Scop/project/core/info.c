/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:49:02 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:49:03 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void				info(void)
{
	printf("\nControls : \n");
	printf("return - start/stop model mod\n");
	printf("p - switch polygon mod\n");
	printf("1 - use colors interpolated between model's minimum and maximum\n");
	printf("2 - use random color on each vertex\n");
	printf("3 - use model's material\n");
	printf("4 - use kitty texture\n");
	printf("\nCamera controls : \n");
	printf("a/d/w/s/q/e - move\n");
	printf("arrows - rotate\n");
	printf("r - start/stop rotation\n");
	printf("\nModel controls : \n");
	printf("a/d/w/s/q/e - move\n");
	printf("arrows or j/l/i/k/u/o - rotate\n");
}
