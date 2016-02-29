##
## source_server.mk for source_server in /home/plasko_a/projet/epitech/PSU_2014_myftp
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Wed Mar 11 06:38:52 2015 Antoine Plaskowski
## Last update Sun Apr 26 22:39:38 2015 zwertv_e
##

PATH_SRC	=	source/
PATH_SERVER	=	$(PATH_SRC)server/
PATH_CMD	=	$(PATH_SERVER)cmd/

SRC_SERVER	+=	$(PATH_SERVER)main.c
SRC_SERVER	+=	$(PATH_SERVER)manage_select.c
SRC_SERVER	+=	$(PATH_SERVER)client.c
SRC_SERVER	+=	$(PATH_SERVER)clean_client.c
SRC_SERVER	+=	$(PATH_SERVER)cbuf.c
SRC_SERVER	+=	$(PATH_SERVER)channels.c
SRC_SERVER	+=	$(PATH_SERVER)find_channels.c
SRC_SERVER	+=	$(PATH_SERVER)exec_cmd.c
SRC_SERVER	+=	$(PATH_SERVER)exec_client.c
SRC_SERVER	+=	$(PATH_SERVER)fd_set_client.c
SRC_SERVER	+=	$(PATH_SERVER)get_nb_chans.c

SRC_SERVER	+=	$(PATH_CMD)get_nb_params.c
SRC_SERVER	+=	$(PATH_CMD)reg_cmp.c
SRC_SERVER	+=	$(PATH_CMD)display_cclient.c
SRC_SERVER	+=	$(PATH_CMD)cmd_ping.c
SRC_SERVER	+=	$(PATH_CMD)cmd_user.c
SRC_SERVER	+=	$(PATH_CMD)cmd_nick.c
SRC_SERVER	+=	$(PATH_CMD)cmd_privmsg.c
SRC_SERVER	+=	$(PATH_CMD)cmd_quit.c
SRC_SERVER	+=	$(PATH_CMD)cmd_join.c
SRC_SERVER	+=	$(PATH_CMD)cmd_part.c
SRC_SERVER	+=	$(PATH_CMD)cmd_list.c
SRC_SERVER	+=	$(PATH_CMD)cmd_names.c
SRC_SERVER	+=	$(PATH_CMD)cmd_topic.c
SRC_SERVER	+=	$(PATH_CMD)cmd_kick.c
SRC_SERVER	+=	$(PATH_CMD)cmd_kill.c
