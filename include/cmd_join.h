/*
** cmd_join.h for cmd_join in /home/costa_b/rendu/PSU_2014_myirc/include
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Wed Apr 22 15:17:50 2015 Kevin Costa
** Last update Fri Apr 24 16:57:44 2015 Kevin Costa
*/

#ifndef		CMD_JOIN_H_
# define	CMD_JOIN_H_

int		checkChanName(char *str);
int		cmd_join(char **com, int const cfd);

#endif		/* !CMD_JOIN_H_ */
