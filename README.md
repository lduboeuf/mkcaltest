# mkcaltest


mkCal is a Sailfish project extending KDE KCalendarCore
see https://github.com/sailfishos/mkcal

mkCal to QtPIM QOrganizer is located in https://github.com/dcaliste/qtorganizer-mkcal/tree/master

## debugging: 
 - QT_LOGGING_RULES=*.mkcal.debug=true
 - overriding the default db ( $home/.local/share/system/privileged/Calendar/mkcal/db ) : SQLITESTORAGEDB=/path/to/db

## tests

 - a database could be generated from mkCal tests, e.g https://github.com/sailfishos/mkcal/blob/master/tests/tst_perf.cpp#L48 (just comment the database removals at end of the tests ), this will land in /tmp/db
   
