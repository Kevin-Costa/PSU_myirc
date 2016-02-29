/*
** message.c for message in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 19 21:17:06 2015 Antoine Plaskowski
** Last update Sun Apr 19 23:18:44 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	"message.h"
#include	"parser.h"
#include	"lexer.h"

bool		message(t_message *message, char *str)
{
  t_lexer	*lexer;
  t_parser	*parser;

  if (message == NULL)
    return (true);
  memset(message, 0, sizeof(*message));
  lexer = lex(str);
  parser = parse(lexer);
  parser = first_node(&parser->node);
  if (parser == NULL)
    return (false);
  switch (parser->lexem_ter)
    {
    case NAME_SERVER:
    case PSEUDO:
      return (set_prefix(message, parser));
    case COMMAND:
      return (set_command(message, parser));
    default:
      return (true);
    }
}
