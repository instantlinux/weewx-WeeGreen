## forecast display for weewx - Copyright 2012-2013 Matthew Wall
## $Id: forecast_table.inc,v 1.7 2015/01/29 00:46:03 root Exp $
## version = 0.3
##
## Include this file to display forecast data.  This file uses icons from the
## forecast icon set.
##
## To override the default settings in this file, use the following syntax in
## skin.conf or weewx.conf:
##
## [Extras]
##     ...
##     [[forecast_table_settings]]
##         forecast_source = NWS
##         num_periods = 40
##         show_sun = 1
##         show_moon = 1
##         show_tides = 1

#if $varExists('forecast')

## Which forecast should be displayed?  Options include WU, NWS
#set $forecast_source = $getVar('Extras.forecast_table_settings.forecast_source', 'WU')

## How many forecast periods should be considered?
## Up to 40 for NWS, up to 240 for WU.  More periods take longer to generate.
#set $num_periods = int($getVar('Extras.forecast_table_settings.num_periods', 40))
#set $hour_periods = int($getVar('Extras.forecast_table_settings.hour_periods', 10))

## Which columns should be displayed?
#set $show_legend = int($getVar('Extras.forecast_table_settings.show_legend', 1))
#set $show_hourly = int($getVar('Extras.forecast_table_settings.show_hourly', 0))
#set $show_day = int($getVar('Extras.forecast_table_settings.show_day', 1))
#set $show_date = int($getVar('Extras.forecast_table_settings.show_date', 1))
#set $show_outlook = int($getVar('Extras.forecast_table_settings.show_outlook', 1))
#set $show_temp = int($getVar('Extras.forecast_table_settings.show_temp', 1))
#set $show_dewpoint = int($getVar('Extras.forecast_table_settings.show_dewpoint', 0))
#set $show_humidity = int($getVar('Extras.forecast_table_settings.show_humidity', 0))
#set $show_wind = int($getVar('Extras.forecast_table_settings.show_wind', 1))
#set $show_tides = int($getVar('Extras.forecast_table_settings.show_tides', 0))
#set $show_sun = int($getVar('Extras.forecast_table_settings.show_sun', 0))
#set $show_moon = int($getVar('Extras.forecast_table_settings.show_moon', 0))
#set $show_pop = int($getVar('Extras.forecast_table_settings.show_pop', 1))
#set $show_precip = int($getVar('Extras.forecast_table_settings.show_precip', 1))
#set $show_obvis = int($getVar('Extras.forecast_table_settings.show_obvis', 1))

#set $wloc = ''
#set $wts = ''
#set $icondir = 'forecast/icons'

<script type='text/javascript'>
function toggle(control, id) {
  elements = document.getElementsByClassName(id + '.hours');
  for(i in elements) {
    elem=elements[i];
    if(elem.style.display != 'none') {
      elem.style.display = 'none';
      control.src = '$icondir/triangle-right.png'
    } else {
      elem.style.display = 'table-row';
      control.src = '$icondir/triangle-down.png'
    }
  }
}
</script>

<div class='stats'>

## Get any tide predictions
#set $tides = $forecast.xtides(startofday=True)

#if $show_legend
  <div class='legend'>
    <table>
      <tr>
        <td colspan="8" class="stats_label">Forecast</td>
      </tr>
      <tr>
#if $show_hourly
        <td class='disclosure'></td>
#end if
#if $show_day or $show_date
        <td class='col-date'></td>
#end if
#if $show_outlook
        <td class='col-outlook'></td>
#end if
#if $show_temp
        <td class='col-temp'><img src='$icondir/thermometer-red.png' class='legend-img' alt='T' title='temperature' /><br/><span class='units'>$unit.label.outTemp</span></td>
#end if
#if $show_dewpoint
        <td class='col-dewpoint'><img src='$icondir/thermometer-dewpoint.png' class='legend-img' alt='D' title='dewpoint' /><br/><span class='units'>$unit.label.dewpoint</span></td>
#end if
#if $show_humidity
        <td class='col-humidity'><img src='$icondir/thermometer-blue.png' class='legend-img' alt='H' title='humidity' /><br/><span class='units'>$unit.label.outHumidity</span></td>
#end if
#if $show_wind
        <td class='col-wind'><img src='$icondir/flag.png' class='legend-img' alt='W' title='wind' /><br/><span class='units'>$unit.label.wind</span></td>
#end if
#if $show_tides and len($tides) > 0
        <td class='col-tides'><img src='$icondir/water.png' class='legend-img' alt='tide' title='tides' /><br/><span class='units'>$unit.label.altitude</span></td>
#end if
#if $show_sun
        <td class='col-sun'><img src='$icondir/sunriseset.png' class='legend-img' alt='S' title='sun' /><br/></td>
#end if
#if $show_moon
#if $almanac.hasExtras
        <td class='col-moon'><img src='$icondir/moonriseset.png' class='legend-img' alt='M' title='moon' /><br/></td>
#end if
        <td class='col-moonphase'><img src='$icondir/moonphase.png' class='legend-img' alt='MP' title='moon phase' /><br/></td>
#end if
#if $show_pop
        <td class='col-pop'><img src='$icondir/pop.png' class='legend-img' alt='PoP' title='probability of precipitation' /><br/></td>
#end if
#if $show_precip
        <td class='col-precip'></td>
#end if
#if $show_obvis
        <td class='col-obvis'></td>
#end if
      </tr>
  </div>
#end if ## show_legend


## Some forecasts return 16-points of the compass, but the icons support
## only 8-points.  This dictionary maps the 16 points to 8 points.
#set $wind_dir_dict = {'SSW':'SW','WSW':'SW','NNW':'NW','WNW':'NW','SSE':'SE','ESE':'SE','NNE':'NE','ENE':'NE'}
#set $tide_dict = {'H':'High','L':'Low'}

#set $lastday = None
#set $periods = $forecast.weather_periods($forecast_source, max_events=$num_periods)
#set $current_hour = int($current.dateTime.format("%H"))
#set $num_hours = $hour_periods
#set $skip_first = 0
#if $current_hour + $hour_periods > 23 and $current_hour % 2 == 0
  #set $skip_first = 1
#end if

#for $period in $periods
  #set $thisday = $period.event_ts.format('%d')
  #set $thisdate = $period.event_ts.format('%Y.%m.%d')
  #set $smryid = $forecast_source + '.' + $thisdate
  #set $hourid = $forecast_source + '.' + $thisdate + '.hours'
  #set $alm = $forecast.almanac(ts=$period.event_ts.raw+10)
  #set $nextday_ts = time.mktime(time.strptime($thisdate + ' 00:00', '%Y.%m.%d %H:%M')) + 24*3600
  #if $alm.hasExtras
    #set $sunrise_ts = $alm.sunrise.raw
    #set $sunset_ts = $alm.sunset.raw
    #set $moonrise_ts = $alm.moon.rise.raw
    #set $moonset_ts = $alm.moon.set.raw
  #else
    ## non-pyephem sunrise/sunset is not a ValueHelper so do conversions
    #set $sunrise_ts = time.mktime(time.strptime($thisdate + ' ' + $alm.sunrise, '%Y.%m.%d %H:%M'))
    #set $sunset_ts = time.mktime(time.strptime($thisdate + ' ' + $alm.sunset, '%Y.%m.%d %H:%M'))
  #end if
  #set $wts = $period.issued_ts

  #if $lastday != $thisday
#if $show_hourly
    #if $lastday is not None
  </div>
    #end if
#end if
    #set $lastday = $thisday
    #set $summary = $forecast.weather_summary($forecast_source, $period.event_ts.raw, periods=$periods)
    #set $wloc = $summary.location
    #set $event_hour = int($period.event_ts.format('%H'))

  <div id='$smryid' class='summary'>
      <tr>
#if $show_hourly
        <td class='disclosure'>
          #if $num_hours > 0
          <img src='$icondir/triangle-right.png' onclick="toggle(this, '$smryid')" />
          #end if
        </td>
#end if
#if $show_day or $show_date
        <td class='col-date'>
#if $show_day
          <span class='day'>$summary.event_ts.format('%a')</span><br/>
#end if
#if $show_date
          <span class='date'>$summary.event_ts.format('%d %b %Y')</span>
#end if
        </td>
#end if
#if $show_outlook
        <td class='col-outlook'>
    #if $summary.clouds is not None
      #set $simg = $icondir + '/' + $summary.clouds + '.png'
          <img class='outlook-img' src='$simg' alt='$summary.clouds' title='$forecast.label('Weather', $summary.clouds)' />
    #end if
        </td>
#end if
#if $show_temp
        <td class='col-temp'><span class='temphi'>$summary.tempMax.nolabel('%.0f')</span><br/><span class='templo'>$summary.tempMin.nolabel('%.0f')</span></td>
#end if
#if $show_dewpoint
        <td class='col-dewpoint'>$summary.dewpointMax.nolabel('%.0f')<br/>$summary.dewpointMin.nolabel('%.0f')</td>
#end if
#if $show_humidity
        <td class='col-humidity'>$summary.humidityMax.nolabel('%.0f',' ')<br/>$summary.humidityMin.nolabel('%.0f',' ')</td>
#end if
#if $show_wind
        <td class='col-wind'
    #if $summary.windDirs is not None
            style='vertical-align:middle; background: url()
      #for $d in $summary.windDirs
        #set $winddir_img = $icondir + '/' + $wind_dir_dict.get($d,$d) + '.png'
            ,url($winddir_img)
      #end for
            ; background-repeat:no-repeat; background-position:center; background-size:32px;'
    #end if
            >
    #if $summary.windSpeedMin == $summary.windSpeedMax or $summary.windSpeedMin.raw == $summary.windSpeedMax.raw
          $summary.windSpeedMin.nolabel('%.0f',' ')
    #else
          $summary.windSpeedMin.nolabel('%.0f',' ')-$summary.windSpeedMax.nolabel('%.0f',' ')
    #end if
          <span class='windgust'>$summary.windGust.nolabel('%.0f',' ')</span>$summary.windChar
        </td>
#end if
#if $show_tides and len($tides) > 0
        <td class='col-tides' style='font-size:100%'>
  #for $tide in $tides
    #if $summary.event_ts.raw <= $tide.event_ts.raw < $summary.event_ts.raw + $summary.duration
      $tide.event_ts.format('%H:%M') $tide_dict.get($tide.hilo,$tide.hilo) ($tide.offset.nolabel('%.1f'))<br/>
    #end if
  #end for
        </td>
#end if
#if $show_sun
        <td class='col-sun'>
  #if $alm.hasExtras
          $alm.sun.rise<br/>
          $alm.sun.set
  #else
          $alm.sunrise<br/>
          $alm.sunset
  #end if
        </td>
#end if
#if $show_moon
  #if $alm.hasExtras
        <td class='col-moon'>
          $alm.moon.rise<br/>
          $alm.moon.set
        </td>
  #end if
        <td class='col-moonphase'>
          $alm.moon_fullness%
        </td>
#end if
#if $show_pop
        <td class='col-pop'>
  #if $summary.pop.raw > 0
          $summary.pop.format('%.0f','')<br/>
    #if $summary.qpf.raw > 0
          $summary.qpf.nolabel('%.2f','') <img class='pop-img' src='$icondir/raindrop.png' /><br/>
    #end if
    #if $summary.qsf.raw > 0
          $summary.qsf.nolabel('%.2f','') <img class='pop-img' src='$icondir/snowflake.png' />
    #end if
  #end if
        </td>
#end if
#if $show_precip
        <td class='col-precip'>
  #for $k in $summary.precip
    #set $precip_img = $icondir + '/' + $k + '.png'
         <img class='precip-img' src='$precip_img' alt='$k' title='$forecast.label('Weather', $k)' />
  #end for
        </td>
#end if
#if $show_obvis
        <td class='col-obvis'>
  #for $k in $summary.obvis
    #set $obvis_img = $icondir + '/' + $k + '.png'
         <img class='obvis-img' src='$obvis_img' alt='$k' title='$forecast.label('Weather', $k)' />
  #end for
        </td>
#end if
      </tr>
  </div>

  #end if ## lastday != thisday

#if $show_hourly and $num_hours > 0
 #if $skip_first
  #set $skip_first = 0
 #else
  #set $ftime = $period.event_ts.format('%H:%M')
  #set $num_hours = $num_hours - 1
      <tr class='period $hourid' style='display:none'>
        <td class='disclosure'></td>
#if $show_day or $show_date
        <td class='col-date'>$ftime<br/></td>
#end if
#if $show_outlook
        <td class='col-outlook'>
  #if $period.clouds is not None
    #if $sunrise_ts < $period.event_ts.raw < $sunset_ts
      #set $outlook_img = $icondir + '/' + $period.clouds + '.png'
    #else
      #set $outlook_img = $icondir + '/' + $period.clouds + 'n.png'
    #end if
          <img class='outlook-img' src='$outlook_img' alt='$period.clouds' title='$forecast.label('Weather', $period.clouds)' />
  #end if
        </td>
#end if
#if $show_temp
        <td class='col-temp'>$period.temp.nolabel('%.0f')</td>
#end if
#if $show_dewpoint
        <td class='col-dewpoint'>$period.dewpoint.nolabel('%.0f')</td>
#end if
#if $show_humidity
        <td class='col-humidity'>$period.humidity.nolabel('%.0f',' ')</td>
#end if
#if $show_wind
        <td class='col-wind'
  #if $period.windDir is not None
    #set $winddir_img = $icondir + '/' + $wind_dir_dict.get($period.windDir,$period.windDir) + '.png'
          background='$winddir_img' background-repeat:no-repeat; background-position:center; background-size:32px;'
  #end if
            >
          $period.windSpeed.nolabel('%.0f',' ') <span class='windgust'>$period.windGust.nolabel('%.0f',' ')</span>$period.windChar<br/>
        </td>
#end if
#if $show_tides and len($tides) > 0
        <td class='col-tides'>
  #for $tide in $tides
    #if $period.event_ts.raw <= $tide.event_ts.raw < $period.event_ts.raw + $period.duration and $tide.event_ts.raw < $nextday_ts
       $tide.event_ts.format('%H:%M') $tide_dict.get($tide.hilo,$tide.hilo) ($tide.offset.nolabel('%.1f'))
    #end if
  #end for
        </td>
#end if
#if $show_sun
        <td class='col-sun'>
  #if $period.event_ts.raw <= $sunrise_ts < $period.event_ts.raw + $period.duration
          $alm.sunrise
  #end if
  #if $period.event_ts.raw <= $sunset_ts < $period.event_ts.raw + $period.duration
          $alm.sunset
  #end if
        </td>
#end if
#if $show_moon
  #if $alm.hasExtras
        <td class='col-moon'>
  #if $period.event_ts.raw <= $moonrise_ts < $period.event_ts.raw + $period.duration and $moonrise_ts < $nextday_ts
          $alm.moon.rise
  #end if
  #if $period.event_ts.raw <= $moonset_ts < $period.event_ts.raw + $period.duration and $moonset_ts < $nextday_ts
          $alm.moon.set
  #end if
        </td>
  #end if
        <td class='col-moonphase'></td>
#end if
#if $show_pop
        <td class='col-pop'>
  #if $period.pop.raw > 0
          $period.pop.format('%.0f',' ')<br/>
    #if $period.qpf.raw > 0
          $period.qpf.nolabel('%.2f',' ') <img class='pop-img' src='$icondir/raindrop.png' /><br/>
    #end if
    #if $period.qsf.raw > 0
          $period.qsf.nolabel('%.2f',' ') <img class='pop-img' src='$icondir/snowflake.png' />
    #end if
  #end if
        </td>
#end if
#if $show_precip
        <td class='col-precip'>
  #for $k,$v in $period.precip.items()
    #set $precip_img = $icondir + '/' + $k + '.png'
            <img class='precip-img' src='$precip_img' alt='$k' title='$forecast.label('Weather', $k)' />
            <br/>
    #if $v != ''
            $forecast.label('Weather', $v+'q')
    #else
            &nbsp;
    #end if
          <br/>
  #end for
          <br/>
        </td>
#end if
#if $show_obvis
        <td class='col-obvis'>
  #if $period.obvis is not None
    #set $obvis_img = $icondir + '/' + $period.obvis + '.png'
          <img class='obvis-img' src='$obvis_img' alt='$period.obvis' title='$forecast.label('Weather', $period.obvis)' />
  #end if
        </td>
#end if
      </tr>
 #end if  ## skip_first
#end if  ## show_hourly
#end for ## period in periods

  </table>
#if $show_hourly
  </div>
#end if
  <div class='sources'>
    <p>
#if $show_tides and len($tides) > 0
      Tides for $tides[0].location issued on $tides[0].issued_ts<br/>
#end if
      $forecast_source forecast
#if $wloc is not None and $wloc != ''
 for $wloc
#end if
#if $wts is not None and $wts != ''
 issued on $wts
#end if
    </p>
  </div>

</div>

#else

<!-- forecasting is not installed -->

#end if
