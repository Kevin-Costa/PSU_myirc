/*
** ping.c for ping in /home/costa_b/rendu/PSU_2014_myirc
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Apr 23 14:17:08 2015 Kevin Costa
** Last update Thu Apr 23 15:32:12 2015 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"cbuf.h"
#include	"ping.h"
#include	"client_com.h"

void		ping(int const cfd, char *str)
{
  dprintf(1, "\r%s", str);
  if (strncmp("PING", str, 4) == 0)
    {
      str[1] = 'O';
      dprintf(cfd, "%s", str);
      dprintf(1, "%s", str);
    }
  dprintf(1, "%s", UPROMPT);
  free(str);
}
