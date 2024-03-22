#!/bin/sh

sleep 13
if [ -f /var/www/wordpress/wp-config.php ] ; then
  echo "'wp-config.php' file already exists."
else {
  mkdir -p /run/php

  wp config create  --dbname=$DB_NAME \
                    --dbuser=$DB_USER \
                    --dbpass=$DB_PASSWORD \
                    --dbhost=$DB_HOST \
                    --path='/var/www/wordpress' \
                    --allow-root

  wp core install --url=$WP_URL \
                  --title=$WP_TITLE \
                  --admin_user=$DB_USER \
                  --admin_password=$DB_PASSWORD \
                  --admin_email=$ADMIN_EMAIL \
                  --path='/var/www/wordpress' \
                  --skip-email \
                  --allow-root

  wp user create  $USER_LOGIN \
                  $USER_EMAIL \
                  --role=author \
                  --user_pass=$USER_PASS \
                  --path='/var/www/wordpress' \
                  --allow-root

  wp theme install twentyseventeen --activate --path='/var/www/wordpress'
  wp plugin update --all --path='/var/www/wordpress'

  sed -i '/WP_CACHE_KEY_SALT/d' /var/www/wordpress/wp-config.php
  {
    echo -e "\n// ** Redis settings ** //";
    echo "define( 'WP_REDIS_HOST', '$REDIS_HOST' );";
    echo "define( 'WP_CACHE_KEY_SALT', '$WP_URL' );";
    echo "define( 'WP_CACHE', true );";
  } | tee -a /var/www/wordpress/wp-config.php

  wp plugin install redis-cache --activate --path='/var/www/wordpress'
  wp redis enable --path='/var/www/wordpress'
}
fi

/usr/sbin/php-fpm8 -F
