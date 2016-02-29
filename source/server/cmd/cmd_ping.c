/*
** cmd_ping.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 21:41:44 2015 zwertv_e
** Last update Sun Apr 26 23:16:26 2015 zwertv_e
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<stdbool.h>
#include	"client.h"
#include	"server.h"
#include	"rcode.h"
#include	"exec_cmd.h"

void		cmd_ping(t_client *client)
{
  if (client != NULL)
    dprintf(client->client, ":%s@%s PONG :%s\r\n", S_NAME,
	    S_ADDR, client->nick);
}
