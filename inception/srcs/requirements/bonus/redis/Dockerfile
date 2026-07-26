# BONUS REDIS

FROM alpine:3.18

RUN apk update

RUN apk add redis

RUN sed -i "s|protected-mode yes|protected-mode no|g" /etc/redis.conf

CMD ["redis-server", "--protected-mode", "no"]