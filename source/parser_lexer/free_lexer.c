/*
** free_lexer.c for free_lexer in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 15 16:36:53 2015 Antoine Plaskowski
** Last update Wed Apr 15 17:16:10 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"lexer.h"

static void	*rec_free_all_lexer(t_lexer *lexer)
{
  t_lexer	*next;

  if (lexer == NULL)
    return (NULL);
  next = lexer->node.next;
  free(lexer->str);
  free(lexer);
  return (rec_free_all_lexer(next));
}

void		*free_all_lexer(t_lexer *lexer)
{
  return (rec_free_all_lexer(first_node(&lexer->node)));
}
