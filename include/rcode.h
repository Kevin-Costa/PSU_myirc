/*
** rcode.h for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Apr 15 09:24:05 2015 zwertv_e
** Last update Sun Apr 26 22:42:44 2015 zwertv_e
*/

#ifndef		RCODE_H_
# define	RCODE_H_

/*
** Good messages
*/

# define	RPL_WELCOME	":%s@%s 001 %s :Welcome to the Internet \
Relay Network %s!%s\r\n"
# define	RPL_YOURHOST	":%s@%s 002 %s :Your host is %s, running \
version %s\r\n"
# define	RPL_CREATED	":%s@%s 003 %s :This server was created \
%s\r\n"
# define	RPL_MYINFO	":%s@%s 004 %s :%s %s o 0\r\n"
# define	RPL_LIST	":%s@%s 322 %s %s %s :%s\r\n"
# define	RPL_LISTEND	":%s@%s 323 %s :End of LIST\r\n"
# define	RPL_NOTOPIC	":%s@%s 331 %s %s :No topic is set\r\n"
# define	RPL_TOPIC	":%s@%s 332 %s %s :%s\r\n"
# define	RPL_NAMREPLY	":%s@%s 353 %s %s %s :"
# define	RPL_ENDOFNAMES	":%s@%s 366 %s %s :End of NAMES list\r\n"

/*
** Bad messages
*/

# define	ERR_NOSUCHNICK		":%s@%s 401 %s %s :No such \
nick/channel\r\n"
# define	ERR_NOSUCHCHANNEL	":%s@%s 403 %s %s :No such \
channel\r\n"
# define	ERR_CANNOTSENDTOCHAN	":%s@%s 404 %s %s :Cannot send \
to channel\r\n"
# define	ERR_TOOMANYCHANNELS	":%s@%s 405 %s %s :You have joined \
too many channels\r\n"
# define	ERR_NORECIPIENT		":%s@%s 411 %s :No recipient given \
(%s)\r\n"
# define	ERR_NOTEXTTOSEND	":%s@%s 412 %s :No text to \
send\r\n"
# define	ERR_NONICKNAMEGIVEN	":%s@%s 431 %s :No nickname \
given\r\n"
# define	ERR_ERRONEUSNICKNAME	":%s@%s 432 %s %s :Erroneous \
nickname\r\n"
# define	ERR_NICKNAMEINUSE	":%s@%s 433 %s %s :Nickname is \
already in use\r\n"
# define	ERR_UNAVAILRESOURCE	":%s@%s 437 %s %s :Nick/channel \
is temporarily unavailable\r\n"
# define	ERR_NOTONCHANNEL	":%s@%s 442 %s %s :You're not on \
that channel\r\n"
# define	ERR_UNKNOWNCOMMAND	":%s@%s 451 %s %s :Unknown \
command\r\n"
# define        ERR_NOTREGISTERED	":%s@%s 451 %s :You have not \
registered\r\n"
# define	ERR_NEEDMOREPARAMS	":%s@%s 461 %s %s :Not enough \
parameters\r\n"
# define	ERR_ALREADYREGISTRED	":%s@%s 462 %s :Unauthorized \
command (already registered)\r\n"
# define	ERR_NOPRIVILEGES	":%s@%s 481 %s :Permission \
Denied- You're not an IRC operator\r\n"
# define	ERR_CHANOPRIVSNEEDED	":%s@%s 482 %s %s :You're not \
channel operator\r\n"

#endif
