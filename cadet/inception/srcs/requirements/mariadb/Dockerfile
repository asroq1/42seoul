FROM debian:buster

RUN  apt-get update -y && \
	apt-get upgrade -y && \
	apt-get -y install mariadb-server

# 50-server.cnf에서 bind-adress주소를 주석처리 해주는 파일로 덮어씌운다.
# 안 해주는 경우에는 외부 ip에서 접근할 수 없기 때문에
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools /var/www

EXPOSE 3306

ENTRYPOINT [ "service" "mysql" ] 