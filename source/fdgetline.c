/*
** fdgetline.c for fdgetline in /home/plasko_a/projet/epitech/PSU_2014_myftp
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 12 01:39:33 2015 Antoine Plaskowski
** Last update Wed Apr 29 11:30:09 2015 zwertv_e
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		<stdio.h>
#include		<string.h>
#include		"stdbool.h"
#include		"fdgetline.h"

static bool		read_fd(char buf[BUF_SIZE], size_t * const i,
				ssize_t * const max, int const fd)
{
  if (*i < (size_t)*max)
    return (true);
  *i = 0;
  if ((*max = read(fd, buf, BUF_SIZE)) > 0)
    return (true);
  else if (*max == -1)
    perror("read()");
  *max = 0;
  return (false);
}

char			*fdgetline(int const fd)
{
  static char		buf[BUF_SIZE];
  static size_t		i = 0;
  static ssize_t	max = 0;
  size_t		n;
  size_t		l;
  char			*p;

  p = NULL;
  l = 0;
  while (read_fd(buf, &i, &max, fd) == true)
    {
      n = 0;
      while (i + n < (size_t)max && buf[i + n] != '\n')
	n++;
      if ((p = realloc(p, l + (n < (size_t)max ? n + 1 : n) + 1)) == NULL ||
	  memcpy(p + l, buf + i, (n < (size_t)max ? n + 1 : n)) == NULL)
	return (NULL);
      i += n < (size_t)max ? n + 1 : n;
      l += n < (size_t)max ? n + 1 : n;
      p[l] = '\0';
      if (n < (size_t)max)
	return (p);
    }
  return (p);
}
