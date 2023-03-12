#ifndef LOGLISTMODEL_H
#define LOGLISTMODEL_H

#include <QAbstractListModel>
#include <memory>

class LogList;

class LogListModel : public QAbstractListModel {
  Q_OBJECT
public:
  explicit LogListModel(QObject *parent = nullptr);

  enum {
    LogIdxRole = Qt::UserRole,
    STimeRole,
    ETimeRole,
    SurgeonIdxRole,
    ToolListRole
  };

  // QAbstractItemModel interface
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QHash<int, QByteArray> roleNames() const;

  Q_INVOKABLE void appendItemToList(int logIdx, const QDateTime &startTime,
                                    const QDateTime &endTime, int surgeonIdx,
                                    int toolIdx, int serialNo, int remainCnt,
                                    int total);

private:
  //  std::unique_ptr<LogList> mList_;
  LogList *mList_;
};

#endif // LOGLISTMODEL_H
