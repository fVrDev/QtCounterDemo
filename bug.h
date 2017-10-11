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
    Q_PROPERTY(qreal ratioX READ ratioX WRITE setRatioX NOTIFY ratioXChanged)
    Q_PROPERTY(qreal ratioY READ ratioY WRITE setRatioY NOTIFY ratioYChanged)

public:
    explicit Bug(QObject *parent = nullptr);

    qreal positionX() const;
    qreal positionY() const;
    qreal velocityX() const;
    qreal velocityY() const;
    qreal ratioX   () const;
    qreal ratioY   () const;

signals:
    void positionXChanged(qreal val);
    void positionYChanged(qreal val);
    void velocityXChanged(qreal val);
    void velocityYChanged(qreal val);
    void ratioXChanged   (qreal ratioX);
    void ratioYChanged   (qreal ratioY);

public slots:
    void setPositionX(qreal val);
    void setPositionY(qreal val);
    void setVelocityX(qreal val);
    void setVelocityY(qreal val);
    void setRatioX   (qreal ratioX);
    void setRatioY   (qreal ratioY);

private:
    qreal m_positionX = 0;
    qreal m_positionY = 0;
    qreal m_velocityX = 0;
    qreal m_velocityY = 0;
    qreal m_ratioX    = 0;
    qreal m_ratioY    = 0;
};

#endif // BUG_H
