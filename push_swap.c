/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:13:28 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/25 10:17:52 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*tab_int;
	t_list	*(*tab_lst);

	if (!ft_arg_error(argc, argv))
		return (0);
	tab_lst = malloc(sizeof(t_list) * 2);
	if (!tab_lst)
		return (0);
	tab_int = malloc(sizeof(int) * argc - 1);
	if (!tab_int)
		return (0);
	tab_lst[0] = ft_lstinit(argv, tab_int);
	if (!ft_sortinlist(tab_lst[0]))
		ft_sort(tab_lst);
	ft_free_lst(tab_lst[0]);
	free(tab_lst);
	free(tab_int);
	return (0);
}

void	ft_free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free (tmp);
	}
	free(lst);
}

t_list	*ft_lstinit(char **argv, int *tab_int)
{
	int		i;
	t_list	*lst_tmp;
	t_list	*lst;
	t_list	**lst_first;

	i = 0;
	lst = NULL;
	lst_first = &lst;
	while (argv[++i])
	{
		tab_int[i - 1] = ft_atoi(argv[i]);
		lst_tmp = ft_lstnew(&tab_int[i - 1]);
		ft_lstadd_back(lst_first, lst_tmp);
	}
	while (lst->next)
	{
		lst_tmp = lst;
		lst = lst->next;
		lst->prev = lst_tmp;
	}
	while (lst->prev)
		lst = lst->prev;
	return (*lst_first);
}
/*
void	ft_putlist(t_list *lst)
{
	while (lst)
	{
		if (lst->content)
			printf("%p list content : %d %p next %p prev %p\n",
			lst, lst->content[0],lst->content, lst->next, lst->prev);
		else
			printf ("%p list content :  %p next %p prev %p\n",
			lst,lst->content, lst->next, lst->prev);
		lst = lst->next;
	}
}

void	ft_putlist_place(t_list *lst)
{
	while (lst)
	{
		if (lst->f_place)
			printf ("%p content : %d f_place %d \n", lst,
			lst->content[0],lst->f_place);
		else
			printf ("%p content : %d f_place %d \n", lst,
			lst->content[0],lst->f_place);
		lst = lst->next;
	}
}
*/
