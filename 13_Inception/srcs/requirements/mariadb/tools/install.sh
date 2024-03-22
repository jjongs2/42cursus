#!/bin/sh

if [ -d /var/lib/mysql/mysql ]; then
	echo "DB already exists."
	mysqld_safe
else {
	mysql_install_db
	if [ $? == 0 ]; then
		echo "Success: DB installed."
	else
		echo "Failure: DB not installed."
		exit 1
	fi

	mysqld_safe &
	if [ $? == 0 ]; then
		echo "Success: mysqld_safe started."
	else
		echo "Failure: mysqld_safe not started."
		exit 1
	fi

	sleep 3
	envsubst < /var/tmp/query.sql | mysql -h localhost -u root
	if [ $? == 0 ]; then
		echo "Success: User created."
	else
		echo "Failure: User not created."
		exit 1
	fi
}
fi
