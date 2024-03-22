#!/bin/sh

sleep 5
chmod 777 /var/www/wordpress

/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf
