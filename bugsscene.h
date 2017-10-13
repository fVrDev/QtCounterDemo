#ifndef BUGSSCENE_H
#define BUGSSCENE_H

#include <QObject>
#include <QVector>
#include <QQmlListProperty>
#include <QTime>

#include "bug.h"

class BugsScene : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal spaceWidth READ spaceWidth WRITE setSpaceWidth )
    Q_PROPERTY(qreal spaceHeight READ spaceHeight WRITE setSpaceHeight )
    Q_PROPERTY(qreal startSpeed READ startSpeed WRITE setStartSpeed )
    Q_PROPERTY(QQmlListProperty<Bug> data READ data NOTIFY dataChanged)
    Q_PROPERTY(uint count READ count)

public:
    explicit BugsScene(QObject *parent = nullptr);
    qreal spaceWidth() const;
    qreal spaceHeight() const;
    uint count() const;
    qreal startSpeed() const;

    QQmlListProperty<Bug> data();

public slots:
    void setSpaceWidth(qreal spaceWidth);
    void setSpaceHeight(qreal spaceHeight);
    void setStartSpeed(qreal startSpeed);
    void add();
    void recalc();


signals:
    void dataChanged(QQmlListProperty<Bug> data);

private:
    qreal m_spaceWidth;
    qreal m_spaceHeight;
    qreal m_startSpeed;

    class QTimer *m_recalcTimer = nullptr;

    QList<Bug*> m_data;

    QTime m_lastRecalcTime;
};

#endif // BUGSSCENE_H
