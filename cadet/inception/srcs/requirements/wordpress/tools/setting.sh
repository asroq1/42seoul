
# #!/bin/bash

sleep 3


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

exec /usr/sbin/php-fpm7.3 -F 