# BONUS WEBSITE


FROM alpine:3.18

RUN apk update

RUN apk add nginx

COPY ngnx.conf /etc/nginx/http.d/default.conf

COPY index.html /var/www/html/index.html

CMD ["nginx", "-g", "daemon off;"]