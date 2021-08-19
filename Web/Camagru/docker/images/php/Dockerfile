FROM php:7.2-apache

RUN a2enmod rewrite

# Installs sendmail
RUN apt-get update && apt-get install -q -y vim msmtp mailutils libpng-dev && rm -rf /var/lib/apt/lists/*

RUN docker-php-ext-install gd mysqli

RUN echo "account gmail" >> /etc/.msmtp
RUN echo "tls on" >> /etc/.msmtp
RUN echo "tls_certcheck off" >> /etc/.msmtp
RUN echo "auth on" >> /etc/.msmtp
RUN echo "host smtp.gmail.com" >> /etc/.msmtp
RUN echo "port 587" >> /etc/.msmtp
RUN echo "user camagru.is.hard@gmail.com" >> /etc/.msmtp
RUN echo "from camagru.is.hard@gmail.com" >> /etc/.msmtp
RUN echo "password fugcuj-xEsmod-8wajpa" >> /etc/.msmtp
RUN chmod 600 /etc/.msmtp
RUN chown www-data:www-data /etc/.msmtp

# Set up php sendmail config
RUN touch /var/log/msmtp.log
RUN chown www-data:www-data /var/log/msmtp.log
RUN echo "sendmail_path = \"/usr/bin/msmtp -C /etc/.msmtp --logfile /var/log/msmtp.log -a gmail -t\"" >> /usr/local/etc/php/conf.d/php-sendmail.ini