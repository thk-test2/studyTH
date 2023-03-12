#include "FilterLogModel.h"

FilterLogModel::FilterLogModel() {}

void FilterLogModel::setIndex(int idx) {
  index_ = idx;
  invalidate();
}

bool FilterLogModel::filterAcceptsRow(int source_row,
                                      const QModelIndex &source_parent) const {
  Q_UNUSED(source_parent)
  return source_row == index_;
}
