/*
** my_node.h for node in /home/plasko_a/projet/epitech/PSU_2014_myirc/include
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 10 15:31:31 2015 Antoine Plaskowski
** Last update Sat Apr 11 22:05:41 2015 Antoine Plaskowski
*/

#ifndef		NODE_H_
# define	NODE_H_

# include	<stddef.h>

typedef	struct	s_node	t_node;

struct		s_node
{
  void		*prev;
  void		*next;
};

void		*put_node(t_node *old, t_node *node);
void		free_node(t_node *node);
void		free_all_node(t_node *node);
void		*sup_node(t_node *node);
void		*sup_node_at(t_node *node, size_t const pos);
void		*first_node(t_node *node);
void		*last_node(t_node *node);
size_t		len_node(t_node *node);

#endif		/* !NODE_H_ */
