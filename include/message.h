/*
** message.h for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 19 20:41:25 2015 zwertv_e
** Last update Sun Apr 19 23:04:57 2015 Antoine Plaskowski
*/

#ifndef		MESSAGE_H_
# define	MESSAGE_H_

# include	<stdbool.h>
# include	"parser.h"

typedef	struct	s_message	t_message;
typedef	struct	s_prefix	t_prefix;

struct		s_prefix
{
  char		*sender;
  char		*user;
  char		*host;
  bool		server;
};

struct		s_message
{
  t_prefix	prefix;
  char		*command;
  char		**params;
};

bool		message(t_message *message, char *str);
bool		set_prefix(t_message *message, t_parser *parser);
bool		set_command(t_message *message, t_parser *parser);
bool		set_params(t_message *message, t_parser *parser);
bool		aff_message(t_message *message, FILE *stream);

#endif		/* !MESSAGE_H_ */
