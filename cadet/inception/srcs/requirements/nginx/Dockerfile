FROM debian:buster

# Open SSL은 443포트를 통해서 https로 통신하기 위해 필요한 self-signed SSL 인증서를 생성하기 위해 설치
RUN apt-get update -y && apt-get upgrade -y && \
	apt-get -y install nginx openssl vim

# RUN	mkdir /etc/nginx/ssl

# RUN openssl req -newkey rsa:2048 -nodes -x509 \
# 	-subj "/C=KR/ST=Seoul/L=Gangnam/O=Gaepodong/OU=42Seoul/CN=hyunjung.42.fr" \
# 	-keyout /etc/nginx/ssl/hyunjung.42.fr.key \
# 	-out /etc/nginx/ssl/hyunjung.42.fr.crt

COPY ./conf/default /etc/nginx/sites-enabled/default
COPY ./tools/setting.sh /var/www

RUN chmod +x /var/www/setting.sh

EXPOSE 443

ENTRYPOINT [ "/var/www/setting.sh" ]

# CMD tail -f /dev/null

CMD [ "nginx", "-g", "daemon off;" ]