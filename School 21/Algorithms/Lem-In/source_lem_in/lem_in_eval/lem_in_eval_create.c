/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_eval_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:38:00 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_eval.h"

static void			case_one(t_lem_in_eval *eval)
{
	eval->distribution = vector_create(sizeof(int));
	vector_push(&eval->distribution, &eval->number_of_ants);
	eval->cost = *(int *)vector_front(eval->array) + eval->number_of_ants - 2;
}

static void			helper_cost(t_lem_in_eval *eval, int *cost_delta,
		int *cost_alt, int *cost_floor)
{
	int				i;
	int				cost_sum;

	i = 0;
	cost_sum = eval->number_of_ants;
	while (i < (int)eval->array->length)
		cost_sum += *(int *)vector_at(eval->array, i++) - 2;
	*cost_floor = (int)floor((double)cost_sum / eval->array->length);
	*cost_delta = cost_sum - *cost_floor * (int)eval->array->length;
	*cost_alt = *cost_delta ? *cost_floor + 1 : *cost_floor;
}

static void			case_multiple(t_lem_in_eval *eval)
{
	int				i;
	int				cost_delta;
	int				cost_floor;
	int				cost_alt;
	int				cost_temp;

	eval->distribution = vector_create(sizeof(int));
	helper_cost(eval, &cost_delta, &cost_alt, &cost_floor);
	i = 0;
	while (i < eval->array->length)
	{
		cost_temp = cost_delta-- > 0 ? cost_alt : cost_floor;
		cost_temp -= *(int *)(vector_at(eval->array, i++));
		cost_temp += 2;
		vector_push(&eval->distribution, &cost_temp);
	}
	eval->cost = cost_alt;
}

t_lem_in_eval		lem_in_eval_create(t_vector *array, int number_of_ants)
{
	t_lem_in_eval	eval;

	eval.is_valid = array != NULL;
	if (!eval.is_valid)
		return (eval);
	eval.array = array;
	eval.number_of_ants = number_of_ants;
	if (eval.array->length == 1)
		case_one(&eval);
	else
		case_multiple(&eval);
	return (eval);
}
