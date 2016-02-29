/*
** sup_node_at.c for sup_node_at in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Apr 11 21:46:37 2015 Antoine Plaskowski
** Last update Mon Apr 13 17:42:14 2015 Antoine Plaskowski
*/

#include	"node.h"

static void	*rec_sup_node_at(t_node *node, size_t const i,
				 size_t const pos)
{
  if (node == NULL)
    return (NULL);
  else if (i < pos)
    return (sup_node(node));
  else
    return (rec_sup_node_at(node->next, i + 1, pos));
}

void		*sup_node_at(t_node *node, size_t const pos)
{
  return (rec_sup_node_at(first_node(node), 0, pos));
}

