#!/bin/sh

mkdir /etc/nginx/certificate
cd /etc/nginx/certificate

openssl req -new -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out nginx-certificate.crt -keyout nginx.key -subj "/C=RU/ST=Moscow/L=Moscow/O=wordpress/CN=hyunjung.42.fr";
 
# req : 인증서를 생성하는 요청
# newkey : rsq:4096에 해당하는 키도 생성 (4096비트 크기의)
# -x509 : self-signed 인증서 생성, x509는 표준 형식이다.
# days : 인증서 만료 기간
# -nodes private key가 생성되면 암호화 x
# -subj : 
# 해당 .sh에서 모든 작업을 수행한 다음 동일한 쉘에서 사용자가 커맨드에 전달한 명령을 실행할 수 있게 해준다.
exec "$@"