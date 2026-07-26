# BONUS SERVICE OF CHOICE "CADVISOR"

FROM debian:trixie


RUN apt-get update && apt-get install -y wget && mkdir -p /home/cadv

RUN wget https://github.com/google/cadvisor/releases/download/v0.53.0/cadvisor-v0.53.0-linux-amd64 -O /home/cadv/cadvisor && chmod +x /home/cadv/cadvisor


CMD ["/home/cadv/cadvisor", "--port=8080"]