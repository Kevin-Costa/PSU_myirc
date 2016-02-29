/*
** cmd_list.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 19:35:23 2015 zwertv_e
** Last update Sun Apr 26 19:53:11 2015 zwertv_e
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdbool.h>
#include	"exec_cmd.h"
#include	"server.h"
#include	"rcode.h"
#include	"client.h"
#include	"channels.h"
#include	"message.h"

static void	send_filter_chans(t_client *client, t_chan *chans, char *dest)
{
  chans = find_chan(chans, dest);
  if (chans != NULL)
    {
      dprintf(client->client, RPL_LIST, S_NAME, S_ADDR,
	      client->nick, chans->name, "1", chans->topic);
    }
}

static void	send_all_chans(t_client *client, t_chan *chans)
{
  chans = first_node(&chans->node);
  while (chans != NULL)
    {
      dprintf(client->client, RPL_LIST, S_NAME, S_ADDR,
	      client->nick, chans->name, "1", chans->topic);
      chans = chans->node.next;
    }
  dprintf(client->client, RPL_LISTEND, S_NAME, S_ADDR, client->nick);
}

static bool	is_list_valid(t_message *msg, t_client *client)
{
  if (msg == NULL || client == NULL)
    return (false);
  return (true);
}

void		cmd_list(t_message *msg, t_client *client, t_chan *chans)
{
  char		*str;

  if (is_list_valid(msg, client) == true)
    {
      if (msg->params != NULL && msg->params[0] != NULL)
	{
	  str = strtok(msg->params[0], ",");
	    while (str != NULL)
	      {
		send_filter_chans(client, chans, str);
		str = strtok(NULL, ",");
	      }
	  dprintf(client->client, RPL_LISTEND, S_NAME, S_ADDR, client->nick);
	}
      else
	send_all_chans(client, chans);
    }
}
