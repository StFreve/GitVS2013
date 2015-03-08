#pragma once
#include <vk.h>
#include "ui_vk_api.h"

class vk_api : public QWidget
{
	Q_OBJECT

	vk::vkAccount* user;
	QLineEdit* Request;
	QTextEdit* Result;
	QPushButton* sendRequest;
public:
	vk_api(QWidget *parent = 0);
	~vk_api();
public slots:
	void send();
	void showRes(const QByteArray&);
	void Error();
private:
	Ui::vk_apiClass ui;
};
