#include "loginwindow.h"

#include <QApplication>
#include <fstream>

rapidjson::Document g_jsonDocumentAccount;
rapidjson::Document g_jsonDocumentTest;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::fstream b_fstrmAccount("account.json", std::ios::in | std::ios::out);
    if (!b_fstrmAccount)
    {
        // 若文件打开失败报错退出
        QMessageBox::information(nullptr,"错误","账户文件打开错误");
        a.exit();
    }
    std::string b_strAccountInfoStr;
    std::string t_strInput;
    while (b_fstrmAccount >> t_strInput)
    {
        // 读入账户文件形成JSON字符串
        b_strAccountInfoStr += t_strInput + ' ';
    }
    if (g_jsonDocumentAccount.Parse(b_strAccountInfoStr.c_str()).HasParseError())
    {
        QMessageBox::information(nullptr, "错误", "解析账户文件错误");
        a.exit();
    }
    LoginWindow w;
    w.show();
    return a.exec();
}