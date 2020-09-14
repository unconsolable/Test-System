/*
File Name: loginwindow.h
Description: Define the class for the login form
Author: unconsolable
*/

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "teachermainform.h"

#include "studentmainform.h"
#include "rootmainform.h"

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    // 点击登录按钮时,检查账号密码
    void on_loginBtn_clicked();

private:
    Ui::LoginWindow *ui;
    // 教师界面的指针,便于后续显示教师界面
    TeacherMainForm *m_pTeacherFormTea = nullptr;
    // 学生界面的指针,便于后续显示学生界面
    StudentMainForm *m_pStudentFormStu = nullptr;
    // 管理员界面的指针,便于后续显示管理员界面
    RootMainForm *m_pRootFormRoot = nullptr;
};
#endif // LOGINWINDOW_H
