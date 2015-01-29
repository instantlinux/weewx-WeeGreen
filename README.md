# weewx-WeeGreen
UI skin for weewx, the weather-reporting engine

## Installation

* Install weewx
* Install forecast skin (this skin depends on its image files and weewx.conf updates)
* Customize weewx.conf 
  * Define your [Station]
  * Register at Wunderground.com, add your api_key to [Forecast][[WU]] and your
    credentials to [StdRESTful][[Wunderground]] - note that rapidfire should be True
  * Specify this skin in [StdReport][[StandardReport]], and comment out forecast
    skin if it got added in previous step
* Customize skin.conf in this directory

## Author

Rich Braun, San Francisco

See example site at http://wx.ci.net

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
