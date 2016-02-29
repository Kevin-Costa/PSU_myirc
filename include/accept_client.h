/*
** accept_client.h for accept_client in /home/plasko_a/projet/epitech/PSU_2014_myftp
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Mar 11 06:50:08 2015 Antoine Plaskowski
** Last update Wed Mar 25 15:21:20 2015 Antoine Plaskowski
*/

#ifndef		ACCEPT_CLIENT_H_
# define	ACCEPT_CLIENT_H_

# include      <netinet/in.h>

typedef	struct		s_clientaddr	t_clientaddr;

typedef	union		u_sockaddr_in	t_sockaddr_in;
union			u_sockaddr_in
{
  struct sockaddr	base;
  struct sockaddr_in	ipv4;
  struct sockaddr_in6	ipv6;
};

struct			s_clientaddr
{
  int			cfd;
  t_sockaddr_in		addr;
};

char const	*get_addr(t_sockaddr_in const * const addr);
int		accept_client(int const sock, t_clientaddr *ca);

#endif		/* !ACCEPT_CLIENT_H_ */
