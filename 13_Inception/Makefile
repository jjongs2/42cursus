.DEFAULT_GOAL = all

all:
	mkdir -p /home/$(USER)/data/mariadb
	mkdir -p /home/$(USER)/data/wordpress
	mkdir -p /home/$(USER)/data/portainer
	mkdir -p /home/$(USER)/data/website
	make up

build:
	docker-compose -f srcs/docker-compose.yml up -d --build

down:
	docker-compose -f srcs/docker-compose.yml down --volumes --rmi all

fclean: down
	sudo rm -rf /home/$(USER)/data/mariadb
	sudo rm -rf /home/$(USER)/data/wordpress
	sudo rm -rf /home/$(USER)/data/portainer
	sudo rm -rf /home/$(USER)/data/website
	docker system prune -f

re:
	make fclean
	make all

remove:
	docker-compose -f srcs/docker-compose.yml rm

restart:
	docker-compose -f srcs/docker-compose.yml restart

stop:
	docker-compose -f srcs/docker-compose.yml stop

up:
	docker-compose -f srcs/docker-compose.yml up -d

.PHONY: all build down fclean re remove restart stop up
