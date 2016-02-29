/*
** my_put_node.c for node in /home/plasko_a/projet/epitech/PSU_2014_myirc/source/node
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 10 15:32:53 2015 Antoine Plaskowski
** Last update Sat Apr 11 21:09:43 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"node.h"

void		*put_node(t_node *old, t_node *node)
{
  if ((old = last_node(old)) != NULL)
    old->next = node;
  if (node != NULL)
    {
      node->prev = old;
      node->next = NULL;
    }
  else
    node = old;
  return (node);
}
