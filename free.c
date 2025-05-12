#include "push_swap.h"
#include <stdlib.h>
void ft_putstr(char * str)
{
    int i;
    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
int free_node(t_stack **stack)
{
    t_stack *temp;
    while(*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);

    }
    *stack = NULL;
}
int ft_error(char *str, t_stack **stack)
{
    if(stack != NULL)
        free_node(stack);
    ft_putstr("Error");
    ft_putstr("\n");
    exit(EXIT_FAILURE);
}
int free_array(char **array)
{
    int i;
    i = 0;
    while(array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}