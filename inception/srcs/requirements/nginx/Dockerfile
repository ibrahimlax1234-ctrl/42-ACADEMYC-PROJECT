# NGINX

FROM debian:bookworm


RUN apt-get update && apt-get upgrade -y


RUN apt-get install -y nginx openssl


RUN mkdir -p /etc/nginx/certs

RUN openssl req -x509 -nodes -out /etc/nginx/certs/inception.crt -keyout \
    /etc/nginx/certs/inception.key -subj "/C=MO/ST=KH/L=KH/O=42/OU=42/CN=librahim.42.fr/UID=librahim"


COPY ./conf/nginx.conf /etc/nginx/nginx.conf


RUN mkdir -p /var/www/wordpress_files


RUN chown -R www-data:www-data /var/www/wordpress_files && chmod -R 755 /var/www/wordpress_files


CMD ["nginx", "-g", "daemon off;"]
