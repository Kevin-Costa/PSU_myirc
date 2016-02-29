/*
** my_fd.c for my_fd in /home/costa_b/rendu/PSU_2014_myirc
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Apr 23 14:22:59 2015 Kevin Costa
** Last update Thu Apr 23 16:04:35 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"write_server.h"
#include	"fd_set.h"
#include	"cbuf.h"
#include	"my_fd.h"

void		my_fd(int const cfd, fd_set set_read)
{
  if (FD_ISSET(0, &set_read))
    write_server(cfd);
}

int		writeBuf(void)
{
  dprintf(2, "\rConnection closed\n");
  exit(1);
}

int		selectError(void)
{
  perror("select()");
  exit(1);
}
