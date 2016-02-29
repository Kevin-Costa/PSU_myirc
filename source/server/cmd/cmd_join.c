/*
** cmd_join.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Apr 21 22:45:26 2015 zwertv_e
** Last update Wed Apr 29 11:40:55 2015 zwertv_e
*/

#include	<stdio.h>
#include	<string.h>
#include	"message.h"
#include	"client.h"
#include	"channels.h"
#include	"rcode.h"
#include	"server.h"
#include	"exec_cmd.h"

static void	join_zero(t_client *client, t_chan **chans)
{
  size_t	i;
  t_cclient	*tmp;

  i = 0;
  while (i < MAX_CHANNELS)
    {
      if (client->channels[i] != NULL)
	{
	  tmp = first_node(&client->channels[i]->clients->node);
	  while (tmp != NULL)
	    {
	      dprintf(tmp->client->client, ":%s!%s PART %s :Left all channels\r\n",
		      client->nick, client->user, client->channels[i]->name);
	      tmp = tmp->node.next;
	    }
	  *chans = leave_chan(*chans, client, client->channels[i]->name);
	  client->channels[i] = NULL;
	}
      ++i;
    }
}

static void	send_client_chan_infos(t_client *client, t_chan *joined)
{
  t_cclient	*tmp;
  t_cclient	*tmp2;

  if (joined->topic[0] == '\0')
    dprintf(client->client, RPL_NOTOPIC, S_NAME, S_ADDR,
	    client->nick, joined->name);
  else
    dprintf(client->client, RPL_TOPIC, S_NAME, S_ADDR,
	    client->nick, joined->name, joined->topic);
  if ((tmp = first_node(&joined->clients->node)) != NULL)
    dprintf(client->client, RPL_NAMREPLY, S_NAME, S_ADDR,
	    client->nick, "=", joined->name);
  tmp2 = tmp;
  if (tmp != NULL)
    display_cclient(client, tmp, false);
  while (tmp != NULL)
    {
      tmp = tmp->node.next;
      if (tmp != NULL)
        display_cclient(client, tmp, true);
    }
  if (tmp2 != NULL)
    dprintf(client->client, "\r\n");
  dprintf(client->client, RPL_ENDOFNAMES, S_NAME, S_ADDR,
	  client->nick, joined->name);
}

static void	cmd_chan(t_client *client, const char *chanName, t_chan **chans)
{
  t_chan	*joined;
  t_cclient	*tmp;

  if (get_nb_chans(client) == MAX_CHANNELS)
    {
      dprintf(client->client, ERR_TOOMANYCHANNELS, S_NAME, S_ADDR,
	      client->nick, chanName);
      return;
    }
  *chans = join_chan(*chans, client, chanName);
  if ((joined = find_chan(*chans, chanName)) != NULL)
    {
      tmp = first_node(&joined->clients->node);
      while (tmp != NULL)
	{
	  dprintf(tmp->client->client, ":%s@%s JOIN :%s\r\n", client->nick,
		  client->user, chanName);
	  tmp = tmp->node.next;
	}
      send_client_chan_infos(client, joined);
    }
  else
    dprintf(client->client, ERR_UNAVAILRESOURCE, S_NAME, S_ADDR,
	    client->nick, chanName);
}

void		cmd_join(t_message *msg, t_client *client, t_chan **chans)
{
  char		*str;

  if (msg == NULL || client == NULL)
    return;
  if (get_nb_params(msg->params) != 1 && get_nb_params(msg->params) != 2)
    {
      dprintf(client->client, ERR_NEEDMOREPARAMS, S_NAME, S_ADDR,
	      client->nick, "JOIN");
      return;
    }
  str = strtok(msg->params[0], ",");
  while (str != NULL)
    {
      if (strcmp(str, "0") == 0)
	join_zero(client, chans);
      else if (strncmp(str, "#", 1) != 0 && strncmp(str, "&", 1) != 0)
	dprintf(client->client, ERR_NOSUCHCHANNEL, S_NAME, S_ADDR,
		client->nick, str);
      else if (is_in_chan(str, client) == false)
	cmd_chan(client, str, chans);
      str = strtok(NULL, ",");
    }
}
