/*
** cmd_quit.c for cmd_quit in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Apr 23 13:42:57 2015 Kevin Costa
** Last update Sun Apr 26 22:58:27 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"cmd_quit.h"

void		cmd_quit(char **com, int const cfd)
{
  char		*str;
  int		i;
  size_t	len;

  len = 0;
  for (i = 1; com[i] != NULL; i++)
    len += strlen(com[i]) + 1;
  str = malloc(sizeof(char) * len);
  for (i = 1; com[i] != NULL; i++)
    {
      strcat(str, com[i]);
      if (com[i + 1] != NULL)
	strcat(str, " ");
    }
  if (com[1] == NULL)
    dprintf(cfd, "QUIT \r\n");
  else if (com[1] != NULL)
    dprintf(cfd, "QUIT :%s\r\n", str);
  else
    dprintf(1, "Wrong number of arguments for /quit\n");
}
