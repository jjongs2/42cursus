FROM alpine:3.16

RUN apk update && \
    apk upgrade && \
    apk add --no-cache dumb-init redis && \
    sed -i "s/bind 127.0.0.1 -::1/# bind 127.0.0.1 -::1/g" /etc/redis.conf && \
    sed -i "s/protected-mode yes/protected-mode no/g" /etc/redis.conf && \
    sed -i "s/# maxmemory <bytes>/maxmemory 20mb/g" /etc/redis.conf && \
    echo -e "\nmaxmemory-policy allkeys-lru" >> /etc/redis.conf

ENTRYPOINT ["dumb-init", "--", "redis-server", "/etc/redis.conf"]
