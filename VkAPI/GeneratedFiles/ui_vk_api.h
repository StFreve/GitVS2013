/********************************************************************************
** Form generated from reading UI file 'vk_api.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VK_API_H
#define UI_VK_API_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vk_apiClass
{
public:

    void setupUi(QWidget *vk_apiClass)
    {
        if (vk_apiClass->objectName().isEmpty())
            vk_apiClass->setObjectName(QStringLiteral("vk_apiClass"));
        vk_apiClass->resize(600, 400);

        retranslateUi(vk_apiClass);

        QMetaObject::connectSlotsByName(vk_apiClass);
    } // setupUi

    void retranslateUi(QWidget *vk_apiClass)
    {
        vk_apiClass->setWindowTitle(QApplication::translate("vk_apiClass", "vk_api", 0));
    } // retranslateUi

};

namespace Ui {
    class vk_apiClass: public Ui_vk_apiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VK_API_H
