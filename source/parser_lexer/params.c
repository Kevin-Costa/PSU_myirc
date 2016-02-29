/*
** params.c for params in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 19 19:44:28 2015 Antoine Plaskowski
** Last update Sun Apr 19 21:05:27 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"lexer.h"
#include	"parser.h"

static t_parser	*end(t_lexer *lexer, t_parser *parser)
{
  t_parser	*new;
  char		*str;

  if (lexer == NULL)
    return (NULL);
  if ((str = concat_lexem(&lexer, CRLF)) == NULL)
    return (NULL);
  if (lexer == NULL || (new = malloc(sizeof(*new))) == NULL)
    {
      free(str);
      return (NULL);
    }
  new->lexem_ter = END;
  new->str = str;
  parser = put_node(&parser->node, &new->node);
  return (parser);
}

static t_parser	*middle(t_lexer *lexer, t_parser *parser)
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
  new->lexem_ter = MIDDLE;
  new->str = str;
  parser = put_node(&parser->node, &new->node);
  return (params(lexer->node.next, parser));
}

t_parser	*params(t_lexer *lexer, t_parser *parser)
{
  if (lexer == NULL)
    return (NULL);
  switch (lexer->lexem)
    {
    case CRLF:
      return (parser);
    case COLON:
      return (end(lexer->node.next, parser));
    default:
      return (middle(lexer, parser));
    }
}
