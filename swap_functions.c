#include "push_swap.h"
void basic_swap(t_stack **stack)
{ 
    int temp;

    if(!stack || !(*stack) || !(*stack)->next)
        return ;
    temp = (*stack)->data;
    (*stack)->data = (*stack)->next->data;
    (*stack)->next->data = temp;

}
void swap_a(t_stack **a)
{
    basic_swap(a);
    write(1, "sa\n", 3);

}
void swap_b(t_stack **b)
{
    basic_swap(b);
    write(1, "sb\n", 3);

}
void swap_ab(t_stack **a, t_stack **b)
{
    basic_swap(a);
    basic_swap(b);
    write(1, "ss\n", 3);

}