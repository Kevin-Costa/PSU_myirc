/*
** my_str_to_word_tab.c for my_str_to_word_tab in /home/costa_b/rendu/PSU_2014_myirc/source/client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Thu Apr 16 00:32:51 2015 Kevin Costa
** Last update Sun Apr 26 22:56:20 2015 Kevin Costa
*/

#include	<stdlib.h>
#include	"my_str_to_word_tab.h"

size_t		my_nb_word(char *str)
{
  size_t	i;

  i = 0;
  while (*str)
    {
      while (*str == ' ' || *str == '\t' || *str == ':')
	str++;
      if (*str != ' ' && *str != '\t' && *str != '\0' &&  *str != ':')
	i++;
      while (*str != ' ' && *str != '\t' && *str != '\0' &&  *str != ':')
	str++;
    }
  return (i + 1);
}

size_t		my_nb_letter(char *str)
{
  size_t	i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != ':')
    i++;
  return (i + 1);
}

char		**my_str_to_wordtab(char *str)
{
  char		**wordtab;
  size_t	i;
  size_t	j;

  if (str == NULL)
    return (NULL);
  if ((wordtab = malloc(sizeof(char *) * my_nb_word(str))) == NULL)
    return (NULL);
  i = 0;
  while (*str)
    {
      while (*str == ' ' || *str == '\t' || *str == ':')
	str++;
      if (*str != ' ' && *str != '\t' && *str != '\0' &&  *str != ':')
	{
	  if ((wordtab[i] = malloc(sizeof(char) * my_nb_letter(str))) == NULL)
	    return (NULL);
	  j = 0;
	  while (*str != ' ' && *str != '\t' && *str != '\0' &&  *str != ':')
	    wordtab[i][j++] = *str++;
	  wordtab[i++][j] = '\0';
	}
    }
  wordtab[i] = NULL;
  return (wordtab);
}
