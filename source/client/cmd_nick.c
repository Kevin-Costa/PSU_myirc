/*
** cmd_nick.c for cmd_nick in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Wed Apr 22 15:10:37 2015 Kevin Costa
** Last update Wed Apr 22 15:39:00 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"cmd_nick.h"

void		cmd_nick(char **com, int const cfd)
{
  if (com[1] != NULL && com[2] == NULL)
    dprintf(cfd, "NICK :%s\r\n", com[1]);
  else
    dprintf(1, "Wrong number of arguments for /nick\n");
}
