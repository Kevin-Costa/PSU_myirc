/*
** cmd_kill.c for cmd_kill in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Sun Apr 26 22:14:01 2015 Kevin Costa
** Last update Wed Apr 29 15:54:32 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"cmd_kill.h"

void		cmd_kill(char **com, int const cfd)
{
  char		*str;
  int		i;
  size_t	len;

  len = 0;
  if (com[1] == NULL)
    {
      dprintf(1, "Wrong number of arguments for /kill\n");
      return;
    }
  for (i = 2; com[i] != NULL; i++)
    len += strlen(com[i]) + 1;
  if ((str = malloc(sizeof(char) * len)) == NULL)
    return;
  for (i = 2; com[i] != NULL; i++)
    {
      strcat(str, com[i]);
      if (com[i + 1] != NULL)
	strcat(str, " ");
    }
  if (com[1] != NULL && com[2] != NULL)
    dprintf(cfd, "KILL %s :%s\r\n", com[1], str);
  else
    dprintf(1, "Wrong number of arguments for /kill\n");
}
