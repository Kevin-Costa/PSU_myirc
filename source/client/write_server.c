/*
** write_server.c for write_server in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Apr 23 14:30:45 2015 Kevin Costa
** Last update Thu Apr 23 15:35:15 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<string.h>
#include	"my_str_to_word_tab.h"
#include	"my_cmd.h"
#include	"write_server.h"
#include	"fdgetline.h"
#include	"client_com.h"

int		write_server(int const cfd)
{
  char		**com;
  char		*str;
  size_t	i;

  if ((str = fdgetline(0)) == NULL)
    return (-1);
  i = strlen(str);
  if (i > 0)
    str[i - 1] = '\0';
  com = my_str_to_wordtab(str);
  if (com[0] != NULL)
    {
      if (my_cmd(com, cfd) == -1)
	{
	  dprintf(1, "%s", UPROMPT);
	  return (-1);
	}
    }
  dprintf(1, "%s", UPROMPT);
  return (0);
}
