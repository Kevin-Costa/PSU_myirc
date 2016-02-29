/*
** my_sup_node.c for sup_node in /home/plasko_a/projet/epitech/PSU_2014_myirc/source/node
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 10 15:33:01 2015 Antoine Plaskowski
** Last update Fri Apr 10 15:33:11 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"node.h"

void		*sup_node(t_node *node)
{
  t_node	*ret;

  if (node == NULL)
    return (NULL);
  ret = NULL;
  if (node->next != NULL)
    {
      ret = node->next;
      ret->prev = node->prev;
    }
  if (node->prev != NULL)
    {
      ret = node->prev;
      ret->next = node->next;
    }
  free_node(node);
  return (first_node(ret));
}
