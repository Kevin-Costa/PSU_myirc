/*
** display_cclient.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 20:27:47 2015 zwertv_e
** Last update Sun Apr 26 20:35:50 2015 zwertv_e
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"client.h"
#include	"channels.h"
#include	"exec_cmd.h"

void	display_cclient(t_client *client, t_cclient *display,
			bool wspace)
{
  if (client != NULL)
    {
      if (display->client->isOp)
	{
	  if (wspace)
	    dprintf(client->client, " %s%s", "+", display->client->nick);
	  else
	    dprintf(client->client, "%s%s", "+", display->client->nick);
	}
      else if (display->isOp)
	{
	  if (wspace)
	    dprintf(client->client, " %s%s", "@", display->client->nick);
	  else
	    dprintf(client->client, "%s%s", "@", display->client->nick);
	}
      else
	{
	  if (wspace)
	    dprintf(client->client, " %s%s", "", display->client->nick);
	  else
	    dprintf(client->client, "%s%s", "", display->client->nick);
	}
    }
}
