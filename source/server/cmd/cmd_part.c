/*
** cmd_part.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Apr 24 22:46:13 2015 zwertv_e
** Last update Wed Apr 29 11:41:09 2015 zwertv_e
*/

#include	<stdlib.h>
#include	<string.h>
#include	"exec_cmd.h"
#include	"client.h"
#include	"channels.h"
#include	"rcode.h"
#include	"server.h"

static void	part_client(t_client *client, t_chan *to_rm, t_chan **chans)
{
  size_t	i;
  t_cclient	*tmp;
  int		tmp_fd;

  i = 0;
  while (i < MAX_CHANNELS)
    {
      if (client->channels[i] == to_rm)
	{
	  tmp = first_node(&client->channels[i]->clients->node);
	  while (tmp != NULL)
	    {
	      tmp_fd = tmp->client->client;
	      dprintf(tmp_fd, ":%s!%s PART %s :Leaving channel\r\n",
		      client->nick, client->user, client->channels[i]->name);
	      tmp = tmp->node.next;
	    }
	  *chans = leave_chan(*chans, client, client->channels[i]->name);
	  client->channels[i] = NULL;
	}
      ++i;
    }
}

static bool	part_chan(t_client *client, char *dest, t_chan **chans)
{
  t_chan	*to_rm;

  if (strchr("#&", dest[0]) == NULL)
    {
      dprintf(client->client, ERR_NOSUCHCHANNEL, S_NAME, S_ADDR,
	      client->nick, dest);
      return (false);
    }
  if ((to_rm = find_chan(*chans, dest)) == NULL)
    {
      dprintf(client->client, ERR_NOSUCHCHANNEL, S_NAME, S_ADDR,
	      client->nick, dest);
      return (false);
    }
  if (is_in_chan(dest, client) == false)
    {
      dprintf(client->client, ERR_NOTONCHANNEL, S_NAME, S_ADDR,
	      client->nick, dest);
      return (false);
    }
  part_client(client, to_rm, chans);
  return (true);
}

static bool	is_cmd_valid(t_message *msg, t_client *client, t_chan *chans)
{
  if (msg == NULL || client == NULL || chans == NULL)
    return (false);
  if (get_nb_params(msg->params) != 1)
    {
      dprintf(client->client, ERR_NEEDMOREPARAMS, S_NAME, S_ADDR,
	      client->nick, msg->command);
      return (false);
    }
  return (true);
}

void		cmd_part(t_message *msg, t_client *client, t_chan **chans)
{
  char		*str;

  if (is_cmd_valid(msg, client, *chans) == true)
    {
      str = strtok(msg->params[0], ",");
      while (str != NULL)
	{
	  part_chan(client, str, chans);
	  str = strtok(NULL, ",");
	}
    }
}
