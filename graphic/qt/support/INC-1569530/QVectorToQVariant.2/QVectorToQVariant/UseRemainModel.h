#ifndef USEREMAINMODEL_H
#define USEREMAINMODEL_H

#include "UseRemainList.h"
#include <QAbstractListModel>
#include <QJSValue>
#include <memory>

// class UseRemainList;

class UseRemainModel : public QAbstractListModel {
  Q_OBJECT
  Q_PROPERTY(UseRemainList *list READ mList WRITE setMList NOTIFY listChanged)
public:
  explicit UseRemainModel(QObject *parent = nullptr);
  ~UseRemainModel();
  enum { ToolIdxRole = Qt::UserRole, SnRole, RemainRole, TotalRole };

  //    UseRemainList *mList() const;
  //    void setMList(UseRemainList *mList);
  Q_INVOKABLE void appendItemToList(int toolIdx, int serialNo, int remainCnt,
                                    int total);

  // QAbstractItemModel interface
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QHash<int, QByteArray> roleNames() const;

  UseRemainList *mList() const;
  void setMList(UseRemainList *mList);
  Q_INVOKABLE void setListFromJs(QJSValue *mList);
  Q_INVOKABLE void setListFromJs(QJSValue mList);

signals:
  void listChanged();

private:
  //    std::unique_ptr<UseRemainList> mList_;
  UseRemainList *mList_;
};

#endif // USEREMAINMODEL_H
