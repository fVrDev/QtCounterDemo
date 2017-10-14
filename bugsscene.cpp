#include "bugsscene.h"

#include <QTimer>
#include <QDebug>
#include <QtMath>

BugsScene::BugsScene(QObject *parent) : QObject(parent)
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

uint BugsScene::count() const
{
    return m_data.count();
}

QQmlListProperty<Bug> BugsScene::data()
{
    return QQmlListProperty<Bug>(qobject_cast<QObject *>(this), m_data);
}

qreal BugsScene::startSpeed() const
{
    return m_startSpeed;
}

void BugsScene::setSpaceWidth(qreal spaceWidth)
{
    m_spaceWidth = spaceWidth;
}

void BugsScene::setSpaceHeight(qreal spaceHeight)
{
    m_spaceHeight = spaceHeight;
}

void BugsScene::add()
{
    m_data.append(new Bug(this));

    auto* bug = qobject_cast<Bug*>(m_data.back());
    bug->setPositionX(spaceWidth()/2.0);
    bug->setPositionY(spaceHeight()/2.0);
    bug->setRatioX(0.5);
    bug->setRatioY(0.5);

    const qreal startSpeedX = qrand() % (int)(2*startSpeed()) - startSpeed();
    bug->setVelocityX( startSpeedX );

    const qreal startSpeedY = qSqrt( startSpeed()*startSpeed() - startSpeedX*startSpeedX ) * (qrand() % 2 ? 1 : -1);
    bug->setVelocityY( startSpeedY );

    emit dataChanged(data());
}

void BugsScene::recalc()
{
    qreal deltaT = m_lastRecalcTime.msecsTo(QTime::currentTime())/1000.f;

    for( auto* obj : m_data )
    {
        auto* bug = qobject_cast<Bug*>(obj);

        qreal x = bug->positionX() + bug->velocityX() * deltaT;

        if( x > 0 && x < spaceWidth() )
        {
            bug->setPositionX(x);
            bug->setRatioX(x/spaceWidth());
        }
        else
        {
            bug->setVelocityX(-bug->velocityX());
        }

        qreal y = bug->positionY() + bug->velocityY() * deltaT;

        if( y > 0 && y < spaceHeight() )
        {
            bug->setPositionY(y);
            bug->setRatioY(y/spaceHeight());
        }
        else
        {
            bug->setVelocityY(-bug->velocityY());
        }
    }

    m_lastRecalcTime = QTime::currentTime();

    emit dataChanged(data());
}

void BugsScene::setStartSpeed(qreal startSpeed)
{
    m_startSpeed = startSpeed;
}
