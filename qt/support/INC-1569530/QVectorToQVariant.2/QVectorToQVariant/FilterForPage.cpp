#include "FilterForPage.h"

FilterForPage::FilterForPage() {}

FilterForPage::FilterForPage(int itemPerPage) : itemPerPage_{itemPerPage} {}

void FilterForPage::setPage(int p) {
  row_ = p;
  invalidate();
}

bool FilterForPage::filterAcceptsRow(int source_row,
                                     const QModelIndex &source_parent) const {
  Q_UNUSED(source_parent)
  const auto min = itemPerPage_ * row_;
  const auto max = min + itemPerPage_;
  return source_row >= min && source_row < max;
}
