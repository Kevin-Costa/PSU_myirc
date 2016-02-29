/*
** parser.c for parser in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 15 09:49:00 2015 Antoine Plaskowski
** Last update Sun Apr 19 21:16:59 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	"message.h"
#include	"parser.h"
#include	"lexer.h"

char		*concat_lexem(t_lexer **lexer, t_lexem lexem)
{
  t_lexer	*tmp;
  char		*str;
  size_t	len;

  len = 0;
  tmp = *lexer;
  while (tmp != NULL && (tmp->lexem & lexem) == 0)
    {
      len += strlen(tmp->str);
      tmp = tmp->node.next;
    }
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  *str = '\0';
  tmp = *lexer;
  while (tmp != NULL && (tmp->lexem & lexem) == 0)
    {
      strcat(str, tmp->str);
      tmp = tmp->node.next;
    }
  *lexer = tmp;
  return (str);
}

t_parser	*parse(t_lexer *lexer)
{
  lexer = first_node(&lexer->node);
  if (lexer == NULL)
    return (NULL);
  switch (lexer->lexem)
    {
    case COLON:
      return (prefix(lexer->node.next, NULL));
    default:
      return (command(lexer, NULL));
    }
}
