#include <stdlib.h>
#include <stdio.h>

// /////////////////////////////////////////////////////////////////////////////
// 					STACK
// /////////////////////////////////////////////////////////////////////////////

typedef struct 		s_stack
{
	int				*data;
	int				capacity;
	int				length;
}					t_stack;

#define STACK_INIT_CAPACITY		16
#define STACK_ENLARGE_RATIO		2

t_stack				*stack_new()
{
	t_stack			*new;
	
	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = (int *)malloc(sizeof(int) * STACK_INIT_CAPACITY);
	new->capacity = STACK_INIT_CAPACITY;
	new->length = 0;
	return (new);
}

void				stack_delete(t_stack **stack)
{
	free((*stack)->data);
	free(*stack);
	*stack = NULL;
}

void				stack_enlarge(t_stack *stack)
{
	int				*buffer;
	
	buffer = (int *)malloc(sizeof(int) * stack->capacity * STACK_ENLARGE_RATIO);
	for (int i = 0; i < stack->length; i++)
		buffer[i] = stack->data[i];
	free(stack->data);
	stack->data = buffer;
	stack->capacity *= STACK_ENLARGE_RATIO;
}

void				stack_push(t_stack *stack, int item)
{
	if (stack->length == stack->capacity)
		stack_enlarge(stack);
	stack->data[stack->length++] = item;
}

int					stack_pop(t_stack *stack, int *destination)
{
	if (!stack->length)
		return (0);
	*destination = stack->data[--stack->length];
	return (1);
}

int					stack_is_empty(t_stack *stack)
{
	return (!stack->length);
}

void				stack_print(t_stack *stack)
{
	for (int i = 0; i < stack->length; i++)
		printf("[%d]", stack->data[i]);
	printf("\n");
}

// /////////////////////////////////////////////////////////////////////////////
// 					IS
// /////////////////////////////////////////////////////////////////////////////

int					is_space(const char *s)
{
	return (*s == ' ' || *s == '\n' || *s == '\t');
}

int					is_digit(const char *s)
{
	return (*s >= '0' && *s <= '9');
}

int					is_operator(const char *s)
{
	return (*s == '+' ||
			*s == '-' ||
			*s == '*' ||
			*s == '/' ||
			*s == '%');
}

// /////////////////////////////////////////////////////////////////////////////
// 					RPN
// /////////////////////////////////////////////////////////////////////////////

int					operator(const char *op, const int *left, const int *right)
{
	if (*op == '+')
		return (*left + *right);
	else if (*op == '-')
		return (*left - *right);
	else if (*op == '*')
		return (*left * *right);
	else if (*op == '/')
		return (*left / *right);
	else if (*op == '%')
		return (*left % *right);
	return (0);
}

#define ERROR		{ stack_delete(&stack); return (0); }

int					rpn_calc(const char *str)
{
	t_stack			*stack;
	int				left;
	int				right;
	int				result;
	int				space_ok;
	
	stack = stack_new();
	space_ok = 1;
	while (*str)
	{
		if (is_space(str))
			space_ok = 1;
		else if (is_digit(str))
		{
			if (!space_ok)
				ERROR
			else
				space_ok = 0;
			
			stack_push(stack, atoi(str));
			while (is_digit(++str));
			//stack_print(stack);
			continue ;
		}
		else if (is_operator(str))
		{
			if (!space_ok)
				ERROR
			else
				space_ok = 0;
			
			if (!stack_pop(stack, &right))
				ERROR
			if (!stack_pop(stack, &left))
				ERROR
			if (!right && (*str == '/' || *str == '%'))
				ERROR
			stack_push(stack, operator(str, &left, &right));
			//stack_print(stack);
		}
		else
			ERROR
		str++;
	}
	if (!stack_pop(stack, &result))
		ERROR
	if (!stack_is_empty(stack))
		ERROR
	printf("%d\n", result);
	return (1);
}
			
// /////////////////////////////////////////////////////////////////////////////
// 					MAIN
// /////////////////////////////////////////////////////////////////////////////


int					main(int argc, char **argv)
{
	if (argc == 2 && rpn_calc(argv[1]));
	else
		printf("Error\n");
	return (0);
}
