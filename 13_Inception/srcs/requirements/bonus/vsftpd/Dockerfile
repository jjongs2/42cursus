FROM alpine:3.16

ARG FTP_USER \
    FTP_PASSWORD

RUN apk update && \
    apk upgrade && \
    apk add --no-cache dumb-init vsftpd && \
    adduser -h /var/www/wordpress -s false -D $FTP_USER && \
    echo "$FTP_USER:$FTP_PASSWORD" | /usr/sbin/chpasswd

COPY conf/vsftpd.conf /etc/vsftpd/
COPY tools/entrypoint.sh /usr/local/bin/

EXPOSE 21

ENTRYPOINT ["dumb-init", "--", "entrypoint.sh"]
