#include "bugsscene.h"

#include <QTimer>

BugsScene::BugsScene(QObject *parent) : QObject(parent)
{
    m_recalcTimer = new QTimer(this);
    m_recalcTimer->setInterval(100);
    connect(m_recalcTimer, SIGNAL(QTimer::timeout), this, SLOT(recalc()));
}

qreal BugsScene::spaceWidth() const
{
    return m_spaceWidth;
}

qreal BugsScene::spaceHeight() const
{
    return m_spaceHeight;
}

QQmlListProperty<Bug> BugsScene::data()
{
    return QQmlListProperty<Bug>(qobject_cast<QObject *>(this), m_data);
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
    bug->setVelocityX( qrand() % 10 );
    bug->setVelocityY( qrand() % 10 );
}

void BugsScene::recalc()
{
    for( auto* obj : m_data )
    {
        auto* bug = qobject_cast<Bug*>(obj);

        qreal x = bug->positionX() + bug->velocityX();

        if( x > 0 && x < spaceWidth() )
        {
            bug->setPositionX(x);
            bug->setRatioX(x/spaceWidth());
        }
        else
        {
            bug->setVelocityX(-bug->velocityX());
        }

        qreal y = bug->positionY() + bug->velocityY();

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
}

//void BugsScene::appendF(QQmlListProperty<Bug> *property, Bug *value)
//{
//    property->append(value);
//}

//Bug* BugsScene::atF(QQmlListProperty<Bug> *property, int index)
//{
//    return property->at(index);
//}

//void BugsScene::clearF(QQmlListProperty<Bug> *property)
//{
//    property->clear();
//}

//int BugsScene::countF(QQmlListProperty<Bug> *property)
//{
//    return property->count();
//}
