/*
** get_nb_params.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Apr 22 21:04:29 2015 zwertv_e
** Last update Wed Apr 22 21:10:18 2015 zwertv_e
*/

#include	<stdlib.h>
#include	"exec_cmd.h"

size_t		get_nb_params(char **params)
{
  size_t	res;

  res = 0;
  if (params == NULL)
    return (res);
  while (params[res] != NULL)
    ++res;
  return (res);
}
