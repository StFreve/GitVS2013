#pragma once
#include <vk.h>
using namespace vk;
class vk::UserArea :public QWidget{
	Q_OBJECT

public:
	UserArea(QWidget* = 0);

public slots:
	void addUser(vkAccount*);
	void deleteUser(vkAccount*);
	QList<vkAccount*> getCheckedUsers() const;
private slots:
	void checkAll();
	void uncheckAll();
	void userStateChanged(int);
private:
	QMap<vkAccount*, vkAccountUI*> linkUI;
	QVBoxLayout* mainLayout;
	size_t checkedUserCounter;
};