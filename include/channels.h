/*
** channels.h for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Apr 10 15:15:00 2015 zwertv_e
** Last update Wed Apr 29 11:33:35 2015 zwertv_e
*/

#ifndef		CHANNELS_H_
# define	CHANNELS_H_

# include	<stdbool.h>

# define	MAX_CHANNELS	10
# define	CHAN_SIZE	200
# define	TOPIC_SIZE	512

typedef struct	s_chan		t_chan;
typedef struct	s_cclient	t_cclient;

# include	"node.h"
# include	"client.h"

struct		s_cclient
{
  t_node	node;
  bool		isOp;
  t_client	*client;
};

struct		s_chan
{
  t_node	node;
  char		name[CHAN_SIZE + 1];
  char		topic[TOPIC_SIZE + 1];
  t_cclient	*clients;
};

bool		is_in_chan(const char *chanName, t_client *client);
size_t		get_nb_chans(t_client *client);
t_chan		*add_chan(t_chan *list, const char *name);
t_chan		*join_chan(t_chan *list, t_client *client,
			   const char *chanName);
t_chan		*leave_chan(t_chan *list, t_client *client,
			    const char *chaName);
t_chan		*find_chan(t_chan *chan, char const *name);

#endif		/* !CHANNELS_H_ */
