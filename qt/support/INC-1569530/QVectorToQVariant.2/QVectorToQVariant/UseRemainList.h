#ifndef USEREMAINLIST_H
#define USEREMAINLIST_H

#include <QObject>

struct UseRemainItem {
  int toolIdx;
  int serialNo;
  int remainCnt;
  int total;
};

Q_DECLARE_METATYPE(UseRemainItem);

class UseRemainList : public QObject {
  Q_OBJECT

  Q_PROPERTY(QVector<UseRemainItem *> *items READ items WRITE setItems NOTIFY
                 itemsChanged)
public:
  explicit UseRemainList(QObject *parent = nullptr);
  ~UseRemainList();

  QVector<UseRemainItem *> *items() const;
  void clearList();

  void setItems(QVector<UseRemainItem *> *items);

public slots:
  Q_INVOKABLE void append(int toolIdx, int serialNo, int remainCnt, int total);

signals:
  void preAddItem();
  void postAddItem();

  void preClearItems();
  void postClearItems();
  void itemsChanged();

private:
  QVector<UseRemainItem *> *items_;
};

#endif // USEREMAINLIST_H
