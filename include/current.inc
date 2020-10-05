        <div class="stats">
          <table>
            <tbody>
              <tr>
	        <td colspan="2" class="stats_label">Current Conditions</td>
              </tr>
              <tr>
                <td class="stats_label">Temperature</td>
                <td class="stats_data">$current.outTemp</td>
              </tr>
              <tr>
                <td class="stats_label">Wind Chill</td>
                <td class="stats_data">$current.windchill</td>
              </tr>
              <tr>
                <td class="stats_label">Heat Index</td>
                <td class="stats_data">$current.heatindex</td>
              </tr>
              <tr>
                <td class="stats_label">Dewpoint</td>
                <td class="stats_data">$current.dewpoint</td>
              </tr>
              <tr>
                <td class="stats_label">Humidity</td>
                <td class="stats_data">$current.outHumidity</td>
              </tr>
              <tr>
                <td class="stats_label">Barometer (now)<br/>($trend.time_delta.hour.format("%.0f") trend)</td>
                <td class="stats_data">$current.barometer<br/>$trend.barometer</td>
              </tr>
              <tr>
                <td class="stats_label">Wind</td>
                <td class="stats_data">$current.windSpeed from $current.windDir ($current.windDir.ordinal_compass)</td>
              </tr>
              <tr>
                <td class="stats_label">Rain Rate</td>
                <td class="stats_data">$current.rainRate</td>
              </tr>
              #if $day.extraTemp1.has_data
              <tr>
                <td class="stats_label">Pond Temperature</td>
                <td class="stats_data">$current.extraTemp1</td>
              </tr>
              #end if
              #if $Extras.has_key('optionalAccessories') and $day.pm2_5.has_data
              #set pmdata = '%.2f, %.2f, %.2f %s' % ($current.pm1_0.raw, $current.pm2_5.raw, $current.pm10_0.raw, $unit.label.pm2_5)
	      #if $current.pm2_5_aqi.raw > 300
	        #set pmcolor = '581845'
	      #else if $current.pm2_5_aqi.raw > 200
	        #set pmcolor = 'F80000'
	      #else if $current.pm2_5_aqi.raw > 150
	        #set pmcolor = '900C3F'
	      #else if $current.pm2_5_aqi.raw > 100
	        #set pmcolor = 'F39C12'
	      #else if $current.pm2_5_aqi.raw > 50
	        #set pmcolor = 'F8F800'
	      #end if
              <tr>
                <td class="stats_label">PM1, 2.5, 10 Concentration</td>
                <td class="stats_data">$pmdata</td>
              </tr>
              <tr>
                <td class="stats_label">AQI</td>
                #if $current.pm2_5_aqi.raw >= 50
                <td class="stats_data" bgcolor="#$pmcolor">
                #else
                <td>
                #end if
                $current.pm2_5_aqi</td>
              </tr>
              #end if
              #if $Extras.has_key('optionalAccessories') and $day.UV.has_data
              <tr>
                <td class="stats_label">UV</td>
                <td class="stats_data">$current.UV</td>
              </tr>
              #end if
              #if $Extras.has_key('optionalAccessories') and $day.ET.has_data and $day.ET.sum.raw > 0.0
              <tr>
                <td class="stats_label">ET</td>
                <td class="stats_data">$current.ET</td>
              </tr>
              #end if
              #if $Extras.has_key('optionalAccessories') and $day.radiation.has_data
              <tr>
                <td class="stats_label">Solar Radiation</td>
                <td class="stats_data">$current.radiation</td>
              </tr>
              #end if
              <tr>
                <td class="stats_label">Inside Temperature</td>
                <td class="stats_data">$current.inTemp</td>
              </tr>
            </tbody>
          </table>
        </div>
