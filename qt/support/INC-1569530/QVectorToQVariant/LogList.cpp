#include "LogList.h"
#include <QCoreApplication>
#include <qqml.h>

//static void registerQmlType() {
//  qmlRegisterType<LogList>("com.logList", 1, 0, "LogList");
//}
//Q_COREAPP_STARTUP_FUNCTION(registerQmlType);

LogList::LogList(QObject *parent) {
  //    qRegisterMetaType<std::vector<UseRemainItem>>("std::vector<UseRemainItem>");
}

LogList::~LogList() {
  if (items_) {
    clearList();
    delete items_;
  }
}

QVector<LogItem> *LogList::items() const { return items_; }

void LogList::clearList() {
  for (auto logItem : *items_) {
    if (logItem.toolList) {
      delete logItem.toolList;
    }
  }
}

void LogList::setItems(QVector<LogItem> *items) { items_ = items; }

void LogList::append(LogItem &logItem) { items_->push_front(logItem); }

void LogList::append(int logIdx, const QDateTime &startTime,
                     const QDateTime &endTime, int surgeonIdx,
                     QVector<UseRemainItem> *toolList) {
  LogItem item{logIdx, startTime, endTime, surgeonIdx, toolList};
  items_->push_front(item);
}

void LogList::append(int logIdx, const QDateTime &startTime,
                     const QDateTime &endTime, int surgeonIdx, int toolIdx,
                     int serialNo, int remainCnt, int total) {
  QVector<UseRemainItem> *toolList = new QVector<UseRemainItem>();
  UseRemainItem useRemainItem{toolIdx, serialNo, remainCnt, total};
  toolList->append(useRemainItem);
  append(logIdx, startTime, endTime, surgeonIdx, toolList);
}

// void LogList::appendToolItem(UseRemainItem &item) {}

// void LogList::appendToolItem(int toolIdx, int serialNo, int remainCnt, int
// total) {}
