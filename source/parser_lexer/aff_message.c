/*
** aff_message.c for aff_message in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 19 22:37:00 2015 Antoine Plaskowski
** Last update Sun Apr 19 23:18:22 2015 Antoine Plaskowski
*/

#include	"message.h"

static bool	show_prefix(t_message *message, FILE *stream)
{
  if (message->prefix.sender != NULL)
    fprintf(stream, "%s = %s\n",
	    message->prefix.server == true ? "SERVER_NAME" : "PSEUDO",
	    message->prefix.sender);
  if (message->prefix.user != NULL)
    fprintf(stream, "USER = %s\n", message->prefix.user);
  if (message->prefix.host != NULL)
    fprintf(stream, "HOST = %s\n", message->prefix.host);
  return (false);
}

static bool	show_params(t_message *message, FILE *stream)
{
  size_t	i;

  if (message->params != NULL)
    {
      i = 0;
      while (message->params[i] != NULL)
	{
	  fprintf(stream, "PARAMS[%lu] = %s\n", i, message->params[i]);
	  i++;
	}
    }
  return (false);
}

bool		aff_message(t_message *message, FILE *stream)
{
  if (message == NULL)
    return (true);
  show_prefix(message, stream);
  if (message->command != NULL)
    fprintf(stream, "COMMAND = %s\n", message->command);
  show_params(message, stream);
  return (false);
}
