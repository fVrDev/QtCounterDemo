#include "bugsscene.h"

#include <QTimer>
#include <QDebug>
#include <QtMath>

BugsScene::BugsScene(QObject *parent) : QAbstractListModel(parent)
{
    m_recalcTimer = new QTimer(this);
    connect(m_recalcTimer, SIGNAL(timeout()), this, SLOT(recalc()));
    m_recalcTimer->start(20);
    m_lastRecalcTime = QTime::currentTime();
}

qreal BugsScene::spaceWidth() const
{
    return m_spaceWidth;
}

qreal BugsScene::spaceHeight() const
{
    return m_spaceHeight;
}

qreal BugsScene::startSpeed() const
{
    return m_startSpeed;
}

void BugsScene::setSpaceWidth(qreal spaceWidth)
{
    m_spaceWidth = spaceWidth;
    emit spaceWidthChanged(m_spaceWidth);
}

void BugsScene::setSpaceHeight(qreal spaceHeight)
{
    m_spaceHeight = spaceHeight;
    emit spaceHeightChanged(m_spaceHeight);
}

void BugsScene::add()
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());

    m_data.append(new Bug(this));

    auto* bug = m_data.back();
    bug->setPositionX(spaceWidth()/2.0);
    bug->setPositionY(spaceHeight()/2.0);

    const qreal startSpeedX = qrand() % (int)(2*startSpeed()) - startSpeed();
    bug->setVelocityX( startSpeedX );

    const qreal startSpeedY = qSqrt( startSpeed()*startSpeed() - startSpeedX*startSpeedX ) * (qrand() % 2 ? 1 : -1);
    bug->setVelocityY( startSpeedY );

    endInsertRows();
}

void BugsScene::clear()
{
    beginRemoveRows(QModelIndex(), 0, m_data.size());
    m_data.clear();
    endRemoveRows();
}

void BugsScene::recalc()
{
    qreal deltaT = m_lastRecalcTime.msecsTo(QTime::currentTime())/1000.f;

    for( auto* bug : m_data )
    {
        qreal x = bug->positionX() + bug->velocityX() * deltaT;

        if( x > 0 && x < spaceWidth() )
        {
            bug->setPositionX(x);
        }
        else
        {
            bug->setVelocityX(-bug->velocityX());
        }

        qreal y = bug->positionY() + bug->velocityY() * deltaT;

        if( y > 0 && y < spaceHeight() )
        {
            bug->setPositionY(y);
        }
        else
        {
            bug->setVelocityY(-bug->velocityY());
        }
    }

    m_lastRecalcTime = QTime::currentTime();

    emit dataChanged(createIndex(0,0), createIndex(m_data.size(),0));
}

void BugsScene::setStartSpeed(qreal startSpeed)
{
    m_startSpeed = startSpeed;
    emit startSpeedChanged(m_startSpeed);
}


int BugsScene::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

QVariant BugsScene::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() && index.row() >= m_data.size())
    {
        return QVariant();
    }

    const auto* bug = m_data[index.row()];

    switch (role)
    {
    case posX:
        return bug->positionX();
    case posY:
        return bug->positionY();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> BugsScene::roleNames() const
{
    auto roles = QAbstractListModel::roleNames();
    roles[posX] = "posX";
    roles[posY] = "posY";
    return roles;
}
