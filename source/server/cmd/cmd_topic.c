/*
** cmd_topic.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 20:50:15 2015 zwertv_e
** Last update Wed Apr 29 11:41:25 2015 zwertv_e
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

static void	set_topic(t_message *msg, t_client *client, t_chan *chan)
{
  t_cclient	*tmp;

  strncpy(chan->topic, msg->params[1], TOPIC_SIZE);
  chan->topic[TOPIC_SIZE] = '\0';
  tmp = chan->clients;
  tmp = first_node(&tmp->node);
  while (tmp != NULL)
    {
      dprintf(tmp->client->client, ":%s!%s TOPIC %s :%s\r\n", client->nick,
	      client->user, chan->name, chan->topic);
      tmp = tmp->node.next;
    }
}

static void	display_topic(t_client *client, t_chan *chan)
{
  if (chan != NULL)
    {
      if (chan->topic[0] == '\0')
	dprintf(client->client, RPL_NOTOPIC, S_NAME, S_ADDR,
		client->nick, chan->name);
      else
	{
	  dprintf(client->client, RPL_TOPIC, S_NAME, S_ADDR,
		  client->nick, chan->name, chan->topic);
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

static bool	is_topic_valid(t_message *msg, t_client *client, t_chan *chans)
{
  t_chan	*tmp;

  if (msg == NULL || client == NULL)
    return (false);
  if (get_nb_params(msg->params) != 1 && get_nb_params(msg->params) != 2)
    {
      dprintf(client->client, ERR_NEEDMOREPARAMS, S_NAME, S_ADDR, client->nick,
	      msg->command);
      return (false);
    }
  if ((tmp = find_chan(chans, msg->params[0])) == NULL)
    {
      dprintf(client->client, ERR_NOTONCHANNEL, S_NAME, S_ADDR, client->nick,
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

void		cmd_topic(t_message *msg, t_client *client, t_chan *chans)
{
  t_chan	*channel;

  if (is_topic_valid(msg, client, chans) == true)
    {
      channel = find_chan(chans, msg->params[0]);
      if (is_chan_op(client, channel) == false)
	dprintf(client->client, ERR_CHANOPRIVSNEEDED, S_NAME, S_ADDR,
		client->nick, msg->params[0]);
      else
	{
	  if (get_nb_params(msg->params) == 1)
	    display_topic(client, channel);
	  else
	    set_topic(msg, client, channel);
	}
    }
}
