FROM alpine:3.16

RUN apk update && \
    apk upgrade && \
    apk add --no-cache dumb-init && \
    wget https://github.com/portainer/portainer/releases/download/2.16.2/portainer-2.16.2-linux-amd64.tar.gz && \
		tar -zxvf portainer-2.16.2-linux-amd64.tar.gz

EXPOSE 9443

ENTRYPOINT ["dumb-init", "--", "portainer/portainer"]
