/*
** my_fd.h for my_fd in /home/costa_b/rendu/PSU_2014_myirc/include
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Apr 23 14:24:39 2015 Kevin Costa
** Last update Thu Apr 23 16:06:12 2015 Kevin Costa
*/

#ifndef		MY_FD_H_
# define	MY_FD_H_

void		my_fd(int const cfd, fd_set set_read);
int		selectError(void);
int		writeBuf(void);

#endif		/* !MY_FD_H_ */
