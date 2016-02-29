/*
** my_free_node.c for free_node in /home/plasko_a/projet/epitech/PSU_2014_myirc/source/node
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 10 15:32:38 2015 Antoine Plaskowski
** Last update Sat Apr 11 21:32:32 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"node.h"

void		free_node(t_node *node)
{
  free(node);
}

static void	rec_free_all_node(t_node *node)
{
  t_node	*next;

  if (node == NULL)
    return;
  next = node->next;
  free_node(node);
  rec_free_all_node(next);
}

void		free_all_node(t_node *node)
{
  rec_free_all_node(first_node(node));
}
