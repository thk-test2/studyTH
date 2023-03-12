#include "UseRemainList.h"
#include <QCoreApplication>
#include <QDebug>
#include <qqml.h>

static void registerQmlType() {
  qmlRegisterType<UseRemainList>("com.remainList", 1, 0, "UseRemainList");
  qRegisterMetaType<UseRemainItem>("UseRemainItem");
  qRegisterMetaType<UseRemainItem>("UseRemainItem&");
  qRegisterMetaType<UseRemainItem *>("UseRemainItem*");
  qRegisterMetaType<QVector<UseRemainItem *>>("QVector<UseRemainItem *>");
}
Q_COREAPP_STARTUP_FUNCTION(registerQmlType);

UseRemainList::UseRemainList(QObject *parent) : QObject(parent) {

  items_ = new QVector<UseRemainItem *>();
}

UseRemainList::~UseRemainList() {
  if (items_) {
    clearList();
    delete items_;
  }
}

QVector<UseRemainItem *> *UseRemainList::items() const { return items_; }

void UseRemainList::clearList() {
  for (auto logItem : *items_) {
    delete logItem;
  }
  items_->clear();
}

void UseRemainList::append(int toolIdx, int serialNo, int remainCnt,
                           int total) {
  qDebug() << "adding item in class";
  UseRemainItem *item = new UseRemainItem{toolIdx, serialNo, remainCnt, total};
  items_->push_front(item);
}

void UseRemainList::setItems(QVector<UseRemainItem *> *items) {
  items_ = items;
  emit itemsChanged();
}
