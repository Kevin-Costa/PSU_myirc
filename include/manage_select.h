/*
** manage_select.h for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 18:38:58 2015 zwertv_e
** Last update Sun Apr 26 18:59:12 2015 zwertv_e
*/

#ifndef		MANAGE_SELECT_H_
# define	MANAGE_SELECT_H_

# include	<errno.h>
# include	<stddef.h>
# include	<stdbool.h>
# include	<signal.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<sys/socket.h>
# include	<sys/select.h>
# include	"create_binded_socket.h"
# include	"accept_client.h"
# include	"fd_set.h"
# include	"client.h"
# include	"channels.h"
# include	"exec_cmd.h"
# include	"server.h"

int	manage_select(fd_set *set_read, int const sfd,
		      t_client *clients, t_chan *chans);

#endif		/* MANAGE_SELECT_H_ */
