/*
文件名: teacherproblemwidget.h
版本: 1.0
目的与主要功能: 定义显示题目和辅助出题的Widget
创建日期: 2020.9.8
描述: 定义显示题目和辅助出题的Widget
作者: unconsolable
修改者: unconsolable
联系方式: chenzhipeng2012@gmail.com
*/

#ifndef TEACHERPROBLEMWIDGET_H
#define TEACHERPROBLEMWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QButtonGroup>

// 释放非空指针
#define CheckDeleteSetNull(Ptr) \
    do                          \
    {                           \
        if ((Ptr))              \
        {                       \
            delete (Ptr);       \
            (Ptr) = nullptr;    \
        }                       \
    }while(0)

class TeacherProblemWidget : public QWidget
{
    Q_OBJECT
    friend class TeacherMainForm;
public:
    TeacherProblemWidget(QWidget *parent = nullptr);
    ~TeacherProblemWidget();
private:
    // 布局
    QGridLayout *m_gridLayoutProblem = nullptr;
    // 描述性文字
    QLabel *m_labelProblemTypeHint = nullptr;
    QLabel *m_labelProblemMarkHint = nullptr;
    QLabel *m_labelProblemDescHint = nullptr;
    QLabel *m_labelProblemAnswerHint = nullptr;
    // 题目类型下拉框
    QComboBox *m_comboBoxProblemType = nullptr;
    // 题目分值输入
    QLineEdit *m_lineEditProblemMark = nullptr;
    // 题干输入
    QPlainTextEdit *m_plainTextEditProblemDesc = nullptr;
    // 以下部分可能部分题会用不到
    // 因此析构时检查是否为空
    // 并避免悬垂指针
    
    // 以下部分仅选择题会用到
    // 选项的描述
    QLineEdit *m_lineEditProblemChoiceA = nullptr;
    QLineEdit *m_lineEditProblemChoiceB = nullptr;
    QLineEdit *m_lineEditProblemChoiceC = nullptr;
    QLineEdit *m_lineEditProblemChoiceD = nullptr;
    // 单选中选择正确选项
    QRadioButton *m_radioProblemRightChoiceB = nullptr;
    QRadioButton *m_radioProblemRightChoiceA = nullptr;
    QRadioButton *m_radioProblemRightChoiceC = nullptr;
    QRadioButton *m_radioProblemRightChoiceD = nullptr;
    // 选项设为组,实现组内四选一
    QButtonGroup *m_btnGroupSingleChoice = nullptr;
    // 多选中选择正确选项
    QCheckBox *m_chkBoxProblemRightChoiceA = nullptr;
    QCheckBox *m_chkBoxProblemRightChoiceB = nullptr;
    QCheckBox *m_chkBoxProblemRightChoiceC = nullptr;
    QCheckBox *m_chkBoxProblemRightChoiceD = nullptr;
    // 以下部分仅判断题会用到
    QCheckBox *m_chkBoxIsRight = nullptr;
    // 以下部分仅简答题会用到
    QPlainTextEdit *m_plainTextKeyWordList = nullptr;
    // 需要flag标志位,若为true需要将Model删除再重新增加
    bool m_boolProblemTypeChanged = false;
    // 之前选择的选项
    int m_intLastProblemTypeIndex = 0;
private slots:
    // 题目类型改变时,释放原有控件,添加新的控件
    void onProblemTypeChanged(int newtype);
};

#endif // PROBLEMWIDGET_H
