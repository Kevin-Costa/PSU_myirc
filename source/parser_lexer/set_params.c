/*
** set_params.c for set_params in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 19 22:22:16 2015 Antoine Plaskowski
** Last update Sun Apr 19 22:35:35 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	<stdlib.h>
#include	"message.h"

static size_t	nbr_params(t_parser *parser)
{
  size_t	i;

  i = 0;
  while (parser != NULL)
    {
      if ((parser->lexem_ter & (MIDDLE | END)) != 0)
	i++;
      parser = parser->node.next;
    }
  return (i);
}

bool		set_params(t_message *message, t_parser *parser)
{
  size_t	i;

  message->params = malloc(sizeof(*message->params) * (nbr_params(parser) + 1));
  if (message->params == NULL)
    return (true);
  i = 0;
  while (parser != NULL)
    {
      if ((parser->lexem_ter & (MIDDLE | END)) != 0)
	{
	  message->params[i] = strdup(parser->str);
	  i++;
	}
      parser = parser->node.next;
    }
  message->params[i] = NULL;
  return (false);
}

