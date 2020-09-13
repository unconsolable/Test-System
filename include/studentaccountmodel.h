#ifndef STUDENTACCOUNTMODEL_H
#define STUDENTACCOUNTMODEL_H

#include <QAbstractItemModel>
#include "rapidjson/document.h"
#include <string>
#include <map>
// 内部直接使用jsonDocument的指针,减少资源拷贝
// 这个指针对应内容非new创建 不要delete
class StudentAccountModel : public QAbstractListModel
{
    Q_OBJECT
public:
    // 拷贝控制
    StudentAccountModel( rapidjson::Document *jsonDocumentAcc, QObject *parent = nullptr);
    StudentAccountModel(const StudentAccountModel&) = delete;
    StudentAccountModel& operator=(const StudentAccountModel&) = delete;
    ~StudentAccountModel() = default;
    // 返回行数,重载QAbstraceListModel
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    // 返回用于显示的数据,重载QAbstractListModel
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    // 实现添加和删除数据时不重写insertRows和removeRows
    // rapidjson中只有增加和删除的API,删除时需要key
    void addAccount(const std::string& account, const std::string& passwd);
    void rmAccount(int pos);
    // 获得账户密码
    std::pair<std::string, std::string> getAccountAndPasswd(int pos);
private:
    rapidjson::Document *m_jsonDocumentAccount;
};

#endif // STUDENTACCOUNTMODEL_H
