/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:18:06 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/25 14:02:19 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_struc
{
	int	len_lst;
	int	pourcent;
	int	pivot;
	int	pivot_prev;
}	t_algo;

/*
FT_CHECK_ARG --------------------------------------------------------------------
*/
int		ft_arg_nb(int argc);
int		ft_arg_digit(char **argv);
int		ft_arg_doublon(char **argv);
int		ft_arg_limit(char **argv);
int		ft_arg_error(int argc, char **argv);
/*
FT_CHECK_lIST -------------------------------------------------------------------
*/
int		ft_sortinlist(t_list *lst);
int		ft_doubletablen(char **tab);
int		ft_sortin2(t_list *lst, char c);
/*
FT_SWAP -------------------------------------------------------------------------
*/
int		ft_swap(t_list *lst);
int		ft_swap_a(t_list *lst);
int		ft_swap_b(t_list *lst);
int		ft_swap_ss(t_list *lst_a, t_list *lst_b);
/*
FT_ROTATE -----------------------------------------------------------------------
*/
int		ft_rotate(t_list *lst);
int		ft_rotate_a(t_list *lst);
int		ft_rotate_b(t_list *lst);
int		ft_rotate_rr(t_list *lst_a, t_list *lst_b);
/*
FT_REVERSE_ROTATE ---------------------------------------------------------------
*/
int		ft_swap_reverse(t_list *lst);
int		ft_rotate_reverse(t_list *lst);
int		ft_rotate_reverse_a(t_list *lst);
int		ft_rotate_reverse_b(t_list *lst);
int		ft_rotate_reverse_rr(t_list *lst_a, t_list *lst_b);
/*
FT_PUSH -------------------------------------------------------------------------
*/
void	ft_push(t_list *(*tab_lst));
int		ft_push_a(t_list *(*tab_lst));
int		ft_push_b(t_list *(*tab_lst));
void	ft_invers_lsttab(t_list *(*tab_lst));
void	ft_delfirst(t_list *lst);
/*
FT_OPTI -------------------------------------------------------------------------
*/
int		ft_lestrotate(t_list *lst, int nb);
int		ft_lestrotate_place(t_list *lst, int nb);
int		ft_placepush(t_list *lst, int nb);
int		ft_placepush_b(t_list *lst, int nb);
int		ft_minuspush(t_list *lst);
/*
FT_ALGO -------------------------------------------------------------------------
*/
int		ft_sort(t_list *(*tab_lst));
void	ft_sorttwo(t_list *tab_lst);
void	ft_sortthree(t_list *(*tab_lst));
void	ft_sortfour(t_list *(*tab_lst));
void	ft_sortfive(t_list *(*tab_lst));
/*
FT_BIG_ALGO ---------------------------------------------------------------------
*/
void	ft_sorthundred_two(t_list *(*tab_lst));
void	ft_push_max(t_list *(*tab_lst), int len_lst);
void	ft_algo_init(t_algo *algo, t_list *lst);
void	ft_push_back(t_algo *algo, t_list *(*tab_lst), int k);
void	ft_push_front(t_algo *algo, t_list *(*tab_lst));
/*
FT_FIND -------------------------------------------------------------------------
*/
int		ft_findminus(t_list	*lst);
int		ft_find_place(t_list *lst, int nb);
int		ft_find_sup(t_list *lst, int nb);
int		ft_find_inter(t_list *lst, int min, int max);
/*
FT_PLACE ------------------------------------------------------------------------
*/
int		ft_f_place(t_list *lst, int nb);
int		ft_findminus_place(t_list	*lst);
int		ft_sort_place(t_list *lst);
void	ft_putplace(t_list *lst);
int		ft_nb_place(t_list *lst);

/*
FT_PUSH -------------------------------------------------------------------------
*/
t_list	*ft_lstinit(char **argv, int *tab_int);
void	ft_delete(void *content);
void	ft_free_lst(t_list *lst);
void	ft_putlist(t_list *lst);
void	ft_putlist_place(t_list *lst);
#endif
