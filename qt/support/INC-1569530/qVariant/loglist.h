#ifndef LOGLIST_H
#define LOGLIST_H

#include <QObject>

struct LogItem {
    QVector<int>* m_vec;
};

class LogList
{
public:
    explicit LogList(QObject *parent = nullptr);
    ~LogList() = default;
    LogList(const LogList&) {}
    QVector<LogItem> *items() const { return items_; }

private:
    QVector<LogItem> *items_;
};

// Q_DECLARE_METATYPE(LogList);

#endif // LOGLIST_H
