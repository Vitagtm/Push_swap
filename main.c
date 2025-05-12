#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int assign_sort(t_stack **a, t_stack **b)
{
    int len;

    if(!a || !(*a) || !(*a)->next)
        return 0;
    assign_indexes(*a);
    len = get_size(*a);
    if(len == 2)
        sort_two(a);
    else if(len == 3)
        sort_three(a);
    else if(len == 4 || len == 5)
        chiqui_sort(a, b);
    else
        k_sort(a, b, len);
}


int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    char **num;
    int i;

    a = NULL;
    b = NULL;
    i = 1;
    if(argc < 2)
        return (0);
    while(i < argc)
    {
        num = ft_split(argv[i], ' ');
        if(!num)
            ft_error("Error: ft_split espacios falló\n", &a);
        num = ft_split(argv[i], ',');
        if(!num)
            ft_error("Error: ft_split comas falló\n", &a);
        validate_num_array(num, &a);
        validate_range_len(num, &a);
        node_into_stack_and_null_parse(&a, num);
        free_array(num);
        i++;
    }
    check_dup_parse(&a);
    assign_sort(&a, &b);
    free_node(&a);
    return (0);
}