FROM alpine:3.16

RUN apk update && \
    apk upgrade && \
    apk add --no-cache dumb-init ruby-full ruby-dev gcc g++ make && \
    gem install jekyll bundler && \
    jekyll new /var/www/blog

WORKDIR /var/www/blog

COPY tools/server.sh /usr/local/bin/

EXPOSE 4000

ENTRYPOINT ["dumb-init", "--", "server.sh"]
