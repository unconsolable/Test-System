/*
File Name: judgementproblem.h
Description: Define the Class JudgementProblem
Author: unconsolable
*/
#ifndef JUDGEMENTPROBLEM_H
#define JUDGEMENTPROBLEM_H

#include "problem.h"

class JudgementProblem : public Problem
{
public:
    JudgementProblem(double = 0, const std::string& = "", bool = true);
    virtual double checkAnswer(const QVariant&) override;
    virtual rapidjson::Value toJsonValue(rapidjson::Document& doc) const override;
    virtual ~JudgementProblem() override = default;
    bool getRightAns() const;
    void setRightAns(bool rightAns);

private:
    bool m_boolRightAns;
};

// 能够使用QVariant
// Q_DECLARE_METATYPE(JudgementProblem);

#endif // JUDGEMENTPROBLEM_H
