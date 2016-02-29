/*
** find_channels.c for find_channels in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 12 08:27:56 2015 Antoine Plaskowski
** Last update Sun Apr 12 08:47:28 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	"channels.h"

static t_chan	*rec_find_chan(t_chan *chan, char const *name)
{
  if (chan == NULL)
    return (NULL);
  else if (strcmp(chan->name, name) == 0)
    return (chan);
  else
    return (rec_find_chan(chan->node.next, name));
}

t_chan		*find_chan(t_chan *chan, char const *name)
{
  if (name == NULL)
    return (NULL);
  else
    return (rec_find_chan(first_node(&chan->node), name));
}
