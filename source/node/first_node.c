/*
** my_first_node.c for first_node in /home/plasko_a/projet/epitech/PSU_2014_myirc/source/node
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 10 15:32:05 2015 Antoine Plaskowski
** Last update Sat Apr 11 21:18:06 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"node.h"

static void	*rec_first_node(t_node *node)
{
  return (node->prev != NULL ? rec_first_node(node->prev) : node);
}

void		*first_node(t_node *node)
{
  if (node != NULL)
    return (rec_first_node(node));
  return (node);
}
