/*
** client_com.c for client_com in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Fri Apr 17 16:18:11 2015 Kevin Costa
** Last update Sun Apr 26 23:02:14 2015 Kevin Costa
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"create_connected_socket.h"
#include	"client_com.h"
#include	"my_str_to_word_tab.h"
#include	"fdgetline.h"

int		client_connect(void)
{
  char		**com;
  int		cfd;
  char		*str;
  size_t	i;

  dprintf(1, UPROMPT);
  if ((str = fdgetline(0)) == NULL)
    return (-2);
  i = strlen(str);
  if (i > 0)
    str[i - 1] = '\0';
  com = my_str_to_wordtab(str);
  if (com[0] != NULL)
    {
      if (strcmp(com[0], "/server") == 0 && com[2] == NULL)
	return (((cfd = create_connected_socket(com[1], "4242")) == -1)
		? -1 : cfd);
      if (strcmp(com[0], "/server") == 0)
	return (((cfd = create_connected_socket(com[1], com[2])) == -1)
		? -1 : cfd);
      else
	dprintf(1, "You are not connected\n");
    }
  return (-1);
}
