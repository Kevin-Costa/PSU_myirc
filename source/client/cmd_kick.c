/*
** cmd_kick.c for cmd_kick in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Sun Apr 26 22:01:35 2015 Kevin Costa
** Last update Wed Apr 29 15:58:47 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"cmd_kick.h"

void		cmd_kick(char **com, int const cfd)
{
  char		*str;
  int		i;
  size_t	len;

  len = 0;
  if (com[1] == NULL || com[2] == NULL)
    {
      dprintf(1, "Wrong number of arguments for /kick\n");
      return;
    }
  for (i = 3; com[i] != NULL; i++)
    len += strlen(com[i]) + 1;
  if ((str = malloc(sizeof(char) * len)) == NULL)
    return;
  for (i = 3; com[i] != NULL; i++)
    {
      strcat(str, com[i]);
      if (com[i + 1] != NULL)
	strcat(str, " ");
    }
  if (com[1] != NULL && (com[1][0] == '&' || com[1][0] == '#')
      && com[2] != NULL && com[3] == NULL)
    dprintf(cfd, "KICK %s :%s\r\n", com[1], com[2]);
  else if (com[1] != NULL && (com[1][0] == '&'|| com[1][0] == '#')
      && com[2] != NULL && com[3] != NULL)
    dprintf(cfd, "KICK %s %s :%s\r\n", com[1], com[2], str);
  else
    dprintf(1, "Your channel doesn't exist\n");
}
