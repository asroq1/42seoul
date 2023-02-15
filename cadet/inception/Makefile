
all : 
	mkdir -p /Users/devicii/data/wordpress
	mkdir -p /Users/devicii/data//mariadb

	docker-compose -f ./srcs/docker-compose.yml up --build -d

clean : 
		docker-compose -f ./srcs/docker-compose.yml down
		docker system prune -a
		rm -rf /Users/devicii/data

.PHONY : all clean