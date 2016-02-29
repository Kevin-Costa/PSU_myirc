/*
** get_nb_chans.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Apr 22 20:05:04 2015 zwertv_e
** Last update Wed Apr 22 20:06:16 2015 zwertv_e
*/

#include	"client.h"
#include	"channels.h"

size_t		get_nb_chans(t_client *client)
{
  size_t	i;
  size_t	nb;

  if (client == NULL)
    return (0);
  i = 0;
  nb = 0;
  while (i < MAX_CHANNELS)
    {
      if (client->channels[i] != NULL)
	++nb;
      ++i;
    }
  return (nb);
}
