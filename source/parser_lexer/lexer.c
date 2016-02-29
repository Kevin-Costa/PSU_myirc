/*
** lexer.c for lexer in /home/plasko_a/projet/epitech/PSU_2014_myirc/source/parser
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 12 07:47:50 2015 Antoine Plaskowski
** Last update Wed Apr 22 21:50:34 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	<regex.h>
#include	<string.h>
#include	"lexer.h"

static struct s_tab	g_tab[] =
  {
    {.lexem = COLON, .regex = "^:"},
    {.lexem = SPACE, .regex = "^ +"},
    {.lexem = EXCLAMATION_MARK, .regex = "^!"},
    {.lexem = AT, .regex = "^@"},
    {.lexem = CRLF, .regex = "^\r\n"},
    {.lexem = STRING, .regex = "^[^ \r\n]+"}
  };

static size_t const	g_size_tab = sizeof(g_tab) / sizeof(*g_tab);

static void	err_regex(regex_t *preg, int const err)
{
  char		*strerr;
  size_t	len;

  len = regerror (err, preg, NULL, 0);
  if ((strerr = malloc (sizeof(*strerr) * len)) != NULL)
    {
      regerror(err, preg, strerr, len);
      fprintf(stderr, "%s\n", strerr);
      free(strerr);
    }
}

static void	free_regex(void)
{
  size_t	i;

  i = 0;
  while (i < g_size_tab)
    {
      regfree(&g_tab[i].preg);
      i++;
    }
}

static bool	init_regex(void)
{
  size_t	i;
  int		err;

  i = 0;
  while (i < g_size_tab)
    {
      if ((err = regcomp(&g_tab[i].preg, g_tab[i].regex, REG_EXTENDED)) != 0)
	{
	  err_regex(&g_tab[i].preg, err);
	  return (true);
	}
      i++;
    }
  atexit(&free_regex);
  return (false);
}

static t_lexer	*match_regex(char const *to_lex, size_t const i)
{
  t_lexer	*lexer;
  int		match;

  if (i >= g_size_tab)
    return (NULL);
  match = regexec (&g_tab[i].preg, to_lex, 1, &g_tab[i].pmatch, 0);
  if (match != 0)
    return (match_regex(to_lex, i + 1));
  if ((lexer = malloc(sizeof(*lexer))) == NULL)
    return (NULL);
  lexer->lexem = g_tab[i].lexem;
  lexer->str = strndup(to_lex, g_tab[i].pmatch.rm_eo - g_tab[i].pmatch.rm_so);
  return (lexer);
}

t_lexer		*lex(char const *to_lex)
{
  static bool	regex_to_init = true;
  t_lexer	*lexer;
  t_lexer	*tmp;

  if (regex_to_init == true && (regex_to_init = init_regex()) == true)
    return (NULL);
  lexer = NULL;
  while (*to_lex != '\0')
    {
      if ((tmp = match_regex(to_lex, 0)) == NULL)
	return (free_all_lexer(lexer));
      lexer = put_node(&lexer->node, &tmp->node);
      to_lex += strlen(tmp->str);
    }
  return (lexer);
}
