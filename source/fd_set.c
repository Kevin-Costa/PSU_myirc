/*
** fd_set.c for fd_set in /home/plasko_a/programation/epitech/socket/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jul 28 17:09:12 2014 Antoine Plaskowski
** Last update Fri Mar 27 03:49:40 2015 Antoine Plaskowski
*/

#include	<sys/select.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"fd_set.h"

int		fd_set_cpy(fd_set * const dest, fd_set const * const cpy)
{
  int		i;

  if (dest == NULL || cpy == NULL)
    return (1);
  i = 0;
  while (i < FD_SETSIZE)
    {
      if (FD_ISSET(i, cpy))
	FD_SET(i, dest);
      else
	FD_CLR(i, dest);
      i++;
    }
  return (0);
}

int		fd_set_close(fd_set const * const fd_set)
{
  int		i;

  if (fd_set == NULL)
    return (1);
  i = 0;
  while (i < FD_SETSIZE)
    {
      if (FD_ISSET(i, fd_set))
	close(i);
      i++;
    }
  return (0);
}
