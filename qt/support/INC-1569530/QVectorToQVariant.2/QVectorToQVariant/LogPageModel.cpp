#include "LogPageModel.h"
#include <QCoreApplication>
#include <QDateTime>
#include <qqml.h>

static void registerQmlType() {
  qmlRegisterType<LogPageModel>("com.logPageModel", 1, 0, "LogPageModel");
}
Q_COREAPP_STARTUP_FUNCTION(registerQmlType);

LogPageModel::LogPageModel(QObject *parent) : QObject(parent) {
  connect(this, &LogPageModel::currentPageChanged, this,
          &LogPageModel::createModelForPage);

  //    itemsModel_ = std::make_unique<LogListModel>();
  //    itemsForPage_.setSourceModel(itemsModel_.get());
  itemsModel_ = new LogListModel();
  itemsForPage_.setSourceModel(itemsModel_);
  oneItemPerPage_.setSourceModel(itemsModel_);
  createModelForPage();
  QDateTime time;
  appendItemToList(1, time.currentDateTime(), time.currentDateTime(), 1, 1, 1,
                   1, 1);
  appendItemToList(1, time.currentDateTime(), time.currentDateTime(), 1, 1, 1,
                   1, 1);
}

int LogPageModel::pageCount() const {
  const auto v = itemsModel_->rowCount() / itemPerPage_;
  const auto perfect = (itemsModel_->rowCount() % itemPerPage_) == 0;
  return perfect ? v : v + 1;
}

int LogPageModel::currentPage() const { return currentPage_; }

void LogPageModel::setCurrentPage(int currentPage) {
  currentPage_ = currentPage;
  currentPageChanged();
}

QSortFilterProxyModel *LogPageModel::itemsForPage() { return &itemsForPage_; }

void LogPageModel::appendItemToList(int logIdx, const QDateTime &startTime,
                                    const QDateTime &endTime, int surgeonIdx,
                                    int toolIdx, int serialNo, int remainCnt,
                                    int total) {
  if (itemsModel_) {
    auto oldCount = pageCount();
    //        beginInsertRows(QModelIndex(), 0, 0);
    itemsModel_->appendItemToList(logIdx, startTime, endTime, surgeonIdx,
                                  toolIdx, serialNo, remainCnt, total);
    //        endInsertRows();
    if (oldCount != pageCount())
      emit pageCountChanged();
    createModelForPage();
  }
}

QSortFilterProxyModel *LogPageModel::oneItemPerPage() {
  return &oneItemPerPage_;
}

void LogPageModel::setFilterLogIdx(int idx) {
  oneItemPerPage_.setIndex(idx);
  emit oneItemPerPageChanged();
}

int LogPageModel::filterLogIdx() const { return filterLogIdx_; }

int LogPageModel::logItemCnt() const { return itemsModel_->rowCount(); }

LogListModel *LogPageModel::itemsModel() const { return itemsModel_; }

void LogPageModel::setItemsModel(LogListModel *itemsModel) {
  itemsModel_ = itemsModel;
  emit itemsModelChanged();
}

void LogPageModel::createModelForPage() {
  itemsForPage_.setPage(currentPage_);
  emit itemsForPageChanged();
}
