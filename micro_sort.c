#include "push_swap.h"
void sort_two(t_stack **a)
{
    if(!a || !(*a) || !(*a)->next)
        return ;
    if((*a)->index > (*a)->next->index)
        swap_a(a);
}

void sort_three(t_stack **a)
{
    int first = (*a)->index;
    int second = (*a)->next->index;
    int third = (*a)->next->next->index;

    if (first > second && second < third && first < third)
        swap_a(a); 
    else if (first > second && second > third)
    {
        swap_a(a); 
        rrotate_a(a);
    }
    else if (first > second && second < third && first > third)
        rotate_a(a); 
    else if (first < second && second > third && first < third)
    {
        swap_a(a); 
        rotate_a(a);
    }
    else if (first < second && second > third && first > third)
        rrotate_a(a); 
}
