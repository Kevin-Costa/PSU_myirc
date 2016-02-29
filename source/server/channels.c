/*
** channels.c for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 12 06:22:46 2015 zwertv_e
** Last update Wed Apr 29 11:34:39 2015 zwertv_e
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"channels.h"

t_chan		*add_chan(t_chan *list, const char *name)
{
  t_chan	*new;

  if (name == NULL)
    return (list);
  if (find_chan(list, name) != NULL)
    return (list);
  if ((new = malloc(sizeof(t_chan))) == NULL)
    return (list);
  strncpy(new->name, name, CHAN_SIZE);
  new->name[CHAN_SIZE] = '\0';
  new->topic[0] = '\0';
  new->clients = NULL;
  return (put_node(&list->node, &new->node));
}

bool		is_in_chan(const char *chanName, t_client *client)
{
  size_t	i;

  if (chanName == NULL || client == NULL)
    return (false);
  i = 0;
  while (i < MAX_CHANNELS)
    {
      if (client->channels[i] != NULL && \
	  strcmp((client->channels[i])->name, chanName) == 0)
	return (true);
      ++i;
    }
  return (false);
}

static void	add_channel_to_client(t_client *client, t_chan *to_join)
{
  size_t	i;

  i = 0;
  while (i < MAX_CHANNELS)
    {
      if (client->channels[i] == NULL)
	{
	  client->channels[i] = to_join;
	  i = MAX_CHANNELS;
	}
      ++i;
    }
}

t_chan		*join_chan(t_chan *list, t_client *client, const char *chanName)
{
  t_chan	*to_join;
  t_cclient	*ncclient;

  if (client == NULL || chanName == NULL || (ncclient = \
					     malloc(sizeof(t_cclient))) == NULL)
    return (list);
  list = add_chan(list, chanName);
  to_join = find_chan(list, chanName);
  if (to_join == NULL || is_in_chan(to_join->name, client) == true)
    {
      free(ncclient);
      return (list);
    }
  ncclient->client = client;
  ncclient->isOp = false;
  if (to_join->clients == NULL)
    ncclient->isOp = true;
  add_channel_to_client(client, to_join);
  if (to_join->clients == NULL)
    to_join->clients = put_node(NULL, &ncclient->node);
  else
    to_join->clients = put_node(&to_join->clients->node, &ncclient->node);
  return (list);
}

t_chan		*leave_chan(t_chan *list, t_client *client, const char *chaName)
{
  size_t	i;
  t_cclient	*tmp;
  t_chan	*to_rm;

  if (list == NULL || client == NULL || chaName == NULL)
    return (list);
  if (is_in_chan(chaName, client) != true)
    return (list);
  if ((to_rm = find_chan(list, chaName)) == NULL)
    return (list);
  i = 0;
  while (i < MAX_CHANNELS)
    {
      if (client->channels[i] == to_rm)
	client->channels[i] = NULL;
      ++i;
    }
  tmp = first_node(&to_rm->clients->node);
  while (tmp != NULL && tmp->client != client)
    tmp = tmp->node.next;
  if (tmp != NULL)
    to_rm->clients = sup_node(&tmp->node);
  if (to_rm->clients == NULL)
    list = sup_node(&to_rm->node);
  return (list);
}
