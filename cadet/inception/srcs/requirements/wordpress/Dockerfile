FROM debian:buster

RUN  apt-get update && apt-get -y install mariadb-client
# PHP모듈 설치
RUN apt-get -y install \
	php7.3 \
	php-fpm \
	php-cli \
	wget \
	curl \
	php-mysql \
	php-mbstring \
	php-xml \
	sendmail \
	vim

# wordpress 설치
RUN wget https://wordpress.org/latest.tar.gz && \
	tar -xvf latest.tar.gz && \
	mv /wordpress/* /var/www/html/ && \
	chown -R www-data:www-data /var/www/html && \ 
	rm -r /wordpress latest.tar.gz
# 50-server.cnf에서 bind-adress주소를 주석처리 해주는 파일로 덮어씌운다.
# 안 해주는 경우에는 외부 ip에서 접근할 수 없기 때문에
EXPOSE 9000

# wp-config-sample을 wp-config으로 변경
COPY /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

RUN service php7.3-fpm start

# mysql과 mysqld의 차이는 무엇인가 ?
# CMD ["mysqld"] 
