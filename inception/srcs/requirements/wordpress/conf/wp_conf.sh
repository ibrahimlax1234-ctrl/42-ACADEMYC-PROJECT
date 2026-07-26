#!/bin/bash

sleep 6

cd /var/www/wordpress_files


if [ ! -f wp-config.php ]; then
    echo "WordPress w redis plugin mam instalyinch , gha ytinstallaw daba"


    curl  -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar

    php wp-cli.phar core download --allow-root
    php wp-cli.phar core config --dbhost=mariadb --dbname="$DB_NAME" --dbuser="$DB_USER" --dbpass="$DB_PW" --allow-root
    php wp-cli.phar core install --url="$DOMAIN_NAME" --title="$WEBISTE_TITLE" --admin_user="$ADMIN_USER_WP" --admin_password="$ADMIN_PW_WP" --admin_email="$ADMIN_EMAIL_WP" --allow-root
    php wp-cli.phar user create "$USERNAME_WP" "$USER_EMAIL_WP" --user_pass="$USER_PW_WP" --role="$WP_USER_ROLE" --allow-root

    php wp-cli.phar plugin install redis-cache --activate --allow-root
    php wp-cli.phar config set WP_REDIS_HOST redis --allow-root
    php wp-cli.phar config set WP_REDIS_PORT 6379 --allow-root
    php wp-cli.phar redis enable --allow-root
else
    echo "kolchi nadi"
fi

chmod -R 755 /var/www/wordpress_files
chown -R www-data:www-data /var/www/wordpress_files
sed -i 's@^listen = .*@listen = 0.0.0.0:9000@' /etc/php/8.2/fpm/pool.d/www.conf
mkdir -p /run/php
/usr/sbin/php-fpm8.2 -F