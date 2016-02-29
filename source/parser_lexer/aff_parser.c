/*
** aff_parser.c for aff_parser in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Sun Apr 19 20:26:22 2015 Antoine Plaskowski
** Last update Wed Apr 22 21:16:51 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	"parser.h"

static char const	*lexem_ter_to_string(t_lexem_ter const lexem_ter)
{
  switch (lexem_ter)
    {
    case NAME_SERVER:
      return ("NAME_SERVER");
    case PSEUDO:
      return ("PSEUDO");
    case USER:
      return ("USER");
    case HOST:
      return ("HOST");
    case COMMAND:
      return ("COMMAND");
    case MIDDLE:
      return ("MIDDLE");
    case END:
      return ("END");
    default:
      return ("NONE");
    }
}

static bool	rec_aff_all_parser(t_parser *parser, FILE *stream)
{
  if (parser == NULL)
    return (false);
  fprintf(stream, "%s = %s\n", lexem_ter_to_string(parser->lexem_ter),
	  parser->str);
  return (rec_aff_all_parser(parser->node.next, stream));
}

bool		aff_all_parser(t_parser *parser, FILE *stream)
{
  return (rec_aff_all_parser(first_node(&parser->node), stream));
}
