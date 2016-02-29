/*
** main.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Apr 22 21:13:58 2015 zwertv_e
** Last update Wed Apr 29 11:42:50 2015 zwertv_e
*/

#include	<stdio.h>
#include	<signal.h>
#include	<unistd.h>
#include	<stdbool.h>
#include	<stdlib.h>
#include	<sys/select.h>
#include	<string.h>
#include	"create_connected_socket.h"
#include	"fd_set.h"
#include	"cbuf.h"
#include	"client_com.h"
#include	"ping.h"
#include	"my_fd.h"
#include	"write_server.h"

static bool	g_keep_running = true;

static void	int_handler(int const signum)
{
  (void)signum;
  g_keep_running = false;
}

static int	manage_select(fd_set const * const src, int const cfd)
{
  fd_set	set_read;
  fd_set	set_write;
  t_cbuf	cbuf;
  char		*str;

  set_cbuf(&cbuf);
  while (g_keep_running == true)
    {
      fd_set_cpy(&set_read, src);
      fd_set_cpy(&set_write, src);
      if (select(cfd + 1, &set_read, &set_write, NULL, NULL) == -1)
	selectError();
      if (FD_ISSET(cfd, &set_read))
      	  if (write_cbuf(cfd, &cbuf) <= 0)
	    writeBuf();
      my_fd(cfd, set_read);
      if (is_cbuf_ready(&cbuf) == 0)
	{
	  str = read_cbuf(&cbuf);
	  ping(cfd, str);
	}
    }
  return (0);
}

int		main(int argc, char **argv)
{
  fd_set	src;
  int		cfd;

  if (argc != 1 && argc != 3)
    {
      fprintf(stderr, "Usage: %s\nUsage: %s <ip> <port>\n", argv[0], argv[0]);
      return (1);
    }
  if (signal(SIGINT, int_handler) == SIG_ERR)
    perror("signal()");
  if (argc == 1)
    while ((cfd = client_connect()) == -1);
  else
    cfd = create_connected_socket(argv[1], argv[2]);
  if (cfd == -2 || cfd == -1)
    return (-1);
  dprintf(1, "Client connected\n");
  FD_ZERO(&src);
  FD_SET(cfd, &src);
  FD_SET(0, &src);
  dprintf(1, UPROMPT);
  return (manage_select(&src, cfd));
}
