FROM alpine:3.16

RUN apk update && \
    apk upgrade && \
    apk add --no-cache dumb-init && \
    wget https://github.com/google/cadvisor/releases/download/v0.46.0/cadvisor-v0.46.0-linux-amd64 -O cadvisor && \
    chmod +x cadvisor && \
    mv cadvisor /usr/local/bin/

EXPOSE 8080

ENTRYPOINT ["dumb-init", "--", "cadvisor"]
