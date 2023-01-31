FROM debian:buster

# Open SSL은 443포트를 통해서 https로 통신하기 위해 필요한 self-signed SSL 인증서를 생성하기 위해 설치
RUN apt-get update -y && apt-get upgrade -y && \
	apt-get -y install nginx openssl vim

# nginx설정 파일 수정 및 openssl설정 cli파일 넘기기
COPY ./conf/default /etc/nginx/sites-enabled/default
COPY ./tools/setting.sh /var/www

# opensll cli 적용
RUN chmod +x /var/www/setting.sh

# 외부로 443포트 개방
EXPOSE 443

# openssl 실행
ENTRYPOINT [ "/var/www/setting.sh" ]

# -g 글로벌, daemon을 꺼준다.
CMD [ "nginx", "-g", "daemon off;" ]