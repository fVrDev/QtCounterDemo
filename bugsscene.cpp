#include "bugsscene.h"
#include "bug.h"

#include <QTimer>

BugsScene::BugsScene(QObject *parent) : QObject(parent)
{
    m_recalcTimer = new QTimer(this);
    m_recalcTimer->setInterval(100);
    connect(m_recalcTimer, &QTimer::timeout, SLOT(recalc));
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
    return QQmlListProperty<Bug>(static_cast<QObject *>(this), m_data);
}

void BugsScene::add()
{
    m_data.append(new Bug(this));

    auto* bug = qobject_cast<Bug*>(obj);
    bug->setPositionX(spaceWidth()/2.0);
    bug->setPositionY(spaceHeight()/2.0);
    bug->setRatioX(0.5);
    bug->setRatioY(0.5);
    bug->setVelocityX( rand() % 10.0 );
    bug->setVelocityY( rand() % 10.0 );
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
