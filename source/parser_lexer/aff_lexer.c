/*
** lexer_utils.c for lexer_utils in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 15 16:36:53 2015 Antoine Plaskowski
** Last update Wed Apr 22 21:16:32 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	"lexer.h"

static char const	*lexem_to_string(t_lexem const lexem)
{
  switch (lexem)
    {
    case COLON:
      return ("COLON");
    case SPACE:
      return ("SPACE");
    case EXCLAMATION_MARK:
      return ("EXCLAMATION_MARK");
    case AT:
      return ("AT");
    case CRLF:
      return ("CRLF");
    case STRING:
      return ("STRING");
    default:
      return ("NONE");
    }
}

static bool	rec_aff_all_lexer(t_lexer *lexer, FILE *stream)
{
  if (lexer == NULL)
    return (false);
  fprintf(stream, "%s = %s\n", lexem_to_string(lexer->lexem), lexer->str);
  return (rec_aff_all_lexer(lexer->node.next, stream));
}

bool		aff_all_lexer(t_lexer *lexer, FILE *stream)
{
  return (rec_aff_all_lexer(first_node(&lexer->node), stream));
}
