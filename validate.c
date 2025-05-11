#include "push_swap.h"
int is_digit(char num)
{
    if(num >= '0' && num <= '9')
        return 1;
    return 0;
}
int check_long(char *num)
{
    long long val;
    val = ft_atoll(num);
    return (val >= INT_MIN && val <= INT_MAX);
}
void validate_range_len(char **num, t_stack **a)
{
    int i;
    i = 0;
    while(num[i])
    {
        if(*num[i] == '\0')
        {
            free_array(num);
            ft_error("Error: Cadena vacía\n", a);
        }
        if(!(check_long(num[i])))
        {
            free_array(num);
            ft_error("Error: Número fuera de rango\n", a);
        }
        i++;
    }
}
int validate_char(char* num)
{
    int i;
    i = 0;
    if(!num[i])
        return(0);
    if((num[0] == '-' || num[0] == '+') && !(is_digit(num[1])))
        return(0);
    if (num[0] == '-' || num[0] == '+')
        i++;
    while(num[i])
    {
        if(!is_digit(num[i]))
            return (0);
        i++;
    }
    return(1);
}
void validate_num_array(char **array, t_stack **a)
{
    int i;
    i = 0;
    while(array[i])
    {
        if(!(validate_char(array[i])))
        {
            free_array(array);
            ft_error("Error: Número inválido", a);
        }
        else
            i++;

    }
}