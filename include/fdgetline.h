/*
** fdgetline.h for fdgetline in /home/plasko_a/projet/epitech/PSU_2014_myftp
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 12 02:51:42 2015 Antoine Plaskowski
** Last update Sun Mar 22 17:30:50 2015 Antoine Plaskowski
*/

#ifndef		FDGETLINE_H_
# define	FDGETLINE_H_

# include	<unistd.h>

# define	BUF_SIZE	(4096)

char		*fdgetline(int const fd);

#endif		/* !FDGETLINE_H_ */
