/*
** cmd_kill.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 22:40:09 2015 zwertv_e
** Last update Sun Apr 26 22:58:03 2015 zwertv_e
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
      dprintf(tmp->client->client, ":%s!%s KILL %s :%s\r\n",
	      client->nick, client->user, to_kick->nick, reason);
      tmp = tmp->node.next;
    }
}

static void	kill_user(t_message *msg, t_client *client,
			  t_chan **chans, t_client *to_kill)
{
  size_t	i;

  i = 0;
  while (i < MAX_CHANNELS)
    {
      if (to_kill->channels[i] != NULL)
	{
	  send_msg(client, to_kill->channels[i], to_kill, msg->params[1]);
	  *chans = leave_chan(*chans, to_kill, to_kill->channels[i]->name);
	  to_kill->channels[i] = NULL;
	}
      ++i;
    }
  to_kill->isAuth = -1;
  close(to_kill->client);
}

static bool	is_op(t_client *client)
{
 if (client == NULL)
   return (false);
 if (client->isOp == true)
   return (true);
 return (false);
}

static bool	is_kill_valid(t_message *msg, t_client *client)
{
  if (msg == NULL || client == NULL)
    return (false);
  if (get_nb_params(msg->params) != 2)
    {
      dprintf(client->client, ERR_NEEDMOREPARAMS, S_NAME, S_ADDR, client->nick,
	      msg->command);
      return (false);
    }
  return (true);
}

void		cmd_kill(t_message *msg, t_client *client, t_chan **chans)
{
  t_client	*to_kill;

  if (is_kill_valid(msg, client) == true)
    {
      if (is_op(client) == false)
	dprintf(client->client, ERR_NOPRIVILEGES, S_NAME, S_ADDR,
		client->nick);
      else
	{
	  to_kill = first_node(&client->node);
	  while (to_kill != NULL && strcmp(to_kill->nick, msg->params[0]) != 0)
	    to_kill = to_kill->node.next;
	  if (to_kill == NULL)
	    dprintf(client->client, ERR_NOSUCHNICK, S_NAME, S_ADDR,
		    client->nick, msg->params[0]);
	  else
	    kill_user(msg, client, chans, to_kill);
	}
    }
}
