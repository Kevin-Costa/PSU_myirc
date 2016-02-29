/*
** cmd_users.c for cmd_users in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Apr 23 16:13:43 2015 Kevin Costa
** Last update Sun Apr 26 23:14:07 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"cmd_users.h"

void		cmd_users(char **com, int const cfd)
{
  char		*str;
  char		*save;

  if (com[1] == NULL)
    dprintf(cfd, "NAMES \r\n");
  else if (com[1] != NULL && com[2] == NULL)
    {
      if ((save = malloc(sizeof(char) * strlen(com[1] + 1))) == NULL)
	return;
      strcpy(save, com[1]);
      str = strtok(com[1], ",");
      while (str != NULL)
	str = strtok(NULL, ",");
      com[1] = save;
      dprintf(cfd, "NAMES :%s\r\n", com[1]);
    }
  else
    dprintf(1, "Wrong number of parameter for /users\n");
}
