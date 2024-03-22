FROM alpine:3.16

RUN apk update && \
    apk upgrade && \
    apk add --no-cache dumb-init mariadb-client redis php8 php8-fpm php8-opcache php8-gd php8-curl php8-mysqli php8-json php8-mbstring php8-phar && \
    mkdir -p /var/www && \
    cd /var/www && \
    wget https://wordpress.org/wordpress-6.0.tar.gz && \
    tar -zxvf wordpress-6.0.tar.gz && \
    rm -f wordpress-6.0.tar.gz && \
    chown -R root:root wordpress

COPY conf/www.conf /etc/php8/php-fpm.d
COPY tools/install.sh /usr/local/bin/

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

ENTRYPOINT ["dumb-init", "--", "install.sh"]
