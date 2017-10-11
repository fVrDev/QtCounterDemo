#ifndef BUGSSCENE_H
#define BUGSSCENE_H

#include <QObject>
#include <QVector>
#include <QQmlListProperty>

class BugsScene : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal spaceWidth READ spaceWidth WRITE setSpaceWidth )
    Q_PROPERTY(qreal spaceHeight READ spaceHeight WRITE setSpaceHeight )
    Q_PROPERTY(QQmlListProperty<class Bug> data READ data NOTIFY on_data)

public:
    explicit BugsScene(QObject *parent = nullptr);
    qreal spaceWidth() const;
    qreal spaceHeight() const;

    QQmlListProperty<class Bug> data();

public slots:
    void setSpaceWidth(qreal spaceWidth);
    void setSpaceHeight(qreal spaceHeight);
    void add();
    void recalc();

signals:
    void on_data(QQmlListProperty<Bug> data);

private:
    qreal m_spaceWidth;
    qreal m_spaceHeight;

    class QTimer *m_recalcTimer = nullptr;

    QList<QObject*> m_data;
};

#endif // BUGSSCENE_H
