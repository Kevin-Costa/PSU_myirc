/*
** cmd_list.c for cmd_list in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Wed Apr 22 17:44:16 2015 Kevin Costa
** Last update Sun Apr 26 21:39:40 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"cmd_list.h"

void		cmd_list(char **com, int const cfd)
{
  if (com[1] != NULL && com[2] == NULL)
    dprintf(cfd, "LIST :%s\r\n", com[1]);
  else if (com[1] == NULL)
    dprintf(cfd, "LIST \r\n");
  else
    dprintf(1, "Wrong number of arguments for /list\n");
}
