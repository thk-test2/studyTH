#ifndef LOGPAGEMODEL_H
#define LOGPAGEMODEL_H

#include "FilterForPage.h"
#include "FilterLogModel.h"
#include "LogListModel.h"

class LogPageModel : public QObject {
  Q_OBJECT
  Q_PROPERTY(LogListModel *itemsModel READ itemsModel WRITE setItemsModel NOTIFY
                 itemsModelChanged)
  Q_PROPERTY(int currentPage READ currentPage WRITE setCurrentPage NOTIFY
                 currentPageChanged)
  Q_PROPERTY(int pageCount READ pageCount NOTIFY pageCountChanged)
  Q_PROPERTY(QSortFilterProxyModel *itemsForPage READ itemsForPage NOTIFY
                 itemsForPageChanged)
  Q_PROPERTY(int filterLogIdx READ filterLogIdx WRITE setFilterLogIdx NOTIFY
                 filterLogIdxChanged)
  Q_PROPERTY(int logItemCnt READ logItemCnt NOTIFY logItemCntChanged)
  Q_PROPERTY(QSortFilterProxyModel *oneItemPerPage READ oneItemPerPage NOTIFY
                 oneItemPerPageChanged)
public:
  explicit LogPageModel(QObject *parent = nullptr);

  int pageCount() const;

  int currentPage() const;
  void setCurrentPage(int currentPage);

  QSortFilterProxyModel *itemsForPage();

  Q_INVOKABLE void appendItemToList(int logIdx, const QDateTime &startTime,
                                    const QDateTime &endTime, int surgeonIdx,
                                    int toolIdx, int serialNo, int remainCnt,
                                    int total);

  QSortFilterProxyModel *oneItemPerPage();
  void setFilterLogIdx(int idx);

  int filterLogIdx() const;
  int logItemCnt() const;

  LogListModel *itemsModel() const;
  void setItemsModel(LogListModel *itemsModel);

signals:
  void currentPageChanged();
  void itemsForPageChanged();
  void pageCountChanged();
  void itemsModelChanged();
  void oneItemPerPageChanged();
  void filterLogIdxChanged();
  void logItemCntChanged();

private:
  //    std::unique_ptr<LogListModel> itemsModel_;
  LogListModel *itemsModel_{nullptr};
  int currentPage_{0};
  int itemPerPage_{6};
  int filterLogIdx_{0};
  FilterForPage itemsForPage_{itemPerPage_};
  FilterLogModel oneItemPerPage_;

  void createModelForPage();
};

#endif // LOGPAGEMODEL_H
