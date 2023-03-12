#include "LogListModel.h"
#include "LogList.h"
#include <QCoreApplication>
#include <qqml.h>

static void registerQmlType() {
  qmlRegisterType<LogListModel>("com.logModel", 1, 0, "LogListModel");
}
Q_COREAPP_STARTUP_FUNCTION(registerQmlType);

LogListModel::LogListModel(QObject *parent) : QAbstractListModel(parent) {
  //  mList_ = std::make_unique<LogList>();
  mList_ = new LogList();
}

int LogListModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent)
  if (parent.isValid() || !mList_)
    //    if (parent.isValid())
    return 0;
  //    return mList_->items()->size();
  return mList_->size();
}

QVariant LogListModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid() || !mList_) {
    return QVariant();
  }

  const LogItem item = mList_->items()->at(index.row());
  switch (role) {
  case LogIdxRole:
    return QVariant(item.logIdx);
  case STimeRole:
    return QVariant(item.startTime);
  case ETimeRole:
    return QVariant(item.endTime);
  case SurgeonIdxRole:
    return QVariant(item.surgeonIdx);
  case ToolListRole:
    return QVariant::fromValue(*(item.toolList));
  }
  return QVariant();
}

QHash<int, QByteArray> LogListModel::roleNames() const {
  QHash<int, QByteArray> names;
  names[LogIdxRole] = "logIdx";
  names[STimeRole] = "startTime";
  names[ETimeRole] = "endTime";
  names[SurgeonIdxRole] = "surgeonIdx";
  names[ToolListRole] = "toolList";
  return names;
}

void LogListModel::appendItemToList(int logIdx, const QDateTime &startTime,
                                    const QDateTime &endTime, int surgeonIdx,
                                    int toolIdx, int serialNo, int remainCnt,
                                    int total) {
  if (mList_) {
    beginInsertRows(QModelIndex(), 0, 0);
    mList_->append(logIdx, startTime, endTime, surgeonIdx, toolIdx, serialNo,
                   remainCnt, total);
    endInsertRows();
  }
}
