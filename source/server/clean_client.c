/*
** clean_client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Apr 22 22:52:53 2015 zwertv_e
** Last update Fri Apr 24 21:24:48 2015 zwertv_e
*/

#include	<stdlib.h>
#include	"client.h"

t_client	*clean_client(t_client *clients)
{
  t_client	*res;

  res = clients;
  clients = first_node(&clients->node);
  while (clients != NULL)
    {
      if (clients->isAuth == -1)
	{
	  res = sup_node(&clients->node);
	  clients = res;
	}
      else
	clients = clients->node.next;
    }
  return (res);
}
