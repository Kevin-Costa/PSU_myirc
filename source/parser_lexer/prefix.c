/*
** prefix.c for prefix in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 19 19:17:31 2015 Antoine Plaskowski
** Last update Tue Apr 28 15:48:07 2015 Kevin Costa
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"lexer.h"

static t_parser	*at(t_lexer *lexer, t_parser *parser)
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
  new->str = str;
  new->lexem_ter = HOST;
  parser = put_node(&parser->node, &new->node);
  return (command(lexer->node.next, parser));
}

static t_parser	*exclamation_mark(t_lexer *lexer, t_parser *parser)
{
  t_parser	*new;
  char		*str;

  if (lexer == NULL)
    return (NULL);
  if ((str = concat_lexem(&lexer, SPACE | AT)) == NULL)
    return (NULL);
  if (lexer == NULL || (new = malloc(sizeof(*new))) == NULL)
    {
      free(str);
      return (NULL);
    }
  new->str = str;
  new->lexem_ter = USER;
  parser = put_node(&parser->node, &new->node);
  switch (lexer->lexem)
    {
    case AT:
      return (at(lexer->node.next, parser));
    default:
      return (command(lexer->node.next, parser));
    }
}

t_parser	*prefix(t_lexer *lexer, t_parser *parser)
{
  t_parser	*new;
  char		*str;

  if (lexer == NULL)
    return (NULL);
  if ((str = concat_lexem(&lexer, SPACE | EXCLAMATION_MARK | AT)) == NULL)
    return (NULL);
  if (lexer == NULL || (new = malloc(sizeof(*new))) == NULL)
    {
      free(str);
      return (NULL);
    }
  new->str = str;
  new->lexem_ter = PSEUDO;
  parser = put_node(&parser->node, &new->node);
  switch (lexer->lexem)
    {
    case EXCLAMATION_MARK:
      return (exclamation_mark(lexer->node.next, parser));
    case AT:
      return (at(lexer->node.next, parser));
    default:
      new->lexem_ter = NAME_SERVER;
      return (command(lexer->node.next, parser));
    }
}
