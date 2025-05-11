#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
typedef struct s_stack
{
    int data;
    int index;
    struct s_stack *next;

} t_stack;
//Push_swap moves
//Swap
void basic_swap(t_stack **stack);
void swap_a(t_stack **a);
void swap_b(t_stack **b);
void swap_ab(t_stack **a, t_stack **b);
//push
void basic_push(t_stack **stack1, t_stack **stack2);
void push_a(t_stack **b, t_stack **a);
void push_b(t_stack **a, t_stack **b);
//rotate
void basic_rotate(t_stack **stack);
void rotate_a(t_stack **a);
void rotate_b(t_stack **b);
void rotate_ab(t_stack **a, t_stack **b);
//reverse_rotate
void basic_rrotate(t_stack **stack);
void rrotate_a(t_stack **a);
void rrotate_b(t_stack **b);
void rrotate_ab(t_stack **a, t_stack **b);
//Assign indexes
void index_to_negative(t_stack *current);
void assign_indexes(t_stack *a);
//Micro sort
void sort_two(t_stack **a);
void sort_three(t_stack **a);
//Chiqui sort
t_stack* get_min(t_stack *a);
int get_position(t_stack *a, int index);
int get_size(t_stack *a);
void rotate_to_top(t_stack **a, int index);
void chiqui_sort(t_stack **a, t_stack **b);
//K sort
int	ft_sqrt(int number);
void move_to_b(t_stack **a, t_stack **b, int number);
int count_rot(t_stack *stack, int max_pos);
void k_sort(t_stack **a, t_stack **b, int number);
//Push_swap.c
void sort(t_stack **a, t_stack **b);

//validate
int check_long(char *num);
void validate_range_len(char **num, t_stack **a);
int validate_char(char* num);
void validate_num_array(char **array, t_stack **a);
//create stack and parse
t_stack *new_node(int data);

void append_node(t_stack **a, int data);
void node_into_stack_and_null_parse(t_stack **a, char **num);
void check_dup_parse(t_stack **a);

// free
void ft_putstr(char * str);
int free_node(t_stack **stack);
int ft_error(char *str, t_stack **stack);
int free_array(char **array);

//split
static void *ft_free_word(char **total_words);
int ft_wordcount(char const *s, char c);
char **ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
//lib_utils
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int	ft_atoi(const char *str);
long long	ft_atoll(const char *str);
#endif
