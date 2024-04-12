  location / {
    return 503;
  }


  # Define maintenance directory so that it doesn't return 503 HTTP code
    location /maintenance {
  }
 
  # Define 503 error/maintenance page
  error_page 503 @maintenance;
  location @maintenance {
    rewrite ^(.*)$ /maintenance/maintenance.html break;
  }

