/*
** cmd_part.c for cmd_part in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Wed Apr 22 15:38:50 2015 Kevin Costa
** Last update Wed Apr 22 15:40:54 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"cmd_part.h"

void		cmd_part(char **com, int const cfd)
{
  if (com[1] != NULL && com[2] == NULL)
    dprintf(cfd, "PART :%s\r\n", com[1]);
  else
    dprintf(1, "Wrong number of arguments for /part\n");
}
