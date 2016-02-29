/*
** cmd_mp.c for cmd_mp in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Apr 23 16:25:00 2015 Kevin Costa
** Last update Sun Apr 26 22:58:57 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"cmd_join.h"
#include	"cmd_mp.h"

void		cmd_msg(char **com, int const cfd)
{
  char		*str;
  int		i;
  size_t	len;

  len = 0;
  for (i = 1; com[i] != NULL; i++)
    len += strlen(com[i]) + 1;
  if ((str = malloc(sizeof(char) * len)) == NULL)
    return;
  for (i = 1; com[i] != NULL; i++)
    {
      strcat(str, com[i]);
      if (com[i + 1] != NULL)
	strcat(str, " ");
    }
  if (com[0] != NULL && com[1] != NULL &&
      (com[0][0] == '&' || com[0][0] == '#'))
    dprintf(cfd, "PRIVMSG %s :%s\r\n", com[0], str);
  else
    dprintf(1, "Wrong number of arguments for /msg\n");
}

void		cmd_mp(char **com, int const cfd)
{
  char		*str;
  int		i;
  size_t	len;

  len = 0;
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
  if (com[1] != NULL && com[2] != NULL && ((com[1][0] >= 'a' &&
					    com[1][0] <= 'z') ||
					   (com[1][0] >= 'A' &&
					    com[1][0] <= 'Z')))
    dprintf(cfd, "PRIVMSG %s :%s\r\n", com[1], str);
  else
    dprintf(1, "Wrong number of arguments for /msg\n");
}
