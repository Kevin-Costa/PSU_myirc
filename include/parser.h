/*
** parser.h for parser in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 15 09:46:51 2015 Antoine Plaskowski
** Last update Sun Apr 19 21:58:16 2015 Antoine Plaskowski
*/

#ifndef		PARSER_H_
# define	PARSER_H_

# include	<stdio.h>
# include	"node.h"
# include	"lexer.h"

typedef	enum	e_lexem_ter
  {
    NAME_SERVER = 1,
    PSEUDO = NAME_SERVER * 2,
    USER = PSEUDO * 2,
    HOST = USER * 2,
    COMMAND = HOST * 2,
    MIDDLE = COMMAND * 2,
    END = MIDDLE * 2
  }		t_lexem_ter;

typedef	struct	s_parser	t_parser;

struct		s_parser
{
  t_node	node;
  t_lexem_ter	lexem_ter;
  char		*str;
};

bool		aff_all_parser(t_parser *parser, FILE *stream);
char		*concat_lexem(t_lexer **lexer, t_lexem lexem);
t_parser	*parse(t_lexer *lexer);
t_parser	*prefix(t_lexer *lexer, t_parser *parser);
t_parser	*command(t_lexer *lexer, t_parser *parser);
t_parser	*params(t_lexer *lexer, t_parser *parser);

#endif		/* !PARSER_H_ */
