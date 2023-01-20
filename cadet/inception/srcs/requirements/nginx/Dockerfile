FROM debian:buster

# Open SSL은 443포트를 통해서 https로 통신하기 위해 필요한 self-signed SSL 인증서를 생성하기 위해 설치
RUN apt-get update -y && apt-get upgrade -y && \
	apt-get -y install nginx openssl vim

RUN	mkdir /etc/nginx/ssl

COPY /conf/default /etc/nginx/sites-available/default

EXPOSE 443

CMD [ "service nginx start" ]
# ENTRYPOINT [ "sh", '-c', "/setting.sh" ]