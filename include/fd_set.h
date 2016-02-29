/*
** fd_set.h for fd_set in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Mar 25 15:51:29 2015 Antoine Plaskowski
** Last update Sat Apr 25 00:06:44 2015 zwertv_e
*/

#ifndef		FD_SET_H_
# define	FD_SET_H_

# include	<stdbool.h>
# include	<sys/select.h>
# include	"client.h"

int		fd_set_cpy(fd_set * const dest, fd_set const * const cpy);
int		fd_set_close(fd_set const * const fd_set);
int		fd_set_rclient(fd_set *fdset, t_client *client, int sfd);
bool		fd_set_wclient(fd_set *fdset, t_client *client);

#endif		/* !FD_SET_H_ */
