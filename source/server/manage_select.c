/*
** manage_select.c for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 18:38:07 2015 zwertv_e
** Last update Wed Apr 29 11:36:31 2015 zwertv_e
*/

#include	"manage_select.h"

static int	read_client(fd_set const * const set_read, int client,
			    int const client_max, t_client **clients)
{
  t_client	*tmp;
  int		res;

  res = 1;
  while (client <= client_max)
    {
      if (FD_ISSET(client, set_read))
	{
	  res = 0;
	  if ((tmp = find_client((*clients), client)) != NULL)
	    if (write_cbuf(tmp->client, &tmp->cbuf) <= 0)
	      (*clients) = sup_node(&tmp->node);
	}
      client++;
    }
  return (res);
}

static void	write_client(fd_set const * const set_write,
			     t_client **clients, t_chan **chans)
{
  t_client	*tmp;

  tmp = *clients;
  tmp = first_node(&tmp->node);
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->client, set_write))
	{
	  exec_client(*clients, chans);
	  *clients = clean_client(tmp);
	  tmp = *clients;
	}
      if (tmp != NULL)
	tmp = tmp->node.next;
    }
}

int	manage_select(fd_set *set_read, int const sfd,
			      t_client *clients, t_chan *chans)
{
  fd_set	set_write;
  t_clientaddr	ca;
  int		client_max;

  while (g_keep_running == true)
    {
      client_max = fd_set_rclient(set_read, clients, sfd);
      fd_set_wclient(&set_write, clients);
      if (select(client_max + 1, set_read, &set_write, NULL, NULL) == -1)
	{
	  perror("select()");
	  return (1);
	}
      if (FD_ISSET(sfd, set_read))
	{
	  if (accept_client(sfd, &ca) == -1)
	    return (1);
	  clients = add_client(clients, ca.cfd);
	}
      read_client(set_read, sfd + 1, client_max, &clients);
      write_client(&set_write, &clients, &chans);
    }
  return (0);
}
