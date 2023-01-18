FROM debian:buster

RUN  apt-get update && \
	apt-get -y install \ 
	wget \
	tar \ 
	sudo \
	php7.3-fpm \ 
	php7.3-mysql\
	mariadb-client
# PHP모듈 설치
# RUN apt-get -y install \
# 	php7.3 \
# 	php-fpm \
# 	php-cli \
# 	php-mysqli \
# 	wget \
# 	curl \
# 	sendmail \

# COPY /tools/fpm.conf /etc/php/7.3/fpm/pool.d/www.conf
# COPY /tools/wp-config.php /var/www/html/wp-config.php
# COPY /tools/setting.sh /var/www

# conf 복사
COPY /tools/setting.sh /
COPY /conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

# wordpress CLI 설치 이후에 권한변경 이후 이동
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp

# working dir 위치 설정
WORKDIR /var/www/html/wordpress

# 해당 wordpress /run/php 생성 이후 setting.sh 등록
RUN mkdir -p /run/php && \
	chmod +x /setting.sh

# wordpress 설치
RUN wget https://wordpress.org/latest.tar.gz && \
	tar -xvf latest.tar.gz 
# RUN curl -o /usr/local/bin/wp -fL “https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar”; \
# 	chmod u+x /usr/local/bin/wp;
# 50-server.cnf에서 bind-adress주소를 주석처리 해주는 파일로 덮어씌운다.
# 안 해주는 경우에는 외부 ip에서 접근할 수 없기 때문에
EXPOSE 9000

# wp-config-sample을 wp-config으로 변경

# wp-config-sample을 wp-config으로 변경

# RUN chmod +x /var/www/setting.sh

ENTRYPOINT [ "sh", "-c", "/setting.sh" ]

# CMD ["usr/sbin/php-fpm7.3", "--nodaemonize"] 
