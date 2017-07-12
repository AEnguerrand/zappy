##
## Makefile for  in /home/allame_e/Rendu/PSU_2016_zappy/
##
## Made by Enguerrand Allamel
## Login   <enguerrand.allamel@epitech.eu>
##
## Started on  Sun Jun 18 05:13:09 2017 Enguerrand Allamel
## Last update Thu Jun 22 23:00:18 2017 Enguerrand Allamel
##

$@

CP      		=  		cp -rf

RM      		=  		rm -rf

all: zappy_server

zappy_server:
	make -C Server

clean fclean:
	make -C Server $@

re all:
	make -C Server $@

.PHONY: $(RULES)
