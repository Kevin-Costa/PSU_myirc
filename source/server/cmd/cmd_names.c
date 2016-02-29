/*
** cmd_names.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 20:03:07 2015 zwertv_e
** Last update Sun Apr 26 20:34:03 2015 zwertv_e
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdbool.h>
#include	"client.h"
#include	"channels.h"
#include	"server.h"
#include	"rcode.h"
#include	"message.h"
#include	"exec_cmd.h"

static void	names_all(t_client *client, t_chan *chans)
{
  t_cclient	*tmp;
  t_cclient	*tmp2;

  chans = first_node(&chans->node);
  while (chans != NULL)
    {
      if ((tmp = first_node(&chans->clients->node)) != NULL)
	dprintf(client->client, RPL_NAMREPLY, S_NAME, S_ADDR,
		client->nick, "=", chans->name);
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
	      client->nick, chans->name);
      chans = chans->node.next;
    }
}

static void	names_filter(t_client *client, t_chan *chans, char *dest)
{
  t_cclient	*tmp;
  t_cclient	*tmp2;

  chans = find_chan(chans, dest);
  if (chans != NULL)
    {
      if ((tmp = first_node(&chans->clients->node)) != NULL)
	dprintf(client->client, RPL_NAMREPLY, S_NAME, S_ADDR,
		client->nick, "=", chans->name);
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
	      client->nick, chans->name);
    }
}

static bool	is_names_valid(t_message *msg, t_client *client)
{
  if (msg == NULL || client == NULL)
    return (false);
  return (true);
}

void		cmd_names(t_message *msg, t_client *client, t_chan *chans)
{
  char		*str;

  if (is_names_valid(msg, client) == true)
    {
      if (msg->params != NULL && msg->params[0] != NULL)
	{
	  str = strtok(msg->params[0], ",");
	  while (str != NULL)
	    {
	      names_filter(client, chans, str);
	      str = strtok(NULL, ",");
	    }
	}
      else
	names_all(client, chans);
    }
}
