## Specifying an encoding of UTF-8 is usually safe, but if your text is
## actually in Latin-1, then you should replace the string "UTF-8" with "latin-1"
#encoding UTF-8
<!DOCTYPE HTML PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head profile="http://www.w3.org/2005/10/profile">
    #if $encoding == 'utf8'
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    #end if
    <title>$station.location $pageTitle</title>
    <link rel="stylesheet" type="text/css" href="weewx.css"/>
    <link rel="icon" type="image/png" href="favicon.ico" />
    <script type="text/javascript">
      var refreshInt = 300;
      function openURL(urlname) {
        window.location=urlname;
      }
      function openNoaaFile(date) {
        var url = "NOAA/NOAA-";
        url = url + date;
        url = url + ".txt";
        window.location=url;
      }
      function createCookie(name,value,days) {
        if (days) {
          var date = new Date();
          date.setTime(date.getTime()+(days*24*60*60*1000));
          var expires = "; expires="+date.toGMTString();
        }
        else var expires = "";
        document.cookie = name+"="+value+expires+"; path=/";
      }
      function readCookie(name) {
        var nameEQ = name + "=";
        var ca = document.cookie.split(';');
        for (var i=0; i < ca.length; i++) {
          var c = ca[i];
          while (c.charAt(0)==' ') c = c.substring(1,c.length);
          if (c.indexOf(nameEQ) == 0)
            return c.substring(nameEQ.length,c.length);
        }
        return null;
      }
      function eraseCookie(name) {
        createCookie(name,"",-1);
      }
      function autoRefresh() {
        if (readCookie('refreshEnabled') != 'true') {
          createCookie('refreshEnabled','true',9999);
          var startRefresh = setTimeout("window.location.reload()",refreshInt * 1000);
        }
        else {
          eraseCookie('refreshEnabled');
          clearTimeout(startRefresh);
        }
      }
      function buttonColor(id) {
        if (readCookie('refreshEnabled') == 'true') {
          document.getElementById(id).style.background = "#a5f595";
        } else {
          document.getElementById(id).style.background = "#fafaff";
        }
      }
      function initialButtonColors() {
        buttonColor('refbutton')
      }
      window.onload = initialButtonColors;
    </script>
  </head>
