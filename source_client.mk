##
## source_client.mk for source_client in /home/plasko_a/projet/epitech/PSU_2014_myftp
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Wed Mar 11 06:38:52 2015 Antoine Plaskowski
## Last update Sun Apr 26 22:15:28 2015 Kevin Costa
##

PATH_SRC	=	source/
PATH_CLIENT	=	$(PATH_SRC)client/

SRC_CLIENT	+=	$(PATH_CLIENT)main.c \
			$(PATH_CLIENT)my_str_to_word_tab.c \
			$(PATH_CLIENT)client_com.c \
			$(PATH_CLIENT)ping.c \
			$(PATH_CLIENT)my_fd.c \
			$(PATH_CLIENT)write_server.c \
			$(PATH_CLIENT)cmd_user.c \
			$(PATH_CLIENT)cmd_users.c \
			$(PATH_CLIENT)cmd_nick.c \
			$(PATH_CLIENT)cmd_join.c \
			$(PATH_CLIENT)cmd_kick.c \
			$(PATH_CLIENT)cmd_kill.c \
			$(PATH_CLIENT)cmd_part.c \
			$(PATH_CLIENT)cmd_topic.c \
			$(PATH_CLIENT)cmd_list.c \
			$(PATH_CLIENT)cmd_quit.c \
			$(PATH_CLIENT)cmd_mp.c \
			$(PATH_CLIENT)my_cmd.c \
			$(PATH_SRC)server/cbuf.c
