#ifndef LOGLISTMODEL_H
#define LOGLISTMODEL_H

#include <QAbstractListModel>
#include <memory>

class LogList;

class LogListModel : public QAbstractListModel {
  Q_OBJECT
public:
  explicit LogListModel(QObject *parent = nullptr);
  LogListModel(const LogListModel&) { }

  enum {
    LogIdxRole = Qt::UserRole,
    STimeRole,
    ETimeRole,
    SurgeonIdxRole,
    ToolListRole
  };

  // QAbstractItemModel interface
  int rowCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role) const;
  QHash<int, QByteArray> roleNames() const;

private:
  std::unique_ptr<LogList> mList_;
};

Q_DECLARE_METATYPE(LogListModel);

#endif // LOGLISTMODEL_H
