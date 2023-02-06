
# --build : doesn't matter about cached data. it must rebuild the source

all : 
	mkdir -p /Users/devicii/data/wordpress
	mkdir -p /Users/devicii/data/mariadb

	docker-compose -f ./srcs/docker-compose.yml up --build -d
	
re : 
	docker-compose build ./srcs/docker-compose.yml --no-cache

clean : 
		docker-compose -f ./srcs/docker-compose.yml down
		docker system prune -a
		rm -rf /Users/devicii/data

.PHONY : all re clean