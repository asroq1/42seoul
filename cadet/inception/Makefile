
all : 
	mkdir -p /home/hyunjung/data/wordpress
	mkdir -p /home/hyunjung/data//mariadb

	docker-compose -f ./srcs/docker-compose.yml up --build -d
	
re : 
	docker-compose build ./srcs/docker-compose.yml --no-cache

clean : 
		docker-compose -f ./srcs/docker-compose.yml down
		docker system prune -a
		rm -rf /home/hyunjung/data

.PHONY : all re clean