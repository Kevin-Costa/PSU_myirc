/*
** lexer.h for lexer in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 12 07:48:13 2015 Antoine Plaskowski
** Last update Wed Apr 22 21:51:22 2015 Antoine Plaskowski
*/

#ifndef		LEXER_H_
# define	LEXER_H_

# include	<stdio.h>
# include	<regex.h>
# include	<stdbool.h>
# include	"node.h"

typedef	enum	e_lexem
  {
    COLON = 1,
    SPACE = COLON * 2,
    EXCLAMATION_MARK = SPACE * 2,
    AT = EXCLAMATION_MARK * 2,
    CRLF = AT * 2,
    STRING = CRLF * 2
  }		t_lexem;

typedef	struct	s_lexer	t_lexer;

struct		s_lexer
{
  t_node	node;
  t_lexem	lexem;
  char		*str;
};

struct          s_tab
{
  t_lexem const	lexem;
  char const	*regex;
  regex_t	preg;
  regmatch_t	pmatch;
};

t_lexer		*lex(char const *to_lex);
void		*free_all_lexer(t_lexer *lexer);
bool		aff_all_lexer(t_lexer *lexer, FILE *stream);

#endif		/* !LEXER_H_ */
