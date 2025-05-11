#include "push_swap.h"
void basic_rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *first;

    if(!stack || !(*stack) || !(*stack)->next)
        return;
    first = (*stack);
    *stack = (*stack)->next;
    temp =(*stack);
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = first;
    first->next = NULL;
}
void rotate_a(t_stack **a)
{
    basic_rotate(a);
    write(1, "ra\n", 3);
}
void rotate_b(t_stack **b)
{
    basic_rotate(b);
    write(1, "rb\n", 3);
}
void rotate_ab(t_stack **a, t_stack **b)
{
    basic_rotate(a);
    basic_rotate(b);
    write(1, "rr\n", 3);
}
