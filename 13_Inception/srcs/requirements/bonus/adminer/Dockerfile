FROM alpine:3.16

RUN apk update && \
    apk upgrade && \
    apk add --no-cache dumb-init php8 php8-common php8-session php8-iconv php8-gd php8-curl php8-xml php8-mysqli php8-imap php8-cgi php8-pdo php8-pdo_mysql php8-soap php8-posix php8-gettext php8-ldap php8-ctype php8-dom php8-simplexml && \
    mkdir -p /var/www && \
    wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O /var/www/index.php && \
    chown -R root:root /var/www

EXPOSE 8080

ENTRYPOINT ["dumb-init", "--", "php", "-S", "[::]:8080", "-t", "/var/www"]
