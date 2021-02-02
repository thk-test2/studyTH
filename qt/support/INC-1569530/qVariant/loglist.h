#ifndef LOGLIST_H
#define LOGLIST_H

#include <QObject>

class LogList : public QObject
{
    Q_OBJECT
public:
    explicit LogList(QObject *parent = nullptr);
    ~LogList() = default;
    LogList(const LogList&) {}

signals:

private:
    QVector<int> m_vec;
};

Q_DECLARE_METATYPE(LogList);

#endif // LOGLIST_H
