CREATE DATABASE IF NOT EXISTS wordpress_db;
CREATE USER IF NOT EXISTS 'hyunjung'@'%' IDENTIFIED BY '1234';
-- # DB_USER에게 모든 권한을 줌
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'hyunjung'@'%';
-- # 위의 db 변경사항을 즉시 반영하도록 하게 한다
FLUSH PRIVILEGES;

-- ALTER USER 'root'@'localhost' IDENTIFIED BY 'root12345'; 