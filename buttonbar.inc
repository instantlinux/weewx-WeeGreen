<div id="navbar">
  <input type="button" value="   RSS   " onclick="openURL('RSS/weewx_rss.xml')" />
  <input type="button" value=" Flip-Phone Format " onclick="openURL('mobile.html')" />
  <input type="button" value=" Smartphone Format " onclick="openURL('smartphone/index.html')" />
  <input type="button" value=" Auto Refresh " id='refbutton' onclick="autoRefresh();buttonColor('refbutton');" />
  <div class="sources">
    <p>Weewx uptime:  $station.uptime<br/>
       Server uptime: $station.os_uptime</p>
  </div>
</div>
