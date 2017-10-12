#ifndef BUGSSCENE_H
#define BUGSSCENE_H

#include <QObject>
#include <QVector>
#include <QQmlListProperty>

#include "bug.h"

class BugsScene : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal spaceWidth READ spaceWidth WRITE setSpaceWidth )
    Q_PROPERTY(qreal spaceHeight READ spaceHeight WRITE setSpaceHeight )
    Q_PROPERTY(QQmlListProperty<Bug> data READ data NOTIFY dataChanged)

public:
    explicit BugsScene(QObject *parent = nullptr);
    qreal spaceWidth() const;
    qreal spaceHeight() const;

    QQmlListProperty<Bug> data();

public slots:
    void setSpaceWidth(qreal spaceWidth);
    void setSpaceHeight(qreal spaceHeight);
    void add();
    void recalc();

signals:
    void dataChanged(QQmlListProperty<Bug> data);

private:
//    static QQmlListProperty<Bug>::AppendFunction appendF;
//    static QQmlListProperty<Bug>::AtFunction     atF;
//    static QQmlListProperty<Bug>::ClearFunction  clearF;
//    static QQmlListProperty<Bug>::CountFunction  countF;

    qreal m_spaceWidth;
    qreal m_spaceHeight;

    class QTimer *m_recalcTimer = nullptr;

    QList<Bug*> m_data;
};

#endif // BUGSSCENE_H
