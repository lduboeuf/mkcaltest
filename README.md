# mkcaltest


mkCal is a Sailfish project extending KDE KCalendarCore
see https://github.com/sailfishos/mkcal

mkCal to QtPIM QOrganizer is located in https://github.com/dcaliste/qtorganizer-mkcal/tree/master

## debugging: 
 - QT_LOGGING_RULES=*.mkcal.debug=true
 - overriding the default db ( $home/.local/share/system/privileged/Calendar/mkcal/db ) : SQLITESTORAGEDB=/path/to/db