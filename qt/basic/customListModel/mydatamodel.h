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
        DurationRole,
        EnableRole
    };

    explicit MyDataModel(QObject * parent = nullptr);

    int rowCount(const QModelIndex &p = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role) const override;
    Q_INVOKABLE QVariantMap get(int row) const;

    Q_INVOKABLE bool selectUser(int index, bool check);
    Q_INVOKABLE bool selectAllUser(bool check);
    Q_INVOKABLE bool restoreAllUser();
    Q_INVOKABLE void removeAll();

    int count() const;

public slots:
    void append(QObject *o);
    void insert(QObject *o, int i);
    void remove(int idx);

signals:
    void countChanged(int count);

private:
    QList<QObject*> m_data;
};

#endif // MYDATAMODEL_H
