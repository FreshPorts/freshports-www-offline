This website is useful when taking another website off line.
You can redirect all queries here.  All responses are 
503 Service Unavailable.  That should let people and spiders
know to try again later.

This file was originally written for Apache, then changed to be
agnostic. However, FreshPorts uses Nginx.

To use this, here is the outline of the steps you need to perform:

* remove the virtual host of your real website from the webserver
* add this virtual host, ensuring that you specify the right
  ServerName or ServerAlias for the host you are taking offline.
* signal your webserver to reload

Enjoy.

To prepare:

```
sudo mkdir /usr/local/etc/nginx/includes.offline
sudo cp offline.conf offline.inc /usr/local/etc/nginx/includes.offline
cd /usr/local/etc/nginx/includes.offline
sudo ln -s  /usr/local/www/default_vhost_nginx/configuration/vhosts.conf default_vhost_nginx.conf
sudo ln -s /usr/local/etc/freshports/vhosts.conf.nginx.freshports.net    freshports.NET.conf
cd ..
sudo mkdir -p /usr/local/etc/nginx/html/maintenance
sudo cp -p maintenance.html /usr/local/etc/nginx/html/maintenance
```

Customize offline.conf
* adjust hostnames 
* adjust IP addresses
* adjust ssl_certificate & ssl_certificate_key

Customtize maintenance/maintenance.html

To take websites offline:

```
cd /usr/local/etc/nginx
sudo mv includes includes.actual
sudo ln -s includes.offline includes
sudo service nginx configtest
sudo service nginx reload (might be enough, if not, reload)
```

To take webites online:

```
cd /usr/local/etc/nginx
sudo rm includes
sudo  mv includes.actual includes
sudo service nginx configtest
sudo service nginx reload (might be enough, if not, reload)
```
