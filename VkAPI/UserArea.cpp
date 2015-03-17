#include <vk.h>
using namespace vk;
UserArea::UserArea(QWidget* parent)
	:QScrollArea(parent),
	mainLayout(new QVBoxLayout){
	mainLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	QWidget* wgt = new QWidget;
	wgt->setLayout(mainLayout);
	setWidget(wgt);
	setWidgetResizable(true);
	setMinimumWidth(300);
	setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
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

QList<vkAccount*> UserArea::getCheckedUsers() const{
	QList<vkAccount*> checkedUsers;
	for(auto it = linkUI.begin(); it!=linkUI.end(); ++it){
		if ((*it)->isCheked())
			checkedUsers.push_back(it.key());
	}
	return checkedUsers;
}

void UserArea::checkAll(){
	foreach(auto it, linkUI)
		it->setChecked(1);
}

void UserArea::uncheckAll(){
	foreach(auto it, linkUI)
		it->setChecked(0);
}