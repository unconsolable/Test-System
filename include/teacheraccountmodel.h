/*
文件名: studentaccountmodel.h
版本: 1.0
目的与主要功能: 继承QAbstractModel定义教师账号模型
创建日期: 2020.9.13
描述: 继承QAbstractModel定义教师账号模型
作者: unconsolable
修改者: unconsolable
联系方式: chenzhipeng2012@gmail.com
*/

#ifndef TEACHERACCOUNTMODEL_H
#define TEACHERACCOUNTMODEL_H

#include <QAbstractItemModel>
#include "rapidjson/document.h"
#include <string>
#include <map>
// 内部直接使用jsonDocument的指针,减少资源拷贝
// 这个指针对应内容非new创建 不要delete
class TeacherAccountModel : public QAbstractListModel
{
    Q_OBJECT
public:
    // 拷贝控制
    TeacherAccountModel( rapidjson::Document *jsonDocumentAcc, QObject *parent = nullptr);
    TeacherAccountModel(const TeacherAccountModel&) = delete;
    TeacherAccountModel& operator=(const TeacherAccountModel&) = delete;
    ~TeacherAccountModel() = default;
    // 返回行数,重载QAbstraceListModel
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    // 返回用于显示的数据,重载QAbstractListModel
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    // 实现添加和删除数据时不重写insertRows和removeRows
    // rapidjson中只有增加和删除的API,删除时需要key
    // rapidjson中增加只能append,因此修改后位置可能会变
    void addAccount(const std::string& account, const std::string& passwd);
    void rmAccount(int pos);
    // 获得<账号,密码>对
    std::pair<std::string, std::string> getAccountAndPasswd(int pos);
private:
    rapidjson::Document *m_pJsonDocumentAccount;
};

#endif // TEACHERACCOUNTMODEL_H
