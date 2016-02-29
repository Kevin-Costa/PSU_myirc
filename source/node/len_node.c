/*
** len_node.c for len_node in /home/plasko_a/projet/epitech/PSU_2014_myirc/source/node
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Apr 11 21:04:59 2015 Antoine Plaskowski
** Last update Sat Apr 11 21:07:45 2015 Antoine Plaskowski
*/

#include	"node.h"

static size_t	rec_len_node(t_node *node, size_t len)
{
  return (node != NULL ? rec_len_node(node->next, len + 1) : len);
}

size_t		len_node(t_node *node)
{
  return (rec_len_node(first_node(node), 0));
}
