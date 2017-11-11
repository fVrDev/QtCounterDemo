#ifndef BUG_H
#define BUG_H

#include <QObject>

class Bug : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal positionX READ positionX WRITE setPositionX NOTIFY positionXChanged)
    Q_PROPERTY(qreal positionY READ positionY WRITE setPositionY NOTIFY positionYChanged)
    Q_PROPERTY(qreal velocityX READ velocityX WRITE setVelocityX NOTIFY velocityXChanged)
    Q_PROPERTY(qreal velocityY READ velocityY WRITE setVelocityY NOTIFY velocityYChanged)

public:
    explicit Bug(QObject *parent = nullptr);

    qreal positionX() const;
    qreal positionY() const;
    qreal velocityX() const;
    qreal velocityY() const;

signals:
    void positionXChanged(qreal val);
    void positionYChanged(qreal val);
    void velocityXChanged(qreal val);
    void velocityYChanged(qreal val);

public slots:
    void setPositionX(qreal val);
    void setPositionY(qreal val);
    void setVelocityX(qreal val);
    void setVelocityY(qreal val);

private:
    qreal m_positionX = 0;
    qreal m_positionY = 0;
    qreal m_velocityX = 0;
    qreal m_velocityY = 0;
};

#endif // BUG_H
