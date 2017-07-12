##
## Makefile for  in /home/cauvin_m/Rendu/PSU_2016_zappy/Server/
##
## Made by Maxime Cauvin
## Login   <maxime.cauvin@epitech.eu>
##
## Started on  Sun Jun 18 05:15:13 2017 Maxime Cauvin
## Last update Sun Jun 18 05:29:15 2017 Maxime Cauvin
##

NAME = 	../zappy_server

CC   =		gcc

RM   = 	rm -f

CFLAGS += 	-W -Wall -Werror -Wextra -I./Includes

LDFLAGS += -lm

SRCS = 	Srcs/main.c \
		Srcs/error.c \
		Srcs/log.c \
		Srcs/utils.c \
		Srcs/Arguments/arguments.c \
		Srcs/Arguments/arguments_dispatch.c \
		Srcs/Clients/clients.c \
		Srcs/Game/game_action_queue.c \
		Srcs/Game/game_action_cmd.c \
		Srcs/Game/game_action_fork.c \
		Srcs/Game/game_action_eat.c \
		Srcs/Game/game_end.c \
		Srcs/GameGraphic/game_graphic.c \
		Srcs/GameGraphic/game_graphic_cmd.c \
		Srcs/GameGraphic/game_graphic_cmd_player.c \
		Srcs/GameGraphic/game_graphic_cmd_time.c \
		Srcs/GameGraphic/game_graphic_incantation.c \
		Srcs/GameGraphic/game_graphic_init.c \
		Srcs/GameGraphic/game_graphic_map.c \
		Srcs/GameGraphic/game_graphic_notify.c \
		Srcs/GameGraphic/game_graphic_player.c \
		Srcs/GameMap/game_map.c \
		Srcs/GameMap/game_map_generation.c \
		Srcs/GameMap/game_map_ressources.c \
		Srcs/GamePlayer/game_player.c \
		Srcs/GamePlayer/game_player_cmd.c \
		Srcs/GamePlayer/game_player_cmd_broadcast.c \
		Srcs/GamePlayer/game_player_cmd_eject.c \
		Srcs/GamePlayer/game_player_cmd_move.c \
		Srcs/GamePlayer/game_player_cmd_look.c \
		Srcs/GamePlayer/game_player_cmd_look_line.c \
		Srcs/GamePlayer/game_player_cmd_inventory.c \
		Srcs/GamePlayer/game_player_cmd_obj.c \
		Srcs/GamePlayer/game_player_cmd_incantation.c \
		Srcs/GamePlayer/game_player_cmd_player.c \
		Srcs/GamePlayer/game_player_dead.c \
		Srcs/GamePlayer/game_player_queue.c \
		Srcs/GamePlayer/game_player_init.c \
		Srcs/GamePlayer/game_player_sound.c \
		Srcs/GamePlayer/game_player_sound_b.c \
		Srcs/GamePlayer/game_player_teams.c \
		Srcs/Network/network_cir_buf.c \
		Srcs/Network/network_cir_buf_cmd.c \
		Srcs/Network/network_cir_buf_cmd_b.c \
		Srcs/Network/network_start.c \
		Srcs/Network/network_tunnel.c \
		Srcs/Network/network_server.c \
		Srcs/Network/network_client.c \
		Srcs/Network/network_time.c \
		Srcs/Network/network_loop.c

OBJS = 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@printf "\033[0;32mzappy_server compiled successfully !\n\033[0m"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
