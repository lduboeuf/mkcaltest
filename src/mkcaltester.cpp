#include "mkcaltester.h"

#include <KCalendarCore/OccurrenceIterator>
#include <KCalendarCore/Event>

#include <extendedcalendar.h>
#include <sqlitestorage.h>

#include <QDebug>

/*
class MKCalStorageObserver: public QObject, public ExtendedStorageObserver
{
    Q_OBJECT
public:
    MKCalStorageObserver(ExtendedStorage::Ptr storage): storage(storage)
    {
        storage->registerObserver(this);
    }
    ~MKCalStorageObserver()
    {
        storage->unregisterObserver(this);
    }

    void storageModified(ExtendedStorage *storage, const QString &info)
    {
        emit modified();
    }

    void storageUpdated(ExtendedStorage *storage,
                        const KCalendarCore::Incidence::List &added,
                        const KCalendarCore::Incidence::List &modified,
                        const KCalendarCore::Incidence::List &deleted)
    {
        emit updated(added, modified, deleted);
    }

signals:
    void modified();
    void updated(const KCalendarCore::Incidence::List &added,
                 const KCalendarCore::Incidence::List &modified,
                 const KCalendarCore::Incidence::List &deleted);

private:
    ExtendedStorage::Ptr storage;
};
*/

MkCalTester::MkCalTester()
{
}

void MkCalTester::testListEvents()
{
    mKCal::ExtendedCalendar::Ptr cal(new mKCal::ExtendedCalendar(QTimeZone()));
    mKCal::ExtendedStorage::Ptr storage = cal->defaultStorage(cal);
    storage->open();

    const QDateTime startDateTime = QDateTime::fromString("2010-01-01");
    const QDateTime endDateTime = QDateTime::fromString("2025-01-01");

    storage->load(startDateTime.date(), endDateTime.date());
    QList<QString> visibleNotebooks;
    for (const mKCal::Notebook::Ptr &nb : storage->notebooks()) {
        if (nb->isVisible()) {
            visibleNotebooks.append(nb->uid());
        }
    }
    qDebug() << "visible nbs" << visibleNotebooks;


    KCalendarCore::OccurrenceIterator it(*cal, startDateTime, endDateTime);
    while (it.hasNext()) {
        it.next();
        KCalendarCore::Incidence::Ptr incidence = it.incidence();

        const QByteArray notebookUid = cal->notebook(incidence).toUtf8();
        if (visibleNotebooks.contains(notebookUid)) {
            if (incidence->type() == KCalendarCore::Incidence::TypeEvent) {
                const KCalendarCore::Event::Ptr &event = incidence.staticCast<KCalendarCore::Event>();
                qDebug() << "title" << event->summary();
                qDebug() << "dtStart" << event->dtStart();
                qDebug() << "dtEnd" << event->dtEnd();


                for (const KCalendarCore::Alarm::Ptr alarm : incidence->alarms()) {
                    qDebug() << "alarmType:" << alarm->type();
                    if (alarm->type() == KCalendarCore::Alarm::Audio) {
                         qDebug() << "Alarm audiofile" << alarm->audioFile();
                    } else if (alarm->type() == KCalendarCore::Alarm::Display) {
                         qDebug() << "Alarm text" << alarm->text();
                    }

                    qDebug() << "Second before start" << alarm->startOffset().asSeconds();
                    qDebug() << "Repetition" << alarm->snoozeTime().asSeconds();
                }
            }
        }

    }



}

