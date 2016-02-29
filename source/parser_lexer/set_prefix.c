/*
** set_prefix.c for set_prefix in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 19 21:51:03 2015 Antoine Plaskowski
** Last update Sun Apr 19 22:45:39 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	"message.h"

static bool	host(t_message *message, t_parser *parser)
{
  if (parser == NULL)
    return (true);
  if (parser->lexem_ter == HOST)
    {
      message->prefix.host = strdup(parser->str);
      return (host(message, parser->node.next));
    }
  return (set_command(message, parser));
}

static bool	user(t_message *message, t_parser *parser)
{
  if (parser == NULL)
    return (true);
  if (parser->lexem_ter == USER)
    {
      message->prefix.user = strdup(parser->str);
      return (host(message, parser->node.next));
    }
  return (host(message, parser));
}

bool		set_prefix(t_message *message, t_parser *parser)
{
  if (parser == NULL)
    return (true);
  if ((parser->lexem_ter & (NAME_SERVER | PSEUDO)) == 0)
    return (true);
  message->prefix.sender = strdup(parser->str);
  if (parser->lexem_ter == NAME_SERVER)
    {
      message->prefix.server = true;
      return (set_command(message, parser->node.next));
    }
  return (user(message, parser->node.next));
}

