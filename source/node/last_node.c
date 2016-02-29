/*
** my_last_node.c for lastnode in /home/plasko_a/projet/epitech/PSU_2014_myirc/source/node
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 10 15:32:21 2015 Antoine Plaskowski
** Last update Sat Apr 11 21:26:07 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"node.h"

static void	*rec_last_node(t_node *node)
{
  return (node->next != NULL ? rec_last_node(node->next) : node);
}

void		*last_node(t_node *node)
{
  if (node != NULL)
    return (rec_last_node(node));
  return (node);
}
