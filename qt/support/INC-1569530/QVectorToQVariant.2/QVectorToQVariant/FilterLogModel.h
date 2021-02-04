#ifndef FILTERLOGMODEL_H
#define FILTERLOGMODEL_H

#include <QSortFilterProxyModel>

class FilterLogModel : public QSortFilterProxyModel {
  Q_OBJECT
public:
  FilterLogModel();

  Q_INVOKABLE void setIndex(int idx);

protected:
  bool filterAcceptsRow(int source_row,
                        const QModelIndex &source_parent) const override;

private:
  int index_{0};
};

#endif // FILTERLOGMODEL_H
