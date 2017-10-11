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

qreal Bug::ratioX() const
{
    return m_ratioX;
}

qreal Bug::ratioY() const
{
    return m_ratioY;
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

void Bug::setRatioX(qreal ratioX)
{
    m_ratioX = ratioX;
    emit ratioXChanged(m_ratioX);
}

void Bug::setRatioY(qreal ratioY)
{
    m_ratioY = ratioY;
    emit ratioYChanged(m_ratioY);
}
