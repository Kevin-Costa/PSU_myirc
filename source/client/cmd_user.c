/*
** cmd_user.c for cmd_user in /home/costa_b/rendu/PSU_2014_myirc
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Wed Apr 22 15:01:39 2015 Kevin Costa
** Last update Sun Apr 26 22:57:12 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"cmd_user.h"

void		cmd_user(char **com, int const cfd)
{
  char		*str;
  int		i;
  size_t	len;

  len = 0;
  for (i = 2; com[i] != NULL; i++)
    len += strlen(com[i]) + 1;
  str = malloc(sizeof(char) * len);
  for (i = 2; com[i] != NULL; i++)
    {
      strcat(str, com[i]);
      if (com[i + 1] != NULL)
	strcat(str, " ");
    }
  if (com[1] != NULL && com[2] != NULL)
    dprintf(cfd, "USER %s 0 * :%s\r\n", com[1], str);
  else
    dprintf(1, "Missing argument for /user\n");
}
