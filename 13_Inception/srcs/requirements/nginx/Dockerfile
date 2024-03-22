FROM alpine:3.16

RUN apk update && \
    apk upgrade && \
    apk add --no-cache dumb-init nginx openssl && \
    mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -out /etc/nginx/ssl/kijsong.42.fr.crt -keyout /etc/nginx/ssl/kijsong.42.fr.key -subj "/C=KR/ST=Seoul/L=Gangnam-gu/O=42/OU=42Seoul/CN=kijsong.42.fr"

COPY conf/nginx.conf /etc/nginx/

EXPOSE 443

ENTRYPOINT [ "dumb-init", "--", "nginx", "-g", "daemon off;" ]
