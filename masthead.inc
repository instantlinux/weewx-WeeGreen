<div id="masthead">
        <h1>$station.location</h1>
        <h2>$pageTitle</h2>
        <h2>$current.dateTime</h2>
        <input type="button" value="   Current   " onclick="openURL('current.html')" />
        #if $varExists('forecast')
          <input type="button" value="   Forecast  " onclick="openURL('forecast.html')" />
        #end if
        <input type="button" value="    Week     " onclick="openURL('week.html')" />
        <input type="button" value="    Month    " onclick="openURL('month.html')" />
        <input type="button" value="    Year     " onclick="openURL('year.html')" />
        <select NAME=noaaselect onchange="openNoaaFile(value)">
          #for $monthYear in $SummaryByMonth
            <option value="$monthYear">$monthYear</option>
          #end for
          #for $yr in $SummaryByYear
            <option value="$yr">$yr</option>
          #end for
          <option selected>Almanac</option>
        </select>
        #if $Extras.has_key('wundergroundLink')
          <input type="button" value=" Wunderground " onclick="window.open('$Extras.wundergroundLink', '_blank')" />
        #end if
        <input type="button" value="   About   " onclick="openURL('about.html')" />
</div>
