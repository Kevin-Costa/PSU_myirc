/*
** reg_cmp.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr 23 18:29:21 2015 zwertv_e
** Last update Thu Apr 23 19:41:15 2015 zwertv_e
*/

#include	<sys/types.h>
#include	<regex.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	"exec_cmd.h"

bool		reg_cmp(const char *str, const char *pattern)
{
  regex_t	preg;
  int		err;
  int		match;

  err = regcomp(&preg, pattern, REG_EXTENDED);
  if (err != 0)
    return (false);
  match = regexec(&preg, str, 0, NULL, 0);
  regfree(&preg);
  if (match == REG_NOMATCH)
    return (false);
  return (true);
}
