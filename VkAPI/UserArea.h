#pragma once
#include <vk.h>
using namespace vk;
class vk::UserArea :public QScrollArea{
	Q_OBJECT

public:
	UserArea(QWidget* = 0);

public slots:
	void addUser(vkAccount*);
	void deleteUser(vkAccount*);
	void checkAll();
	void uncheckAll();
	QList<vkAccount*> getCheckedUsers() const;
private:
	QMap<vkAccount*, vkAccountUI*> linkUI;
	QVBoxLayout* mainLayout;
};