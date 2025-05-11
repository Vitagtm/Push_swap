#include "push_swap.h"
void basic_push(t_stack **stack1, t_stack **stack2)
{
    t_stack *temp;
    if(!stack1 || !(*stack1))
        return ;
    temp = (*stack1);
    (*stack1) = temp->next;
    temp->next = (*stack2);
    *(stack2) = temp;  
}
void push_a(t_stack **a, t_stack **b)
{
    basic_push(b, a);
    write(1, "pa\n", 3);
}
void push_b(t_stack **a, t_stack **b)
{
    basic_push(a, b);
    write(1, "pb\n", 3);
}
