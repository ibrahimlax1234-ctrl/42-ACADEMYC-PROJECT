# BONUS ADMINER

FROM alpine:3.18

RUN apk update && apk add php php-mysqli php-session wget


RUN mkdir -p /home/adminer

RUN cd /home/adminer && wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O index.php


FROM alpine:3.18

RUN apk update && apk add php php-mysqli php-session wget


RUN mkdir -p /home/adminer

RUN cd /home/adminer && wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O index.php


CMD ["sh", "-c", "cd /home/adminer && php -S 0.0.0.0:8080"]