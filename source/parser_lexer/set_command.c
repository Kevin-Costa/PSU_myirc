/*
** set_command.c for set_command in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 19 22:07:57 2015 Antoine Plaskowski
** Last update Sun Apr 19 22:20:25 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	"message.h"

bool		set_command(t_message *message, t_parser *parser)
{
  if (parser == NULL)
    return (true);
  if (parser->lexem_ter != COMMAND)
    return (true);
  message->command = strdup(parser->str);
  return (set_params(message, parser->node.next));
}
