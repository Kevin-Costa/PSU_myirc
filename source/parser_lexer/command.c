/*
** command.c for command in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 19 19:40:17 2015 Antoine Plaskowski
** Last update Sun Apr 19 20:59:23 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"lexer.h"
#include	"parser.h"

t_parser	*command(t_lexer *lexer, t_parser *parser)
{
  t_parser	*new;
  char		*str;

  if (lexer == NULL)
    return (NULL);
  if ((str = concat_lexem(&lexer, SPACE)) == NULL)
    return (NULL);
  if (lexer == NULL || (new = malloc(sizeof(*new))) == NULL)
    {
      free(str);
      return (NULL);
    }
  new->lexem_ter = COMMAND;
  new->str = str;
  parser = put_node(&parser->node, &new->node);
  return (params(lexer->node.next, parser));
}
