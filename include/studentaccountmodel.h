/*
文件名: studentaccountmodel.h
版本: 1.0
目的与主要功能: 继承QAbstractModel定义学生账号模型
创建日期: 2020.9.13
描述: 继承QAbstractModel定义学生账号模型
作者: unconsolable
修改者: unconsolable
联系方式: chenzhipeng2012@gmail.com
*/

#ifndef STUDENTACCOUNTMODEL_H
#define STUDENTACCOUNTMODEL_H

#include <QAbstractItemModel>
#include "rapidjson/document.h"
#include <string>
#include <map>
// 我们把账号文件解析的jsonDocument设置为全局变量
// 因此数据直接用这个全局变量的指针,减少资源拷贝
// 本类实现即为在数据基础上加wrapper,使其符合qt中Model-View的要求
// 这个指针非new创建 不要delete
class StudentAccountModel : public QAbstractListModel
{
    Q_OBJECT
public:
    // 拷贝控制
    StudentAccountModel(rapidjson::Document *jsonDocumentAcc, QObject *parent = nullptr);
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
    // 返回<账号，密码>对
    std::pair<std::string, std::string> getAccountAndPasswd(int pos);
private:
    // 账号数据模型
    rapidjson::Document *m_pJsonDocumentAccount;
};

#endif // STUDENTACCOUNTMODEL_H
