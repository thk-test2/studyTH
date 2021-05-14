#ifndef MYDATAMODEL_H
#define MYDATAMODEL_H

#include <QAbstractListModel>

class MyDataModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    enum ModelRoles {
        TitleRole = Qt::UserRole + 1,
        ArtistNameRole,
        DurationRole
    };

    explicit MyDataModel(QObject * parent = nullptr);

    int rowCount(const QModelIndex &p) const;
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;

    int count() const;

public slots:
    void append(QObject *o);
    void insert(QObject *o, int i);
    void remove (int idx);

signals:
    void countChanged(int count);

private:
    QList<QObject*> m_data;
};

#endif // MYDATAMODEL_H
