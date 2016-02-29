/*
** client.h for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:20 2015 zwertv_e
** Last update Fri Apr 24 23:00:55 2015 zwertv_e
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# define	CNAME_SIZE	9
# define	CUSER_SIZE	512
# define	CRNAME_SIZE	512

typedef	struct	s_client	t_client;

# include	"cbuf.h"
# include	"channels.h"
# include	"node.h"

struct		s_client
{
  t_node	node;
  int		client;
  int		isAuth;
  bool		isOp;
  t_cbuf	cbuf;
  char		user[CUSER_SIZE + 1];
  char		rname[CRNAME_SIZE + 1];
  char		nick[CNAME_SIZE + 1];
  t_chan	*channels[MAX_CHANNELS];
};

int		len_client(t_client const *list);
t_client	*add_client(t_client *list, int const _client);
t_client	*remove_client(t_client *list, t_client *to_rem);
t_client	*remove_client_at(t_client *list, int const pos);
t_client	*remove_client_if(t_client *list, int (*fnc)(t_client *));
t_client	*find_client(t_client *list, int fd);
t_client	*clean_client(t_client *clients);

#endif		/* !CLIENT_H_ */
