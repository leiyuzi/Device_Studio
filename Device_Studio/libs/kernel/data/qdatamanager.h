#ifndef QDATAMANAGER_H
#define QDATAMANAGER_H

#include <QObject>
#include <QMap>

class QDataGroup;
class QAbstractDataHost;

class QDataManager : public QObject
{
    Q_OBJECT
public:
    explicit QDataManager(QObject *parent = 0);
    ~QDataManager();

    void    addGroup(const QString & groupName,int index = -1);
    void    delGroup(QDataGroup * group);

    QAbstractDataHost * getData(const QString & name);
    QAbstractDataHost * getDataByUuid(const QString & uuid);

    QList<QDataGroup*>  getGroups();
    QDataGroup*         getGroup(const QString & name);
    QDataGroup*         getGropuByUuid(const QString & uuid);

    bool    save(const QString & path);
    bool    load(const QString & path);
signals:
    void    groupAdded(QDataGroup * group,int index);
    void    groupDeled(QDataGroup * group);
protected:
    QList<QDataGroup*>   m_groups;
    QMap<QString,QDataGroup*>   m_uuidToGroup;
};

#endif // QDATAMANAGER_H
