FROM debian:buster

RUN  apt-get update && apt-get install -y mariadb-server

EXPOSE 3306 


# 50-server.cnf에서 bind-adress주소를 주석처리 해주는 파일로 덮어씌운다.
# 안 해주는 경우에는 외부 ip에서 접근할 수 없기 때문에
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
# sql문을 이동해준다.
COPY ./tools /var/www

# mysql 명령문을 통해서 미리 만들어둔 sql문을 적용시켜 db를 만들어준다.
RUN service mysql start && mysql < /var/www/initial_db.sql && rm -f /var/www/initial_db.sql;

# mysql : 백그라운드에서 돌아가는 프로세스. mysql서버를 의미
# mysqld : mysql + d (d는 daemon의 약어) 터미널처럼 sql을 실행시켜주는 command-line clinet이다.
CMD ["mysqld"] 

# CMD와 entrypoint의 차이점
# CMD: 명령 및 인자값이 변경될 수 있음. 컨테이너에서 명령을 따로 설정하지 않을 시 CMD에 기재한 명령을 기본값으로 실행
# entrypoint : CMD와 다르게 명령 수정이 불가능하다.
# 고정적으로 실행될 명령은 entrypoint를 사용하는 것이 좋다.