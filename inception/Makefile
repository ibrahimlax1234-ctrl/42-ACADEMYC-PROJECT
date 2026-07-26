COMP		= docker compose -f ./srcs/docker-compose.yml

build:
	@mkdir -p /home/librahim/data/wordpress
	@mkdir -p /home/librahim/data/mariadb
	$(COMP) up --build -d

up:
	$(COMP) up -d


down:
	$(COMP) down

clean:            
	$(COMP) down --rmi all --volumes

logs:
	$(COMP) logs


fclean: clean
	docker system prune -af
	docker builder prune -f
	rm -rf /home/librahim/data/wordpress
	rm -rf /home/librahim/data/mariadb



re: fclean all

.PHONY: build up down clean fclean re logs
