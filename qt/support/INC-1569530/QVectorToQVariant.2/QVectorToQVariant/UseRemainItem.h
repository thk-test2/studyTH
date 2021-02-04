#ifndef USEREMAINITEM_H
#define USEREMAINITEM_H

#include <QObject>

struct UseRemainItem {
  int toolIdx;
  int serialNo;
  int remainCnt;
  int total;
};
Q_DECLARE_METATYPE(UseRemainItem);

#endif // USEREMAINITEM_H
