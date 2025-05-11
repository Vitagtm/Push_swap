#include "push_swap.h"
void basic_rrotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *last;
    if(!stack || !(*stack) || !(*stack)->next)
        return;
    temp = (*stack);
    while(temp->next->next != NULL)
        temp = temp->next;
    last = temp->next;
    temp->next = NULL;
    last->next = (*stack);
    (*stack) = last; 
}
void rrotate_a(t_stack **a)
{
    basic_rrotate(a);
    write(1, "rra\n", 4);
}
void rrotate_b(t_stack **b)
{
    basic_rrotate(b);
    write(1, "rrb\n", 4);
}
void rrotate_ab(t_stack **a, t_stack **b)
{
   basic_rrotate(a);
   basic_rrotate(b); 
   write(1, "rrr\n", 4);
}