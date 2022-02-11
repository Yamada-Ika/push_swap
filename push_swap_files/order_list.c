#include "push_swap.h"
#include "stack.h"

void	ft_add_order_list(t_order_list *order_list, t_order_kind kind)
{
	t_order_list	*new;

	new = (t_order_list *)ft_calloc(1, sizeof(t_order_list));
	new->order_kind = kind;
	ft_add_bilist((t_stack *)order_list, (t_stack *)new);
}
