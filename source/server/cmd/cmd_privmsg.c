/*
** cmd_privmsg.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr 23 20:19:16 2015 zwertv_e
** Last update Wed Apr 29 11:40:31 2015 zwertv_e
*/

#include	<string.h>
#include	<stdlib.h>
#include	"message.h"
#include	"client.h"
#include	"channels.h"
#include	"rcode.h"
#include	"server.h"
#include	"exec_cmd.h"

static void	send_all(t_message *msg, t_client *client, t_client *dest)
{
  if (client->isOp == false)
    dprintf(client->client, ERR_NOSUCHNICK, S_NAME, S_ADDR,
	    client->nick, "*");
  else if (dest != NULL)
    {
      while (dest != NULL)
	{
	  if (dest != client)
	    dprintf(dest->client, ":%s!%s PRIVMSG %s :%s\r\n", client->nick,
		    client->user, dest->nick, msg->params[1]);
	  dest = dest->node.next;
	}
    }
  else
    dprintf(client->client, ERR_NOSUCHNICK, S_NAME, S_ADDR, client->nick,
	    msg->params[0]);
}

static void	send_all_chan(t_message *msg, t_client *client,
			      t_chan *dest)
{
  t_cclient	*tmp;

  if (client->isOp == false)
    dprintf(client->client, ERR_NOSUCHNICK, S_NAME, S_ADDR,
	    client->nick, "#");
  else if (dest != NULL)
    {
      tmp = first_node(&dest->clients->node);
      while (tmp != NULL)
	{
	  if (tmp->client != client)
	    dprintf(tmp->client->client, ":%s!%s PRIVMSG %s :%s\r\n",
		    client->nick, client->user, dest->name, msg->params[1]);
	  tmp = tmp->node.next;
	}
      send_all_chan(msg, client, dest->node.next);
    }
}

static void	send_chan(t_message *msg, t_client *client,
			  t_chan *dest)
{
  t_cclient	*tmp;

  if (dest != NULL)
    {
      if (is_in_chan(dest->name, client) == false)
        dprintf(client->client, ERR_CANNOTSENDTOCHAN, S_NAME, S_ADDR,
		client->nick, dest->name);
      else
	{
	  tmp = first_node(&dest->clients->node);
	  while (tmp != NULL)
	    {
	      if (tmp->client != client)
		dprintf(tmp->client->client, ":%s!%s PRIVMSG %s :%s\r\n",
			client->nick, client->user, dest->name, msg->params[1]);
	      tmp = tmp->node.next;
	    }
	}
    }
  else
    dprintf(client->client, ERR_NOSUCHNICK, S_NAME, S_ADDR,
	    client->nick, msg->params[0]);
}

static void	send_privmsg(t_message *msg, char *dest,
			     t_client *client, t_chan *chans)
{
  t_client	*tmpclient;

  if (strcmp(dest, "#*") == 0)
    send_all_chan(msg, client, first_node(&chans->node));
  else if (strcmp(dest, "*") == 0)
    send_all(msg, client, first_node(&client->node));
  else
    {
      if (strncmp(dest, "#", 1) == 0)
	send_chan(msg, client, find_chan(chans, dest));
      else
	{
	  tmpclient = first_node(&client->node);
	  while (tmpclient != NULL && strcmp(tmpclient->nick, dest) != 0)
	    tmpclient = tmpclient->node.next;
	  if (tmpclient == NULL)
	    dprintf(client->client, ERR_NOSUCHNICK, S_NAME, S_ADDR,
		    client->nick, dest);
	  else
	    dprintf(tmpclient->client, ":%s!%s PRIVMSG %s :%s\r\n",
		    client->nick, client->user, tmpclient->nick,
		    msg->params[1]);
	}
    }
}

void		cmd_privmsg(t_message *msg, t_client *client, t_chan *chans)
{
  char		*str;

  if (msg == NULL || client == NULL)
    return;
  if (get_nb_params(msg->params) < 1)
    {
      dprintf(client->client, ERR_NORECIPIENT, S_NAME, S_ADDR,
	      client->nick, msg->command);
      return;
    }
  else if (get_nb_params(msg->params) != 2)
    {
      dprintf(client->client, ERR_NOTEXTTOSEND, S_NAME, S_ADDR,
	      client->nick);
      return;
    }
  str = strtok(msg->params[0], ",");
  while (str != NULL)
    {
      send_privmsg(msg, str, client, chans);
      str = strtok(NULL, ",");
    }
}
