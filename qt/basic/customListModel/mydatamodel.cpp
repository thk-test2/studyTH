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

void MyDataModel::append(QObject *o)
{
    m_data.append(o);
    emit countChanged(m_data.count());
}

void MyDataModel::insert(QObject *o, int i)
{
    m_data.insert(i, o);
    emit countChanged(m_data.count());
}

void MyDataModel::remove(int idx)
{
    m_data.removeAt(idx);
    emit countChanged(m_data.count());
}

int MyDataModel::count() const
{
    return m_data.count();
}
