#include "push_swap.h"
int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}
void move_to_b(t_stack **a, t_stack **b, int number)
{
    int i;
    int range;
    range = ft_sqrt(number) * 1,4;
    i = 0;

    while(*a)
    {
        if((*a)->index <= i)
        {
            push_b(a, b);
            if(get_size((*b)) > 1)
                rotate_b(b);
            i++;
        }
        else if((*a)->index <= i + range)
        {
            push_b(a, b);
            i++;
        }
        else
            rotate_a(a);
    }
}

int count_rot(t_stack *stack, int max_pos)
{
    int count;
    count = 0;
    while(stack != NULL && stack->index != max_pos)
    {
        stack = stack->next;
        count++;
    }
    return(count);
}
void k_sort(t_stack **a, t_stack **b, int number)
{
    int rb_count;
    int rrb_count;
    int num;
    int size;
    num = number -1; //permite pillar el número más alto hasta el momento por índice, por eso el -1.

    move_to_b(a, b, number);
    while((num) >= 0)
    {
        size = (get_size(*b));
        rb_count = count_rot(*b, num);
        rrb_count = size - rb_count;
        if(rb_count <= rrb_count)
        {
            while((*b)->index != num)
            {
                rotate_b(b);
            }
            push_a(a, b);
            num--;
        }
        else
        {
            while((*b)->index != num)
                rrotate_b(b);
            push_a(a, b);
            num--;
        }
    }
}