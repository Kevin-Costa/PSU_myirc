/*
** cmd_kick.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 21:55:46 2015 zwertv_e
** Last update Wed Apr 29 11:41:38 2015 zwertv_e
*/

#include	<stdlib.h>
#include	<stdbool.h>
#include	<string.h>
#include	"client.h"
#include	"server.h"
#include	"message.h"
#include	"rcode.h"
#include	"channels.h"
#include	"exec_cmd.h"

static void     send_msg(t_client *client, t_chan *to_rm,
			    t_client *to_kick, char *reason)
{
  t_cclient	*tmp;

  tmp = first_node(&to_rm->clients->node);
  while (tmp != NULL)
    {
      if (reason != NULL)
	dprintf(tmp->client->client, ":%s!%s KICK %s %s :%s\r\n",
		client->nick, client->user, to_rm->name,
		to_kick->nick, reason);
      else
	dprintf(tmp->client->client, ":%s!%s KICK %s %s :%s\r\n",
		client->nick, client->user, to_rm->name,
		to_kick->nick, "Kicked by operator");
      tmp = tmp->node.next;
    }
}

static void	kick_user(t_message *msg, t_client *client,
			  t_chan **chans, char *reason)
{
  t_chan	*to_rm;
  t_client	*to_kick;
  size_t	i;

  to_rm = find_chan(*chans, msg->params[0]);
  to_kick = first_node(&client->node);
  while (to_kick != NULL && strcmp(to_kick->nick, msg->params[1]) != 0)
    to_kick = to_kick->node.next;
  i = 0;
  if (to_kick != NULL)
    {
      while (i < MAX_CHANNELS)
	{
	  if (to_kick->channels[i] != NULL && to_kick->channels[i] == to_rm)
	    {
	      send_msg(client, to_kick->channels[i], to_kick, reason);
	      *chans = leave_chan(*chans, to_kick, to_kick->channels[i]->name);
	      to_kick->channels[i] = NULL;
	    }
	  ++i;
	}
    }
}

static bool	is_chan_op(t_client *client, t_chan *chan)
{
t_cclient	*clients;

 clients = first_node(&chan->clients->node);
 while (clients != NULL && clients->client != client)
   clients = clients->node.next;
 if (clients == NULL)
   return (false);
 if (client->isOp == true)
   return (true);
 if (clients->isOp == true)
     return (true);
 return (false);
}

static bool	is_kick_valid(t_message *msg, t_client *client, t_chan *chans)
{
  t_chan	*tmp;

  if (msg == NULL || client == NULL)
    return (false);
  if (get_nb_params(msg->params) != 2 && get_nb_params(msg->params) != 3)
    {
      dprintf(client->client, ERR_NEEDMOREPARAMS, S_NAME, S_ADDR, client->nick,
	      msg->command);
      return (false);
    }
  if ((tmp = find_chan(chans, msg->params[0])) == NULL)
    {
      dprintf(client->client, ERR_NOSUCHCHANNEL, S_NAME, S_ADDR, client->nick,
	      msg->params[0]);
      return (false);
    }
  if (is_in_chan(tmp->name, client) == false)
    {
      dprintf(client->client, ERR_NOTONCHANNEL, S_NAME, S_ADDR, client->nick,
	      msg->params[0]);
      return (false);
    }
  return (true);
}

void		cmd_kick(t_message *msg, t_client *client, t_chan **chans)
{
  t_chan	*channel;

  if (is_kick_valid(msg, client, *chans) == true)
    {
      channel = find_chan(*chans, msg->params[0]);
      if (is_chan_op(client, channel) == false)
	dprintf(client->client, ERR_CHANOPRIVSNEEDED, S_NAME, S_ADDR,
		client->nick, msg->params[0]);
      else
	{
	  if (msg->params[2] == NULL)
	    kick_user(msg, client, chans, NULL);
	  else
	    kick_user(msg, client, chans, msg->params[2]);
	}
    }
}
