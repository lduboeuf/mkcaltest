#include <QCoreApplication>
#include <QDebug>

#include "mkcaltester.h"

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);

    MkCalTester mkcaltester;
    mkcaltester.testListEvents();

    qDebug() << "kikou olala";

    // QT_LOGGING_RULES=*.mkcal.debug=true
    // SQLITESTORAGEDB=/path/to/db

    //return app.exec();
    exit(0);
}
