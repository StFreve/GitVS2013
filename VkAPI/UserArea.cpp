#include <vk.h>
using namespace vk;
UserArea::UserArea(QWidget* parent)
	:QScrollArea(parent),
	mainLayout(new QVBoxLayout){
	QWidget* wgt = new QWidget;
	wgt->setLayout(mainLayout);
	setWidget(wgt);
	setWidgetResizable(true);
	setMinimumWidth(100);
}

void UserArea::addUser(vk::vkAccount* newUser){
	mainLayout->addWidget(linkUI[newUser] = new vkAccountUI(newUser));
	qDebug() << "New User Added";
}

void UserArea::deleteUser(vk::vkAccount* userToDelete){
	mainLayout->removeWidget(linkUI[userToDelete]);
	linkUI.remove(userToDelete);
	qDebug() << "User Deleted";
}
