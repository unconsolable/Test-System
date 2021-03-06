/*
文件名: singlechoiceproblem.h
版本: 1.0
目的与主要功能: 定义单选题类
创建日期: 2020.9.3
描述: 定义单选题类
作者: unconsolable
修改者: unconsolable
联系方式: chenzhipeng2012@gmail.com
*/

#ifndef SINGLECHOICEPROBLEM_H
#define SINGLECHOICEPROBLEM_H

#include "choiceproblem.h"

class SingleChoiceProblem : public ChoiceProblem
{
public:
    // 构造函数
    SingleChoiceProblem(double = 0, const std::string& = "", const std::vector<std::string>& = {}, char = 'A');
    // 判分函数
    virtual double checkAnswer(const QVariant&) override;
    // 转为JSON节点
    virtual rapidjson::Value toJsonValue(rapidjson::Document& doc) const override;
    // 析构函数
    virtual ~SingleChoiceProblem() override = default;
    // 答案的Getter和Setter
    char getRightAns() const;
    void setRightAns(char rightAns);
private:
    // 只有一个正确
    char m_charRightAns;
};

// 能够使用QVariant
// Q_DECLARE_METATYPE(SingleChoiceProblem);

#endif // SINGLECHOICEPROBLEM_H
