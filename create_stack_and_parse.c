#include "push_swap.h"
t_stack *new_node(int data)
{
    t_stack *node;
    node = malloc(sizeof(t_stack));
    if(!node)
        return(NULL);
    node->data = data;
    node->index = -1;
    node->next = NULL;
    return (node);
}

void append_node(t_stack **a, int data)
{
    t_stack *node;
    t_stack *tmp;
    tmp = *a;
    node = new_node(data);
    if(!node)
        ft_error("Error: Malloc falla en append_node\n", a);

    if (!*a)
    {
        *a = node;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}
void node_into_stack_and_null_parse(t_stack **a, char **num)
{
    int i;
    i = 0;

    if(num[i] == NULL)
    {
        free_array(num);
        ft_error("Error: No hay números.\n", a);
    }
    while(num[i])
    {
        append_node(a, ft_atoi(num[i]));
        i++;
    }
}
void check_dup_parse(t_stack **a)
{
    t_stack *current;
    t_stack *to_compare;

    current = *a;
    while(current != NULL && current->next != NULL)
    {
        to_compare = current->next;
        while(to_compare)
        {
            if(current->data == to_compare->data)
            {
                ft_error("Error: Hay números duplicados.\n", a);
            }
            to_compare = to_compare->next;
        }
        current= current->next;

    }
}