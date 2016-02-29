/*
** cmd_nick.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 19 17:49:47 2015 zwertv_e
** Last update Sun Apr 26 18:42:28 2015 zwertv_e
*/

#include	<sys/types.h>
#include	<regex.h>
#include	<stdio.h>
#include	<string.h>
#include	"client.h"
#include	"message.h"
#include	"rcode.h"
#include	"server.h"
#include	"exec_cmd.h"

static void	authClient(t_client *client)
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

static void	cmd_user_all(t_client *client, const char *old, const char *new)
{
  t_cclient	*tmp;
  size_t	i;

  i = 0;
  while (i < MAX_CHANNELS)
    {
      if (client->channels[i] != NULL)
	{
	  tmp = first_node(&client->channels[i]->clients->node);
	  while (tmp != NULL)
	    {
	      if (tmp->client != client)
		dprintf(tmp->client->client, ":%s NICK :%s\r\n", old, new);
	      tmp = tmp->node.next;
	    }
	}
      ++i;
    }
  if (client->isAuth >= 3)
    dprintf(client->client, ":%s NICK :%s\r\n", old, new);
}

static bool	isNickTaken(t_client *list, char *str)
{
  list = first_node(&list->node);
  if (list == NULL)
    return (false);
  while (list != NULL)
    {
      if (strcmp(list->nick, str) == 0)
	return (true);
      list = list->node.next;
    }
  return (false);
}

static bool	is_nick_valid(t_message *msg, t_client *client)
{
  if (msg == NULL || client == NULL)
    return (false);
  if (get_nb_params(msg->params) != 1)
    {
      dprintf(client->client, ERR_NONICKNAMEGIVEN, S_NAME, S_ADDR,
	      client->nick);
      return (false);
    }
  if (reg_cmp(msg->params[0], "^[a-zA-Z][]^a-zA-Z0-9[`\{}-]*") == false)
    {
      dprintf(client->client, ERR_ERRONEUSNICKNAME, S_NAME, S_ADDR,
	      client->nick, msg->params[0]);
      return (false);
    }
  if (isNickTaken(client, msg->params[0]) == true)
    {
      dprintf(client->client, ERR_NICKNAMEINUSE, S_NAME, S_ADDR,
	      client->nick, msg->params[0]);
      return (false);
    }
  return (true);
}

void		cmd_nick(t_message *msg, t_client *client)
{
  if (is_nick_valid(msg, client) == true)
    {
      cmd_user_all(client, client->nick, msg->params[0]);
      strncpy(client->nick, msg->params[0], CNAME_SIZE);
      client->nick[CNAME_SIZE] = '\0';
      if (client->isAuth == 0)
	client->isAuth = 2;
      else if (client->isAuth == 1)
	authClient(client);
    }
}
