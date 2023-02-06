FROM debian:buster

RUN  apt-get update -y && apt-get upgrade -y \
	&& apt-get install -y mariadb-server  mariadb-client

ENV MYSQL_ALLOW_EMPTY_PASSWORD=no
ENV DOMAIN_NAME=hyunjung.42.fr
ENV MYSQL_DB=wordpress_db
ENV MYSQL_USER=asroq1
ENV MYSQL_PW=1234
ENV MYSQL_ROOT=root
ENV MYSQL_ROOT_PW=1234
ENV WP_USER=hyunjung
ENV WP_EMAIL=asroq98@gmail.com
ENV WP_PASS=1234
ENV WP_TITLE=inception
ENV WP_ADMIN=root
ENV WP_ADMIN_PW=1234
ENV WP_ADMIN_EMAIL=hyunjung@student.42seoul.kr

# 50-server.cnf에서 bind-adress주소를 주석처리 해주는 파일로 덮어씌운다.
# 안 해주는 경우에는 외부 ip에서 접근할 수 없기 때문에
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
# sql문을 이동해준다.
COPY ./tools/setting.sh ./

RUN set -ex ; \
	service mysql start ; \
	echo "CREATE DATABASE IF NOT EXISTS ${MYSQL_DB};" > /root/init_db.sql ; \ 
	echo "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PW}';" >> /root/init_db.sql ; \
	echo "GRANT ALL PRIVILEGES ON ${MYSQL_DB}.* TO '${MYSQL_USER}'@'%';" >> /root/init_db.sql ; \
	echo "FLUSH PRIVILEGES;" >> /root/init_db.sql ; \
	echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PW}';" >> /root/init_db.sql ; \
	mysql -hlocalhost -u root -p${MYSQL_ROOT_PW} -e "source /root/init_db.sql;" && \
	rm /root/init_db.sql

# 1.새로운 DB 생성 (기존에 존재하지 않을 경우) >> 문자열을 init.sql에 쓰기
# 2. 유저 생성 '%'는 내부가 아닌 어디에서나 접근이 가능함을 의미한다
# 3. 생성된 유저에 DB (내의 모든 테이블) 의 모든 권한 부여 (원격 접속 권한 포함)
# 4. 그리고 권한 변경사항을 전부 즉시 적용
# 5. 초기에 생성되는 루트 비밀번호를 새롭게 초기화 해준다.
# 6. 그리고 권한 변경사항을 전부 즉시 적용
# 7. -h는 연결할 호스트 이름. mysql 명령어로 루트로 로그인 후 해당 sql문을 실행시킨다.

EXPOSE 3306 
CMD [ "mysqld" ]
# mysql : 백그라운드에서 돌아가는 프로세스. mysql서버를 의미
# mysqld : mysql + d (d는 daemon의 약어) 터미널처럼 sql을 실행시켜주는 command-line clinet이다.

# CMD와 entrypoint의 차이점
# CMD: 명령 및 인자값이 변경될 수 있음. 컨테이너에서 명령을 따로 설정하지 않을 시 CMD에 기재한 명령을 기본값으로 실행
# entrypoint : CMD와 다르게 명령 수정이 불가능하다.
# 고정적으로 실행될 명령은 entrypoint를 사용하는 것이 좋다.