<div class="stats">
  <table>
    <tbody>
      <tr>
        <td class="stats"></td><td class="stats_header">
          $period1Name
        </td>
        <td class="stats_header">
          $period2Name
        </td>
      </tr>
      <tr>
	<td class="stats_label">
	  High<br/>
	  Low
	</td>
	<td class="stats_data">
	  <span class="temphi">$period1.outTemp.max at $period1.outTemp.maxtime<br/></span>
	  <span class="templo">$period1.outTemp.min at $period1.outTemp.mintime</span>
	</td>
	<td class="stats_data">
	  <span class="temphi">$period2.outTemp.max at $period2.outTemp.maxtime<br/></span>
	  <span class="templo">$period2.outTemp.min at $period2.outTemp.mintime</span>
	</td>
      </tr>
      <tr>
	<td class="stats_label">
	  High Heat Index<br/>
	  Low Wind Chill
	</td>
	<td class="stats_data">
	  <span class="temphi">$period1.heatindex.max at $period1.heatindex.maxtime<br/></span>
	  <span class="templo">$period1.windchill.min at $period1.windchill.mintime</span>
	</td>
	<td class="stats_data">
	  <span class="temphi">$period2.heatindex.max at $period2.heatindex.maxtime<br/></span>
	  <span class="templo">$period2.windchill.min at $period2.windchill.mintime</span>
	</td>
      </tr>
      <tr>
	<td class="stats_label">
	  Humidity Range
	</td>
	<td class="stats_data">
	  <span class="temphi">$period1.outHumidity.max at $period1.outHumidity.maxtime<br/></span>
	  <span class="templo">$period1.outHumidity.min at $period1.outHumidity.mintime</span>
	</td>
	<td class="stats_data">
	  <span class="temphi">$period2.outHumidity.max at $period2.outHumidity.maxtime<br/></span>
	  <span class="templo">$period2.outHumidity.min at $period2.outHumidity.mintime</span>
	</td>
      </tr>
      <tr>
	<td class="stats_label">
	  Dewpoint Range
	</td>
	<td class="stats_data">
	  <span class="temphi">$period1.dewpoint.max at $period1.dewpoint.maxtime<br/></span>
	  <span class="templo">$period1.dewpoint.min at $period1.dewpoint.mintime</span>
	</td>
	<td class="stats_data">
	  <span class="temphi">$period2.dewpoint.max at $period2.dewpoint.maxtime<br/></span>
	  <span class="templo">$period2.dewpoint.min at $period2.dewpoint.mintime</span>
	</td>
      </tr>
      <tr>
	<td class="stats_label">
	  Barometer Range
	</td>
	<td class="stats_data">
	  $period1.barometer.max at $period1.barometer.maxtime<br/>
	  $period1.barometer.min at $period1.barometer.mintime
	</td>
	<td class="stats_data">
	  $period2.barometer.max at $period2.barometer.maxtime<br/>
	  $period2.barometer.min at $period2.barometer.mintime
	</td>
      </tr>
      <tr>
	<td class="stats_label">Rainfall</td>
	<td class="stats_data">$period1.rain.sum</td>
	<td class="stats_data">$period2.rain.sum</td>
      </tr>
      <tr>
	<td class="stats_label">High Rain Rate</td>
	<td class="stats_data">$period1.rainRate.max at $period1.rainRate.maxtime</td>
	<td class="stats_data">$period2.rainRate.max at $period2.rainRate.maxtime</td>
      </tr>
      <tr>
	<td class="stats_label">
	  High Wind
	</td>
	<td class="stats_data">
	  $period1.wind.max from $period1.wind.gustdir at $period1.wind.maxtime
	</td>
	<td class="stats_data">
	  $period2.wind.max from $period2.wind.gustdir at $period2.wind.maxtime
	</td>
      </tr>
      <tr>
	<td class="stats_label">
	  Average Wind
	</td>
	<td class="stats_data">
	  $period1.wind.avg
	</td>
	<td class="stats_data">
	  $period2.wind.avg
	</td>
      </tr>
      <tr>
	<td class="stats_label">
	  RMS Wind
	</td>
	<td class="stats_data">
	  $period1.wind.rms
	</td>
	<td class="stats_data">
	  $period2.wind.rms
	</td>
      </tr>

      <tr>
	<td class="stats_label">
	  Vector Average Speed/Direction
	</td>
	<td class="stats_data">
	  $period1.wind.vecavg<br/>
	  $period1.wind.vecdir
	</td>
	<td class="stats_data">
	  $period2.wind.vecavg<br/>
	  $period2.wind.vecdir
	</td>
      </tr>

      #if $period2Name == "Today"
      <tr>
	<td class="stats_label">Sunrise<br/>Sunset</td><td></td>
	<td class="stats_data">
	  $almanac.sunrise<br/>
	  $almanac.sunset<br/>
	</td>
      </tr>
      <tr>
	<td class="stats_label">Moon</td><td></td>
	<td class="stats_data">$almanac.moon_phase ($almanac.moon_fullness% full)</td>
      </tr>
      #end if

      <tr>
	<td class="stats_label">Degree Days</td>
	<td class="stats_data">
	  <span class="temphi">$period1.heatdeg.sum.nolabel("%6.1f")</span> /
	  <span class="templo">$period1.cooldeg.sum.nolabel("%6.1f")</span>
	</td>
	<td class="stats_data">
	  #if $period2Name != "Today" or int($current.dateTime.format("%H")) > 15
	    <span class="temphi">$period2.heatdeg.sum.nolabel("%6.1f")</span> /
	    <span class="templo">$period2.cooldeg.sum.nolabel("%6.1f")</span>
	  #end if
	</td>
      </tr>

      <tr>
	<td class="stats_label">
	  Inside Temperature<br/>Range
	</td>
	<td class="stats_data">
	  <span class="temphi">$period1.inTemp.max at $period1.inTemp.maxtime<br/></span>
	  <span class="templo">$period1.inTemp.min at $period1.inTemp.mintime</span>
	</td>
	<td class="stats_data">
	  <span class="temphi">$period2.inTemp.max at $period2.inTemp.maxtime<br/></span>
	  <span class="templo">$period2.inTemp.min at $period2.inTemp.mintime</span>
	</td>
      </tr>
      #if $period2.extraTemp1.has_data
      <tr>
	<td class="stats_label">
	  High Pond Temperature<br/>
	  Low Pond Temperature
	</td>
	<td class="stats_data">
	  $period2.extraTemp1.max at $period2.extraTemp1.maxtime<br/>
	  $period2.extraTemp1.min at $period2.extraTemp1.mintime
	</td>
      </tr>
      #end if
      #if $Extras.has_key('optionalAccessories') and $period2.pm2_5.has_data
      <tr>
	<td class="stats_label">
	  AQI Range
	</td>
	<td class="stats_data">
	  $period1.pm2_5_aqi.max at $period1.pm2_5.maxtime<br/>
	  $period1.pm2_5_aqi.min at $period1.pm2_5.mintime
	</td>
	<td class="stats_data">
	  $period2.pm2_5_aqi.max at $period2.pm2_5.maxtime<br/>
	  $period2.pm2_5_aqi.min at $period2.pm2_5.mintime
	</td>
      </tr>
      #end if
      #if $Extras.has_key('optionalAccessories') and $period2.UV.has_data
      <tr>
	<td class="stats_label">
	  High UV
	</td>
	<td class="stats_data">
	  $period1.UV.max at $period1.UV.maxtime
	</td>
	<td class="stats_data">
	  $period2.UV.max at $period2.UV.maxtime
	</td>
      </tr>
      #end if
      #if $Extras.has_key('optionalAccessories') and $period2.ET.has_data and $period2.ET.sum.raw >0.0
      <tr>
	<td class="stats_label">
	  High ET
	</td>
	<td class="stats_data">
	  $period1.ET.max at $period1.ET.maxtime
	</td>
	<td class="stats_data">
	  $period2.ET.max at $period2.ET.maxtime
	</td>
      </tr>
      #end if
      #if $Extras.has_key('optionalAccessories') and $period2.radiation.has_data
      <tr>
	<td class="stats_label">
	  High Radiation
	</td>
	<td class="stats_data">
	  $period1.radiation.max at $period1.radiation.maxtime
	</td>
	<td class="stats_data">
	  $period2.radiation.max at $period2.radiation.maxtime
	</td>
      </tr>
      #end if
    </tbody>
  </table>
</div> <!--End class "stats" -->
