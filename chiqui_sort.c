#include "push_swap.h"
#include <stdio.h>
t_stack* get_min(t_stack *a)
{
    t_stack *min;

    if(!a)
        return NULL;
    min = a;
    while(a)
    {
        if(a->index < min->index)
            min = a;
        a = a->next;
    }
    return(min);
}
int get_position(t_stack *a, int index)
{
	int pos = 0;
	while (a)
	{
		if (a->index == index)
			break;
		pos++;
		a = a->next;
	}
	return (pos);
}
int get_size(t_stack *a)
{
	int size = 0;
	while (a)
	{
		size++;
		a = a->next;
	}
	return size;
}

void rotate_to_top(t_stack **a, int index)
{
	int pos = get_position(*a, index);
	int size = get_size(*a);

    if(pos == 0)
        return;
	if (pos <= size / 2)
		while ((*a)->index != index)
			rotate_a(a);
	else
		while ((*a)->index != index)
			rrotate_a(a);
}

void chiqui_sort(t_stack **a, t_stack **b)
{
    int size;
    t_stack *min;
    t_stack *current;
    size = get_size(*a);
    while(size > 3)
    {
        min = get_min((*a));
        if(!min)
            break;
        rotate_to_top(a, min->index);
        push_b(a, b);
        size--;
    }
    sort_three(a);
    while (*b)
        push_a(a, b);
}