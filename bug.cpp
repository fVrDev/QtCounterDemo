#include "bug.h"

Bug::Bug(QObject *parent) : QObject(parent)
{
}

qreal Bug::positionX() const
{
    return m_positionX;
}

qreal Bug::positionY() const
{
    return m_positionY;
}

qreal Bug::velocityX() const
{
    return m_velocityX;
}

qreal Bug::velocityY() const
{
    return m_velocityY;
}

void Bug::setPositionX(qreal val)
{
    m_positionX = val;
    emit positionXChanged(m_positionX);
}

void Bug::setPositionY(qreal val)
{
    m_positionY = val;
    emit positionYChanged(m_positionY);
}

void Bug::setVelocityX(qreal val)
{
    m_velocityX = val;
    emit velocityXChanged(m_velocityX);
}

void Bug::setVelocityY(qreal val)
{
    m_velocityY = val;
    emit velocityYChanged(m_velocityY);
}
