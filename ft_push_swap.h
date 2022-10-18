/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:21:53 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/18 17:03:12 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define CONTINUE -2147483648

/** EXPLANATION OF THE ALGORITHM
 * @brief The execution of the program has to be as follows:
 * ./push_swap 1 4 3
 * 1
 * 4
 * 3
 * -  -
 * a  b
 * In which a number of transitions will be done and finish as:
 * 1
 * 3
 * 4
 * -  -
 * a  b
 * The algorithm should be O(n·log n)
 * so as the test with 500 would be 500 · log_2 500 < 5500
 */

/**
 * Allowed functions:
 * ◦ write
 * ◦ read
 * ◦ malloc
 * ◦ free
 * ◦ exit
 */

typedef struct s_stack
{
	int				num;
	int				finalpos;
	struct s_stack	*nxt;
}	t_stack;

typedef struct s_move
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}	t_move;

/* ARGUMENTS */
/**
 * @brief Checks if every argument is a number
 * @param argc the number of arguments
 * @param argv the array of strings, arguments of the program
 * @return 0 if Ok, -1 if not.
 */
int		ft_sintax_check(int argc, char **argv);

/**
 * @brief 
 * 
 * @param str 
 * @param c 
 * @return char** 
 */
char	**ft_split(char const *str, char c);

/**
 * @brief 
 * 
 * @param res 
 */
void	ft_free_split(char **res);

/**
 * @brief 
 * 
 * @param res 
 * @return int 
 */
int		ft_split_size(char **res);

/**
 * @brief Returns an integer of the first part of a string.
 * This string may begin with an arbitrary amount of white space
 * (as determined by isspace(3)) followed by a single optional `+' or `-' sign. 
 * @param str the strring to convert.
 * @return The string conversion. */
int		ft_atoi(const char *str);

/**
 * @brief The strncmp() function compares not more than n characters. 
 * Because strncmp() is designed for comparing strings rather than binary data,
 * characters that appear after a `\0' character are not compared.
 * @param s1 a string.
 * @param s2 another string.
 * @return 0 if equal, < 0 if s1 is lower than s2 and > 0 if s1 is greater
 * than s2. */
int		ft_strcmp(char *s1, char *s2);

/* OPERATIONS*/

/**
 * @brief Takes the first two elements on top of this stack.
 * Does nothing if the stack has less than 2 elements.
 * @param stack The stack where the exchange will be done. */
void	ft_swap(t_stack **stack, char c);

/**
 * @brief Takes the first element and put it at the end.
 * @param stack The stack where the exchange will be done. */
void	ft_rotate(t_stack **stack, char c);

/**
 * @brief Takes the last element and put it at the beggining
 * @param stack The stack where the exchange will be done. */
void	ft_reverse(t_stack **stack, char c);

/**
 * @brief Takes the first element of stack b and puts it
 * on top of a 
 * @param stack_a The stack where the element is added
 * @param stack_b The stack where the element is extracted */
void	ft_push(t_stack **stack_a, t_stack **stack_b, char c);

/* UTILITIES */

/**
 * @brief Checks if an element is in the stack. Used to check if
 * there are duplicated items 
 * @param stack The stack where to search
 * @param element The element to look for
 * @return 0 if not found, 1 if so. */
int		ft_is_in_stack(t_stack *stack, int element);

/**
 * @brief Checks if the stack is ordered
 * @param stack The stack to check
 * @return 1 if it is ordered, 0 if not.*/
int		ft_is_sorted(t_stack *stack);

/**
 * @brief Measures the stack size.
 * @param stack the stack to measure.
 * @return The size of the stack. */
int		ft_stack_size(t_stack *stack);

/**
 * @brief Returns whether the stack was empty or not
 * @param stack Stack to check
 * @return 1 if is empty, 0 if not.
 */
int		ft_is_empty_stack(t_stack **stack);

/**
 * @brief Gets the last node
 * Be careful on how to use it
 * @param stack
 * @return The last node */
t_stack	*ft_get_last(t_stack *stack);

/**
 * @brief Adds a node at the front of the stack
 * @param stack the stack where to add the new node
 * @param element the number of the node
 * @return Returns -1 if the element is already in the stack
 * or if the malloc fails 
 */
int		ft_add_front(t_stack **stack, int element);

/**
 * @brief Frees the memory position form the stack
 * @param stack The stack to free
 */
void	ft_free_stack(t_stack **stack);

/**
 * @brief Set the desired position for the stack elements
 * 
 * @param stack 
 */
void	ft_desired_pos(t_stack *stack);

void	ft_find_best_i(t_stack **a, t_stack **b, t_move *moves);
int		ft_find_lowest_i(t_stack	**a, int size);
int		ft_find_greatest_if(t_stack	**a);
int		ft_find_greatest_i(t_stack	**a);
int		ft_rotate_or_reverse(t_stack **a, int cluster_range);
void	ft_from_a_to_b(t_stack **a, t_stack **b, int cluster_size);
void	ft_from_b_to_a(t_stack **a, t_stack **b);
void	ft_sort_up_to_five(t_stack **a, t_stack **b, int size);
void	ft_sort_lower_three(t_stack	**a, char c);
void	ft_sort_three(t_stack	**stack, char c);
int		ft_get_first_i_below_range(t_stack **a, int cluster_range);
void	ft_restart_moves(t_move *aux);
void	ft_init_moves(t_move *aux);
void	ft_copy(t_move *moves, t_move *aux);
int		ft_totalcost(t_move *moves);
void	ft_optimize_rotate(t_move *aux);
void	ft_optimize_reverse(t_move *aux);

/**
 * @brief Gets the number of i at stack a.
 * 
 * @param a 
 * @param indx 
 * @return int 
 */
int		ft_get_i_num(t_stack **a, int indx);

/* CHECKER */

int		ft_check_swap(t_stack **a, t_stack **b, char *res);
int		ft_check_push(t_stack **a, t_stack **b, char *res);
int		ft_check_rotate(t_stack **a, t_stack **b, char *res);
int		ft_check_reverse(t_stack **a, t_stack **b, char *res);

/* REMOVE */
void	ft_print_stack(t_stack	*stack);
void	ft_print_stack_extra(t_stack	*stack);
#endif
