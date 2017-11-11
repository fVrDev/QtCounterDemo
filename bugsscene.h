#ifndef BUGSSCENE_H
#define BUGSSCENE_H

#include <QObject>
#include <QVector>
#include <QAbstractListModel>
#include <QTime>

#include "bug.h"

class BugsScene : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(qreal spaceWidth READ spaceWidth WRITE setSpaceWidth NOTIFY spaceWidthChanged )
    Q_PROPERTY(qreal spaceHeight READ spaceHeight WRITE setSpaceHeight NOTIFY spaceHeightChanged )
    Q_PROPERTY(qreal startSpeed READ startSpeed WRITE setStartSpeed NOTIFY startSpeedChanged )

public:
    explicit BugsScene(QObject *parent = nullptr);
    qreal spaceWidth() const;
    qreal spaceHeight() const;
    qreal startSpeed() const;

public slots:
    void setSpaceWidth(qreal spaceWidth);
    void setSpaceHeight(qreal spaceHeight);
    void setStartSpeed(qreal startSpeed);
    void add();
    void clear();
    void recalc();

private:
    qreal m_spaceWidth;
    qreal m_spaceHeight;
    qreal m_startSpeed;

    class QTimer *m_recalcTimer = nullptr;

    QList<Bug*> m_data;

    QTime m_lastRecalcTime;

    // QAbstractListModel interface
public:
    enum Roles
    {
        posX = Qt::UserRole
        , posY
    };

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
signals:
    void spaceWidthChanged(qreal spaceWidth);
    void spaceHeightChanged(qreal spaceHeight);
    void startSpeedChanged(qreal startSpeed);
};

#endif // BUGSSCENE_H
