# #!/bin/bash


# 	echo "고!"
# # if [ ! -f /var/www/html/wp-config.php ]; then
# 	mkdir -p /run/php/;
# 	touch /run/php/php7.3-fpm.pid;
# 	cat /var/www/html/wp-config.php
# 	mv /wordpress/* /var/www/html/
# 	# mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
# 	chown -R www-data:www-data /var/www/html 
# 	rm -r /wordpress latest.tar.gz
# 	echo "?!"
# 	echo "Wordpress: setting up..."
# 	mkdir -p /var/www/html
# 	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar;
# 	chmod +x wp-cli.phar;
# 	mv wp-cli.phar /usr/local/bin/wp;
	
# 	# cd /var/www
# 	# wp core download --allow-root;
# 	# echo "Wordpress: creating users..."
# 	# wp core install --allow-root --url=${WP_URL} --title=${WP_TITLE} --admin_user=${WP_ADMIN_LOGIN} --admin_password=${WP_ADMIN_PASSWORD} --admin_email=${WP_ADMIN_EMAIL}
# 	# wp user create --allow-root ${WP_USER_LOGIN} ${WP_USER_EMAIL} --user_pass=${WP_USER_PASSWORD};
# 	# echo "Wordpress: set up!"
# 	sudo -u www-data sh -c " \
#     wp core download --locale=en_US && \
#     wp config create --dbname=$MYSQL_DB --dbhost=$MYSQL_HOST --dbuser=$MYSQL_USER --dbpass=$MYSQL_PW && \
#     wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PW --admin_email=$WP_EMAIL && \
#     wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PASS
# # fi

# exec "$@"

sleep 3

# mariadb 로그인에 실패할 경우 sleep 1
# &> 은 오류 (stderr) 를 리디렉션한다
# until 은 while ! 와 같으며, 조건문 내의 조건을 만족하기 전까지 반복한다
#!/bin/sh

echo " __        __            _ ____
 \\ \\      / /__  _ __ __| |  _ \\ _ __ ___  ___ ___
  \ \ /\ / / _ \| '__/ _' | |_) | '__/ _ \/ __/ __|
   \ V  V / (_) | | | (_| |  __/| | |  __/\__ \__ \\
    \_/\_/ \___/|_|  \__,_|_|   |_|  \___||___/___/\
"

chown -R www-data:www-data /var/www/


if [ ! -f "/var/www/html/wordpress/index.php" ]; then # index.php가 존재하지 않을 때 => wp 설치 및 초기화가 안 되어 있을 때만 새로 설치
	sudo -u www-data sh -c " \
    wp core download --locale=en_US && \
    wp config create --dbname=$MYSQL_DB --dbhost=$MYSQL_HOST --dbuser=$MYSQL_USER --dbpass=$MYSQL_PW && \
    wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PW --admin_email=$WP_EMAIL && \
    wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PASS
	"
fi