#ifndef FILTERFORPAGE_H
#define FILTERFORPAGE_H

#include <QSortFilterProxyModel>

class FilterForPage : public QSortFilterProxyModel {
  Q_OBJECT
public:
  FilterForPage();
  FilterForPage(int itemPerPage);

  void setPage(int p);

protected:
  bool filterAcceptsRow(int source_row,
                        const QModelIndex &source_parent) const override;

private:
  int row_{0};
  int itemPerPage_{6};
};

#endif // FILTERFORPAGE_H
