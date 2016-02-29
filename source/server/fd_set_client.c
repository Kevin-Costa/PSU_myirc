/*
** fd_set_client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Apr 17 16:38:47 2015 zwertv_e
** Last update Wed Apr 29 11:35:48 2015 zwertv_e
*/

#include	<sys/select.h>
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	"client.h"
#include	"fd_set.h"

bool		fd_set_wclient(fd_set *fdset, t_client *client)
{
  client = first_node(&client->node);
  if (fdset == NULL)
    return (false);
  FD_ZERO(fdset);
  while (client != NULL)
    {
      if (is_cbuf_ready(&client->cbuf) == 0)
	FD_SET(client->client, fdset);
      client = client->node.next;
    }
  return (true);
}

int		fd_set_rclient(fd_set *fdset, t_client *client, int sfd)
{
  int		max_fd;

  max_fd = sfd;
  client = first_node(&client->node);
  if (fdset == NULL)
    return (max_fd);
  FD_ZERO(fdset);
  if (sfd != -1)
    FD_SET(sfd, fdset);
  while (client != NULL)
    {
      if (client->client > max_fd)
	max_fd = client->client;
      FD_SET(client->client, fdset);
      client = client->node.next;
    }
  return (max_fd);
}
