
# --build : doesn't matter about cached data. it must rebuild the source

all : 
	mkdir -p /Users/devicii/data/wordpress
	mkdir -p /Users/devicii/data/mariadb

	docker-compose -f ./srcs/docker-compose.yml up --build -d

clean : docker-compose ./srcs/docker-compose.yml down
		docker image prune -a

# re : docker-compose -f ./srcs/docker-compose.yml up --build

# vclean : 

.PHONY : all clean vclean 