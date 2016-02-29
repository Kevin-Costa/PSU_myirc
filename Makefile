##
## Makefile for myirc in /home/plasko_a/projet/epitech/PSU_2014_myirc
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Wed Mar 11 02:10:40 2015 Antoine Plaskowski
## Last update Fri Apr 24 22:48:48 2015 Antoine Plaskowski
##

CLIENT		=	client

SERVER		=	server

CC		?=	gcc

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

RM		=	rm

LIB		=

INCLUDE		=	-I include/

CFLAGS		=	-Wall -Wextra -O$(LEVEL)
CFLAGS		+=	-D _POSIX_SOURCE -D _GNU_SOURCE
CFLAGS		+=	$(INCLUDE)

ifeq ($(CC), clang)
CFLAGS		+=	-Weverything -Wno-padded -Wno-disabled-macro-expansion
endif

ifneq ($(DEBUG), no)
CFLAGS		+=	-g
endif

ifneq ($(COLOR), no)
CFLAGS		+=	-fdiagnostics-color
endif

LDFLAGS		=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

SRC		=
SRC_SERVER	=
SRC_CLIENT	=

include			source.mk
include			source_$(CLIENT).mk
include			source_$(SERVER).mk

OBJ		=	$(SRC:.c=.o)
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

DPD		=	$(SRC:.c=.dpd)
DPD_CLIENT	=	$(SRC_CLIENT:.c=.dpd)
DPD_SERVER	=	$(SRC_SERVER:.c=.dpd)

all		:	$(SERVER) $(CLIENT)

$(SERVER)	:	$(OBJ) $(OBJ_SERVER)
			$(CC) $(OBJ) $(OBJ_SERVER) -o $(SERVER) $(LDFLAGS)

$(CLIENT)	:	$(OBJ) $(OBJ_CLIENT)
			$(CC) $(OBJ) $(OBJ_CLIENT) -o $(CLIENT) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ)
			$(RM) -f $(OBJ_SERVER)
			$(RM) -f $(OBJ_CLIENT)
			$(RM) -f $(DPD)
			$(RM) -f $(DPD_CLIENT)
			$(RM) -f $(DPD_SERVER)

fclean		:	clean
			$(RM) -f $(SERVER)
			$(RM) -f $(CLIENT)

re		:	fclean all

%.dpd		:	%.c
			@$(CC) -MM $< -o $@ $(CFLAGS) -MT $(<:.c=.o)

%.o		:	%.c
			$(CC) -c $< -o $@ $(CFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.c

-include		$(DPD) $(DPD_CLIENT) $(DPD_SERVER)
