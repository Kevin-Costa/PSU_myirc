/*
** cbuf.h for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 19:40:08 2015 zwertv_e
** Last update Wed Apr 29 11:31:54 2015 zwertv_e
*/

#ifndef CBUF_H_
# define CBUF_H_

# include	<unistd.h>

# define	CBUF_LEN	512

typedef	struct	s_cbuf
{
  char		head[CBUF_LEN];
  size_t	r;
  size_t	w;
  int	        moreTurn;
}		t_cbuf;

int		set_cbuf(t_cbuf *cbuf);
int		is_cbuf_ready(t_cbuf *cbuf);
ssize_t		write_cbuf(int fd, t_cbuf *cbuf);
char		*read_cbuf(t_cbuf *cbuf);

#endif
