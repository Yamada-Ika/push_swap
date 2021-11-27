#include "push_swap.h"

int	main(void)
{
	int		array[] = {8,5,6,3,1,2};
	size_t	array_size = 6;
	t_bilist	*stack_a;
	t_bilist	*stack_b;

	stack_a = ft_create_stack(array, array_size);
	stack_b = ft_create_stack(NULL, 0);

	// init
	ft_print_sepline();
	printf("a :");
	ft_print_stack(stack_a);
	printf("b :");
	ft_print_stack(stack_b);
	ft_print_sepline();

	// swap a
	ft_swap(stack_a);
	ft_print_sepline();
	printf("a :");
	ft_print_stack(stack_a);
	printf("b :");
	ft_print_stack(stack_b);
	ft_print_sepline();

	// push b x 3
	ft_push(stack_b, stack_a);
	ft_push(stack_b, stack_a);
	ft_push(stack_b, stack_a);
	ft_print_sepline();
	printf("a :");
	ft_print_stack(stack_a);
	printf("b :");
	ft_print_stack(stack_b);
	ft_print_sepline();

	// rr
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_print_sepline();
	printf("a :");
	ft_print_stack(stack_a);
	printf("b :");
	ft_print_stack(stack_b);
	ft_print_sepline();

	// rrr
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_print_sepline();
	printf("a :");
	ft_print_stack(stack_a);
	printf("b :");
	ft_print_stack(stack_b);
	ft_print_sepline();

	// sa
	ft_swap(stack_a);
	ft_print_sepline();
	printf("a :");
	ft_print_stack(stack_a);
	printf("b :");
	ft_print_stack(stack_b);
	ft_print_sepline();

	// push a x 3
	ft_push(stack_a, stack_b);
	ft_push(stack_a, stack_b);
	ft_push(stack_a, stack_b);
	ft_print_sepline();
	printf("a :");
	ft_print_stack(stack_a);
	printf("b :");
	ft_print_stack(stack_b);
	ft_print_sepline();
}
