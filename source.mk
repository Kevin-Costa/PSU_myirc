##
## source.mk for source in /home/plasko_a/projet/epitech/PSU_2014_myftp
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Wed Mar 11 02:51:08 2015 Antoine Plaskowski
## Last update Fri May 15 15:53:45 2015 Kevin Costa
##

PATH_SRC	=	source/
PATH_NODE	=	$(PATH_SRC)node/
PATH_PARSER	=	$(PATH_SRC)parser_lexer/

SRC		+=	$(PATH_SRC)create_connected_socket.c
SRC		+=	$(PATH_SRC)create_binded_socket.c
SRC		+=	$(PATH_SRC)accept_client.c
SRC		+=	$(PATH_SRC)fd_set.c
SRC		+=	$(PATH_SRC)fdgetline.c

SRC		+=	$(PATH_NODE)first_node.c
SRC		+=	$(PATH_NODE)last_node.c
SRC		+=	$(PATH_NODE)free_node.c
SRC		+=	$(PATH_NODE)put_node.c
SRC		+=	$(PATH_NODE)sup_node.c
SRC		+=	$(PATH_NODE)sup_node_at.c
SRC		+=	$(PATH_NODE)len_node.c

SRC		+=	$(PATH_PARSER)lexer.c
SRC		+=	$(PATH_PARSER)free_lexer.c
SRC		+=	$(PATH_PARSER)aff_lexer.c
SRC		+=	$(PATH_PARSER)aff_parser.c
SRC		+=	$(PATH_PARSER)parser.c
SRC		+=	$(PATH_PARSER)prefix.c
SRC		+=	$(PATH_PARSER)command.c
SRC		+=	$(PATH_PARSER)params.c
SRC		+=	$(PATH_PARSER)message.c
SRC		+=	$(PATH_PARSER)set_prefix.c
SRC		+=	$(PATH_PARSER)set_command.c
SRC		+=	$(PATH_PARSER)set_params.c
SRC		+=	$(PATH_PARSER)aff_message.c
