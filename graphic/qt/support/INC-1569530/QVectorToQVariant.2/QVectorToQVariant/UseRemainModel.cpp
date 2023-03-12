#include "UseRemainModel.h"
#include "UseRemainList.h"
#include <QCoreApplication>
#include <qqml.h>

static void registerQmlType() {
  qmlRegisterType<UseRemainModel>("com.remainModel", 1, 0, "UseRemainModel");
  qRegisterMetaType<QJSValue *>("QJSValue*");
}
Q_COREAPP_STARTUP_FUNCTION(registerQmlType);

UseRemainModel::UseRemainModel(QObject *parent) : QAbstractListModel(parent) {
  //    mList_ = std::make_unique<UseRemainList>();
  mList_ = new UseRemainList();
}

UseRemainModel::~UseRemainModel() {
  if (mList_)
    delete mList_;
}

UseRemainList *UseRemainModel::mList() const { return mList_; }

void UseRemainModel::setMList(UseRemainList *mList) {
  beginResetModel();
  if (mList_)
    mList_->disconnect(this);
  mList_ = mList;
  endResetModel();
  emit listChanged();
}

void UseRemainModel::setListFromJs(QJSValue *mList) {
  //    beginResetModel();
  //    if (mList_)
  //        mList_->disconnect(this);
  //    //    mList_ = QVariant::fromValue(*(mList));
  //    mList_ = reinterpret_cast<UseRemainList *>(mList);
  //    endResetModel();
}

void UseRemainModel::setListFromJs(QJSValue mList) {
  beginResetModel();
  if (mList_)
    mList_->disconnect(this);
  //    mList_ = QVariant::fromValue(*(mList));
  //    mList_ = reinterpret_cast<UseRemainList *>(&mList);
  endResetModel();
}

// UseRemainList *UseRemainModel::mList() const
//{
//    return mList_;
//}

// void UseRemainModel::setMList(UseRemainList *mList)
//{
//    beginResetModel();
//    if (mList_)
//        mList_->disconnect(this);
//    mList_ = mList;
//    endResetModel();
//}

void UseRemainModel::appendItemToList(int toolIdx, int serialNo, int remainCnt,
                                      int total) {
  if (mList_) {
    beginInsertRows(QModelIndex(), 0, 0);
    mList_->append(toolIdx, serialNo, remainCnt, total);
    endInsertRows();
  }
}

int UseRemainModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent)
  if (parent.isValid() || !mList_)
    //    if (parent.isValid())
    return 0;
  return mList_->items()->size();
}

QVariant UseRemainModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid() || !mList_) {
    return QVariant();
  }

  const UseRemainItem *item = mList_->items()->at(index.row());
  switch (role) {
  case ToolIdxRole:
    return QVariant(item->toolIdx);
  case SnRole:
    return QVariant(item->serialNo);
  case RemainRole:
    return QVariant(item->remainCnt);
  case TotalRole:
    return QVariant(item->total);
  }
  return QVariant();
}

QHash<int, QByteArray> UseRemainModel::roleNames() const {
  QHash<int, QByteArray> names;
  names[ToolIdxRole] = "toolIdx";
  names[SnRole] = "serialNo";
  names[RemainRole] = "remainCnt";
  names[TotalRole] = "total";
  return names;
}
