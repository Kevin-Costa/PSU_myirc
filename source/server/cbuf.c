/*
** cbuf.c for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 19:39:37 2015 zwertv_e
** Last update Wed Apr 29 11:39:45 2015 zwertv_e
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"cbuf.h"

int		set_cbuf(t_cbuf *cbuf)
{
  if (cbuf == NULL)
    return (1);
  cbuf->r = 0;
  cbuf->w = 0;
  cbuf->moreTurn = 0;
  return (0);
}

static size_t	find_rlen(t_cbuf *cbuf)
{
  size_t	len;
  size_t	i;
  int		run;

  i = cbuf->r;
  run = 1;
  len = 0;
  while (run != 0)
    {
      if (run == 2 && cbuf->head[i] == '\n')
	run = 0;
      if (run != 0)
	run = 1;
      if (run != 0 && cbuf->head[i] == '\r')
	run = 2;
      if (run != 0)
	++len;
      ++i;
      if (i >= CBUF_LEN)
	i = 0;
      if (len > CBUF_LEN)
	return (0);
    }
  len = (len > 0) ? (len + 1) : (len);
  return (len);
}

int		is_cbuf_ready(t_cbuf *cbuf)
{
  if (cbuf == NULL)
    return (1);
  if (cbuf->r == cbuf->w && cbuf->moreTurn == 0)
    return (1);
  if (find_rlen(cbuf) == 0)
    return (1);
  return (0);
}

char		*read_cbuf(t_cbuf *cbuf)
{
  char		*res;
  size_t	len;
  size_t	i;

  if (cbuf == NULL || is_cbuf_ready(cbuf) == 1)
    return (NULL);
  len = find_rlen(cbuf);
  if (len == 0 || (res = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < len)
    {
      res[i] = cbuf->head[cbuf->r];
      cbuf->head[cbuf->r] = '\0';
      ++i;
      ++cbuf->r;
      if (cbuf->r >= CBUF_LEN)
	{
	  cbuf->r = 0;
	  cbuf->moreTurn = 0;
	}
    }
  res[i] = '\0';
  return (res);
}

ssize_t		write_cbuf(int fd, t_cbuf *cbuf)
{
  static char	buffer[CBUF_LEN];
  ssize_t	i;
  size_t	j;

  if ((i = read(fd, buffer, CBUF_LEN)) <= 0)
    return (i);
  j = 0;
  while (j < (size_t)i)
    {
      cbuf->head[cbuf->w] = buffer[j];
      if (cbuf->moreTurn == 1 && cbuf->w == cbuf->r)
	++cbuf->r;
      ++cbuf->w;
      if (cbuf->w >= CBUF_LEN)
	{
	  if (cbuf->moreTurn == 0)
	    cbuf->moreTurn = 1;
	  else
	    cbuf->r = 0;
	  cbuf->w = 0;
	}
      ++j;
    }
  return (i);
}
