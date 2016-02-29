/*
** exec_cmd.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 12 19:05:46 2015 zwertv_e
** Last update Sun Apr 26 23:06:34 2015 zwertv_e
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	"exec_cmd.h"
#include	"client.h"
#include	"channels.h"
#include	"message.h"
#include	"server.h"
#include	"rcode.h"

static bool	regist_cmd(t_message *msg, t_client *client, t_chan **chans)
{
  if (strcmp(msg->command, "JOIN") == 0)
    cmd_join(msg, client, chans);
  else if (strcmp(msg->command, "PART") == 0)
    cmd_part(msg, client, chans);
  else if (strcmp(msg->command, "PRIVMSG") == 0)
    cmd_privmsg(msg, client, *chans);
  else if (strcmp(msg->command, "LIST") == 0)
    cmd_list(msg, client, *chans);
  else if (strcmp(msg->command, "NAMES") == 0)
    cmd_names(msg, client, *chans);
  else if (strcmp(msg->command, "TOPIC") == 0)
    cmd_topic(msg, client, *chans);
  else if (strcmp(msg->command, "PING") == 0)
    cmd_ping(client);
  else if (strcmp(msg->command, "KICK") == 0)
    cmd_kick(msg, client, chans);
  else if (strcmp(msg->command, "KILL") == 0)
    cmd_kill(msg, client, chans);
  else
    return (false);
  return (true);
}

void		exec_cmd(t_message *msg, t_client *client, t_chan **chans)
{
  if (client == NULL || msg == NULL)
    return;
  if (msg->command == NULL)
    {
      dprintf(client->client, ERR_UNKNOWNCOMMAND, S_NAME, S_ADDR,
	      client->nick, "");
      return;
    }
  if (strcmp(msg->command, "USER") == 0)
    cmd_user(msg, client);
  else if (strcmp(msg->command, "NICK") == 0)
    cmd_nick(msg, client);
  else if (strcmp(msg->command, "QUIT") == 0)
    cmd_quit(msg, client, chans);
  else if (client->isAuth < 3)
    dprintf(client->client, ERR_NOTREGISTERED, S_NAME, S_ADDR, client->nick);
  else if (regist_cmd(msg, client, chans) == false)
    dprintf(client->client, ERR_UNKNOWNCOMMAND, S_NAME, S_ADDR,
	    client->nick, msg->command);
}
