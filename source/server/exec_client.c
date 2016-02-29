/*
** exec_client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 19 20:41:51 2015 zwertv_e
** Last update Wed Apr 29 11:35:10 2015 zwertv_e
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"client.h"
#include	"lexer.h"
#include	"parser.h"
#include	"message.h"
#include	"exec_cmd.h"

void		exec_client(t_client *client, t_chan **chans)
{
  t_message	msg;
  char		*str;

  client = first_node(&client->node);
  while (client != NULL)
    {
      while (is_cbuf_ready(&client->cbuf) == 0)
	{
	  if ((str = read_cbuf(&client->cbuf)) != NULL)
	    {
	      message(&msg, str);
	      if (msg.command != NULL)
		dprintf(1, "Recieved [%s] from [%s]\n",
			msg.command, client->nick);
	      exec_cmd(&msg, client, chans);
	      free(str);
	    }
	}
      client = client->node.next;
    }
}
