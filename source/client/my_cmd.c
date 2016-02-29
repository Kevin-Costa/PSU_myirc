/*
** my_cmd.c for my_cmd in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Wed Apr 22 17:50:25 2015 Kevin Costa
** Last update Sun Apr 26 23:23:36 2015 Kevin Costa
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"my_cmd.h"
#include	"cmd_user.h"
#include	"cmd_users.h"
#include	"cmd_nick.h"
#include	"cmd_join.h"
#include	"cmd_part.h"
#include	"cmd_list.h"
#include	"cmd_quit.h"
#include	"cmd_topic.h"
#include	"cmd_kick.h"
#include	"cmd_kill.h"
#include	"cmd_mp.h"

int		my_cmd(char **com, int const cfd)
{
  if (strcmp(com[0], "/user") == 0)
    cmd_user(com, cfd);
  else if (strcmp(com[0], "/nick") == 0)
    cmd_nick(com, cfd);
  else if (strcmp(com[0], "/join") == 0)
    {
      if (cmd_join(com, cfd) == -1)
	return (-1);
    }
  else
    my_cmd2(com, cfd);
  return (0);
}

void		my_cmd2(char **com, int const cfd)
{
  if (strcmp(com[0], "/part") == 0)
    cmd_part(com, cfd);
  else if (strcmp(com[0], "/list") == 0)
    cmd_list(com, cfd);
  else if (strcmp(com[0], "/quit") == 0)
    cmd_quit(com, cfd);
  else if (strcmp(com[0], "/users") == 0)
    cmd_users(com, cfd);
  else if (strcmp(com[0], "/msg") == 0)
    cmd_mp(com, cfd);
  else if (strcmp(com[0], "/topic") == 0)
    cmd_topic(com, cfd);
  else if (strcmp(com[0], "/kick") == 0)
    cmd_kick(com, cfd);
  else if (strcmp(com[0], "/kill") == 0)
    cmd_kill(com, cfd);
  else if (strcmp(com[0], "/ping") == 0)
    dprintf(cfd, "PING \r\n");
  else
    cmd_msg(com, cfd);
}
