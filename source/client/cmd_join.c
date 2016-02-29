/*
** cmd_join.c for cmd_join in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Wed Apr 22 15:15:00 2015 Kevin Costa
** Last update Sun Apr 26 23:08:36 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"cmd_join.h"

int		checkChanName(char *str)
{
  if (str[0] != '#' && str[0] != '&' && str[0] != '0')
    {
      dprintf(1, "'%s' isn't a chan name\n", str);
      return (-1);
    }
  return (0);
}

int		cmd_join(char **com, int const cfd)
{
  char		*str;
  char		*save;

  if (com[1] != NULL)
    {
      if ((save = malloc(sizeof(char) * strlen(com[1] + 1))) == NULL)
	return (-1);
      strcpy(save, com[1]);
      str = strtok(com[1], ",");
      while (str != NULL)
	{
	  if (checkChanName(str) == -1)
	    return (-1);
	  str = strtok(NULL, ",");
	}
      com[1] = save;
      if (com[2] == NULL)
	dprintf(cfd, "JOIN :%s\r\n", com[1]);
      else
	dprintf(cfd, "JOIN %s :%s\r\n", com[1], com[2]);
    }
  return (0);
}
