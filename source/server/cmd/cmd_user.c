/*
** cmd_user.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 19 18:02:51 2015 zwertv_e
** Last update Wed Apr 29 11:38:11 2015 zwertv_e
*/

#include	<stdio.h>
#include	<string.h>
#include	"client.h"
#include	"channels.h"
#include	"message.h"
#include	"rcode.h"
#include	"server.h"
#include	"exec_cmd.h"

static void	check_op(t_client *client)
{
  if (strcmp(client->user, "Admin") == 0)
    client->isOp = true;
}

static void	auth_client(t_client *client)
{
  client->isAuth = 3;
  dprintf(client->client, RPL_WELCOME, S_NAME, S_ADDR, \
	  client->nick, client->nick, client->user);
  dprintf(client->client, RPL_YOURHOST, S_NAME, S_ADDR, \
	  client->nick, S_NAME, S_VERSION);
  dprintf(client->client, RPL_CREATED, S_NAME, S_ADDR, \
	  client->nick, S_CREADATE);
  dprintf(client->client, RPL_MYINFO, S_NAME, S_ADDR, \
	  client->nick, S_NAME, S_VERSION);
}

void		cmd_user(t_message *msg, t_client *client)
{
  if (msg == NULL || client == NULL)
    return;
  if (get_nb_params(msg->params) != 4)
    {
      dprintf(client->client, ERR_NEEDMOREPARAMS, S_NAME, S_ADDR, \
	      client->nick, "USER");
      return;
    }
  if (client->isAuth >= 3 || client->isAuth == 1)
    {
      dprintf(client->client, ERR_ALREADYREGISTRED, S_NAME, S_ADDR, \
	      client->nick);
      return;
    }
  strcpy(client->user, msg->params[0]);
  strcpy(client->rname, msg->params[3]);
  if (client->isAuth == 0)
    client->isAuth = 1;
  else if (client->isAuth == 2)
    auth_client(client);
  check_op(client);
}
