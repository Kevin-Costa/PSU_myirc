/*
** cmd_topic.c for cmd_topic in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Sun Apr 26 21:39:32 2015 Kevin Costa
** Last update Sun Apr 26 23:22:02 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"cmd_topic.h"

void		cmd_topic(char **com, int const cfd)
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
  if (com[1] != NULL && com[2] == NULL)
    dprintf(cfd, "TOPIC :%s\r\n", com[1]);
  else if (com[1] != NULL && (com[1][0] == '&' || com[1][0] == '#'))
    dprintf(cfd, "TOPIC %s :%s\r\n", com[1], str);
  else
    dprintf(1, "Wrong number of arguments for /topic\n");
}
