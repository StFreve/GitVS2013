#ifndef VK_API_H
#define VK_API_H

#include <QtWidgets/QWidget>
#include "ui_vk_api.h"

class vk_api : public QWidget
{
	Q_OBJECT

public:
	vk_api(QWidget *parent = 0);
	~vk_api();

private:
	Ui::vk_apiClass ui;
};

#endif // VK_API_H
