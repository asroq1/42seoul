
# #!/bin/bash

echo " __        __            _ ____
 \\ \\      / /__  _ __ __| |  _ \\ _ __ ___  ___ ___
  \ \ /\ / / _ \| '__/ _' | |_) | '__/ _ \/ __/ __|
   \ V  V / (_) | | | (_| |  __/| | |  __/\__ \__ \\
    \_/\_/ \___/|_|  \__,_|_|   |_|  \___||___/___/\
"
# nginx의 접근을 위해 주인을 바꾼다 첫번째 www-data 유저이고 두 번째는 그룹이다. chown <유저>:<그룹> <권한 부여할 폴더>
# -R 옵션은 하위폴더도 모두 권한을 부여하기 위해. www-data가 이름인 이유는 우분투 기준이기 때문이다.
chown -R www-data:www-data /var/www/

if [ ! -f "/var/www/html/index.php" ]; then # 워드프레스가 설치 및 초기화가 안 되어 있을 때만 새로 설치
	# 1. sh에서 www-data유저로 실행하기 위해 아래와 같이 쓴다.
    # 2. wp core download : 워드프레스 파일 다운
    # 3. wp config create : wp-config.php 생성
    # 4. wp core instlall : 워드프레스 설정 및 설치
    # 5. wp user create : 워드프레스 유저 설정
    set -ex
    sudo -u www-data sh -c " \
    wp core download --locale=en_US  && \
    wp config create --dbname=$MYSQL_DB --dbhost=$MYSQL_HOST --dbuser=$MYSQL_USER --dbpass=$MYSQL_PW && \
    wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PW --admin_email=$WP_EMAIL && \
    wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PASS
	"
    mv /var/www/html/wordpress/* /var/www/html  
fi


# 포어그라운드에서 돌리기 위해 -F 옵션을 붙인다.
exec /usr/sbin/php-fpm7.3 -F  