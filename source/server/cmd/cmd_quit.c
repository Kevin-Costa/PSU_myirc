/*
** cmd_quit.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Apr 22 22:13:47 2015 zwertv_e
** Last update Sun Apr 26 18:31:06 2015 zwertv_e
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"client.h"
#include	"message.h"
#include	"channels.h"
#include	"node.h"
#include	"exec_cmd.h"

static void	send_quit(t_chan *chan, t_client *client, char *reason)
{
  t_cclient	*tmp;

  tmp = first_node(&chan->clients->node);
  while (tmp != NULL)
    {
      if (tmp->client != client)
	{
	  if (reason != NULL)
	    dprintf(tmp->client->client, ":%s!%s QUIT :%s\r\n", client->nick, \
		    client->user, reason);
	  else
	    dprintf(tmp->client->client, ":%s!%s QUIT :%s\r\n", client->nick, \
		    client->user, "Disconnected by user");
	}
      tmp = tmp->node.next;
    }
}

void		cmd_quit(t_message *msg, t_client *client, t_chan **chans)
{
  size_t	i;

  if (msg == NULL || client == NULL)
    return;
  i = 0;
  while (i < MAX_CHANNELS)
    {
      if (client->channels[i] != NULL)
	{
	  if (msg->params != NULL)
	    send_quit(client->channels[i], client, msg->params[0]);
	  else
	    send_quit(client->channels[i], client, NULL);
	  *chans = leave_chan(*chans, client, client->channels[i]->name);
	}
      ++i;
    }
  client->isAuth = -1;
  close(client->client);
}
