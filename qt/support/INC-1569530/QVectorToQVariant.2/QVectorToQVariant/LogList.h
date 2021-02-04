#ifndef LOGLIST_H
#define LOGLIST_H

#include "UseRemainList.h"
#include <QDateTime>
#include <QObject>

struct LogItem {
  int logIdx;
  QDateTime startTime;
  QDateTime endTime;
  int surgeonIdx;
  QVector<UseRemainItem> *toolList;
  //    std::vector<UseRemainItem> toolVec;
};

Q_DECLARE_METATYPE(LogItem);

class LogList : public QObject {
  Q_OBJECT
public:
  explicit LogList(QObject *parent = nullptr);
  ~LogList();

  QVector<LogItem> *items() const;
  void clearList();
  void setItems(QVector<LogItem> *items);
  int size();

public slots:
  void append(LogItem &logItem);

  void append(int logIdx, const QDateTime &startTime, const QDateTime &endTime,
              int surgeonIdx, QVector<UseRemainItem> *toolList);

  void append(int logIdx, const QDateTime &startTime, const QDateTime &endTime,
              int surgeonIdx, int toolIdx, int serialNo, int remainCnt,
              int total);

private:
  QVector<LogItem> *items_;
};

#endif // LOGLIST_H
