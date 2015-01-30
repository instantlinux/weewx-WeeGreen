# weewx-WeeGreen
UI skin for weewx, the weather-reporting engine

## Installation

* Install [weewx](http://sourceforge.net/projects/weewx); this skin is tested with version 3.0.1
* Install [forecast skin](http://lancet.mit.edu/mwall/projects/weather) (this skin depends on its image files and weewx.conf updates; tested with forecast version 3.0.2)
* Customize weewx.conf 
  * Define your [Station]
  * Register at Wunderground.com, add your api_key to [Forecast][[WU]] and your
    credentials to [StdRESTful][[Wunderground]] - note that rapidfire should be True
  * Specify this skin in [StdReport][[StandardReport]], and comment out forecast
    skin if it got added in previous step
* Customize skin.conf in this directory
* Set up an Apache or nginx config, example is below

## Author

Rich Braun, San Francisco

See example site at http://wx.ci.net

## Server configuration

Here's an example vhost for Apache; set the DirectoryIndex to current.html or about.html if you prefer a different landing page:

    <VirtualHost *:80>
    # Server Configuration:
    ServerName wx.ci.net
    DocumentRoot "/var/www/htdocs/wx/"
    DirectoryIndex forecast.html
    ServerAdmin richb@instantlinux.net
    ServerSignature email
    TraceEnable Off
    HostNameLookups Off
    <Directory /var/www/htdocs/wx>
    	 Options -Indexes FollowSymLinks
      	 AllowOverride All
	 Order allow,deny
	 Allow from all
    </Directory>
    </VirtualHost>

## License

Copyright 2015 Richard Braun

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
