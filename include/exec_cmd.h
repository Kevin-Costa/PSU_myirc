/*
** exec_cmd.h for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 12 17:00:25 2015 zwertv_e
** Last update Sun Apr 26 22:39:58 2015 zwertv_e
*/

#ifndef		EXEC_CMD_H_
# define	EXEC_CMD_H_

# include	"message.h"
# include	"client.h"
# include	"channels.h"

void		exec_client(t_client *client, t_chan **chans);
void		exec_cmd(t_message *msg, t_client *client, t_chan **chans);

void		cmd_ping(t_client *client);
void		cmd_nick(t_message *msg, t_client *client);
void		cmd_user(t_message *msg, t_client *client);
void		cmd_privmsg(t_message *msg, t_client *client, t_chan *chans);
void		cmd_list(t_message *msg, t_client *client, t_chan *chans);
void		cmd_names(t_message *msg, t_client *client, t_chan *chans);
void		cmd_topic(t_message *msg, t_client *client, t_chan *chans);
void		cmd_join(t_message *msg, t_client *client, t_chan **chans);
void		cmd_quit(t_message *msg, t_client *client, t_chan **chans);
void		cmd_part(t_message *msg, t_client *client, t_chan **chans);
void		cmd_kick(t_message *msg, t_client *client, t_chan **chans);
void		cmd_kill(t_message *msg, t_client *client, t_chan **chans);

void		display_cclient(t_client *client, t_cclient *display,
				bool wspace);
size_t		get_nb_params(char **params);
bool		reg_cmp(const char *str, const char *pattern);

#endif
