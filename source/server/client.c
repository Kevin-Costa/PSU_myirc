/*
** client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:00 2015 zwertv_e
** Last update Wed Apr 29 11:39:12 2015 zwertv_e
*/

#include	<stdlib.h>
#include	"client.h"
#include	"cbuf.h"

t_client	*add_client(t_client *list, int _fd)
{
  t_client	*new;
  size_t	i;

  i = 0;
  if (_fd < 0)
    return (list);
  if ((new = malloc(sizeof(t_client))) == NULL)
    return (NULL);
  new->client = _fd;
  new->isAuth = 0;
  new->isOp = false;
  new->nick[0] = '\0';
  new->user[0] = '\0';
  new->rname[0] = '\0';
  while (i < MAX_CHANNELS)
    {
      new->channels[i] = NULL;
      ++i;
    }
  set_cbuf(&new->cbuf);
  return (put_node(&list->node, &new->node));
}

t_client	*remove_client_if(t_client *list, int (*fnc)(t_client *))
{
  t_client	*ret;

  list = first_node(&list->node);
  ret = list;
  while (list != NULL)
    {
      if ((*fnc)(list) == 0)
	{
	  list = sup_node(&list->node);
	  ret = list;
	}
      else
	list = list->node.next;
    }
  return (first_node(&ret->node));
}

static t_client	*rec_find_client(t_client *client, int _fd)
{
  if (client == NULL)
    return (client);
  else if (client->client == _fd)
    return (client);
  return (rec_find_client(client->node.next, _fd));
}

t_client	*find_client(t_client *list, int _fd)
{
  if (list == NULL || _fd < 1)
    return (list);
  list = first_node(&list->node);
  return (rec_find_client(list, _fd));
}
