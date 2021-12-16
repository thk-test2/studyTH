
#include <QList>
#include <QDebug>
#include "mydatamodel.h"

MyDataModel::MyDataModel(QObject * parent)
    : QAbstractListModel(parent)
{

}

int MyDataModel::rowCount(const QModelIndex &p) const
{
    Q_UNUSED(p)
    return m_data.size();
}

QHash<int, QByteArray> MyDataModel::roleNames() const
{
    static QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[ArtistNameRole] = "artistName";
    roles[DurationRole] = "duration";
    roles[EnableRole] = "enable";
    return roles;
}

QVariant MyDataModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)

    QVariant value;

    switch(role)
    {
    case TitleRole:
        value = m_data[index.row()]->property("title");
        break;
    case ArtistNameRole:
        value = m_data[index.row()]->property("artistName");
        break;
    case DurationRole:
        value = m_data[index.row()]->property("duration");
        break;
    case EnableRole:
        value = m_data[index.row()]->property("enable");
    default:
        break;
    }

    return value;
}

QVariantMap MyDataModel::get(int row) const {
    QVariantMap data;
    const QModelIndex idx = this->index(row, 0);
    if (!idx.isValid()) {
        return data;
    }
    QHashIterator<int, QByteArray> it(this->roleNames());
    while (it.hasNext()) {
        it.next();
        data[it.value()] = idx.data(it.key());
    }
    return data;
}

bool MyDataModel::selectUser(int idx, bool check)
{
    if ((rowCount() <= 0) || (idx < 0) || (rowCount() <= idx))
        return false;

//    UserListItem *p = m_users.at(idx);
//    p->check = check;

    QModelIndex r1 = index(idx);
    QModelIndex r2 = index(idx);

    Q_EMIT dataChanged(r1,r2);

    return true;
}

bool MyDataModel::selectAllUser(bool check)
{
    if (rowCount() <= 0)
        return false;

    for (int i = rowCount() - 1; i >= 0; i--) {
//        UserListItem *p = m_users.at(i);
//        p->check = check;

        QModelIndex r1 = index(i);
        QModelIndex r2 = index(i);
        Q_EMIT dataChanged(r1,r2);
    }

    return true;
}

bool MyDataModel::restoreAllUser()
{
    if (rowCount() <= 0)
        return false;

    for (int i = rowCount() - 1; i >= 0; i--) {
//        UserListItem *p = m_users.at(i);
//        p->check = false;

        QModelIndex r1 = index(i);
        QModelIndex r2 = index(i);

        Q_EMIT dataChanged(r1,r2);
    }

    return true;
}

void MyDataModel::append(QObject *o)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(o);
//    m_data << o;
    endInsertRows();
    emit countChanged(m_data.count());
}

void MyDataModel::insert(QObject *o, int i)
{
    m_data.insert(i, o);
    emit countChanged(m_data.count());
}

void MyDataModel::remove(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    m_data.removeAt(idx);
    endRemoveRows();
    emit countChanged(m_data.count());
}

int MyDataModel::count() const
{
    return m_data.count();
}

void MyDataModel::removeAll()
{
    qDebug() << "removeAll()";
//    QList<QObject *>::iterator i = m_data.begin();
//    while (i != m_data.end()) {
//        qDebug() << *i;
//        i = m_data.erase(i);
//    }
    for (int i = rowCount() - 1; i >= 0; i--) {
        remove(i);
    }
}
