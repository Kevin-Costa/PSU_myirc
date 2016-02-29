/*
** main.c for main in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Mar 25 15:06:41 2015 Antoine Plaskowski
** Last update Mon Apr 27 17:31:39 2015 zwertv_e
*/

#include	<errno.h>
#include	<stddef.h>
#include	<stdbool.h>
#include	<signal.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/socket.h>
#include	<sys/select.h>
#include	"create_binded_socket.h"
#include	"accept_client.h"
#include	"fd_set.h"
#include	"client.h"
#include	"channels.h"
#include	"exec_cmd.h"
#include	"manage_select.h"

bool	g_keep_running = true;

static void	int_handler(int const signum)
{
  (void)signum;
  g_keep_running = false;
}

static int	init_socket(char const * const port)
{
  int		sfd;

  if (signal(SIGINT, int_handler) == SIG_ERR)
    perror("signal()");
  if ((sfd = create_binded_socket(NULL, port)) == -1)
    return (-1);
  if (listen(sfd, 42))
    {
      perror("listen()");
      return (-1);
    }
  return (sfd);
}

int		main(int argc, char **argv)
{
  fd_set	src;
  int		sfd;
  t_client	*clients;
  t_chan	*chans;

  if (argc != 2)
    {
      fprintf(stderr, "Usage: %s port\n", argv[0]);
      return (1);
    }
  if ((sfd = init_socket(argv[1])) == -1)
    return (1);
  clients = NULL;
  chans = NULL;
  manage_select(&src, sfd, clients, chans);
  fd_set_close(&src);
  return (0);
}
