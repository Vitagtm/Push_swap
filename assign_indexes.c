#include "push_swap.h"
void index_to_negative(t_stack *current)
{
    while(current)
    {
        current->index = -1;
        current = current->next;
    }

}
void assign_indexes(t_stack *a)
{
    t_stack *min_node;
    int index;
    t_stack *current;

    index = 0;
    current = a;
    index_to_negative(current);
    while(1)
    {
        min_node = NULL;
        current = a;
        while(current)
        {
            if(current->index == -1)
            {
                if(!min_node || current->data < min_node->data)
                    min_node = current;
            }
            current = current->next;
        }
        if(!min_node)
            break;
        min_node->index = index;
        index++;
    }
}
