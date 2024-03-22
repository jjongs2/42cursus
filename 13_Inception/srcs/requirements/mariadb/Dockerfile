FROM alpine:3.16

RUN apk update && \
    apk upgrade && \
    apk add --no-cache dumb-init gettext mariadb mysql-client && \
    rm -f /etc/my.cnf.d/mariadb-server.cnf && \
    chown -R mysql:mysql /var/lib/mysql

COPY conf/my.cnf /etc/my.cnf.d/
COPY conf/query.sql /var/tmp/
COPY tools/install.sh /usr/local/bin/

ENTRYPOINT ["dumb-init", "--", "install.sh"]
