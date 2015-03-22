#include <vk.h>
using namespace vk;
UserArea::UserArea(QWidget* parent)
	:QWidget(parent), checkedUserCounter(0),
	mainLayout(new QVBoxLayout){
	mainLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	QScrollArea* scl = new QScrollArea;
	QVBoxLayout* vbl = new QVBoxLayout;
	vbl->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	vbl->setMargin(0);

	QPushButton* cA = new QPushButton("Check All");
	QPushButton* ucA = new QPushButton("Uncheck All");
	connect(cA, SIGNAL(clicked()), SLOT(checkAll()));
	connect(ucA, SIGNAL(clicked()), SLOT(uncheckAll()));
	QHBoxLayout* hbl = new QHBoxLayout;
	hbl->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	hbl->addWidget(cA);
	hbl->addWidget(ucA);
	vbl->addLayout(hbl);


	vbl->addWidget(scl);
	
	QWidget* wgt = new QWidget;
	wgt->setLayout(mainLayout);
	scl->setWidget(wgt);
	scl->setWidgetResizable(true);
	scl->setMinimumWidth(320);
	
	scl->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding));
	setLayout(vbl);
}

void UserArea::addUser(vk::vkAccount* newUser){
	vkAccountUI* user = new vkAccountUI(newUser);
	mainLayout->addWidget( user );
	linkUI[newUser] = user;
	connect(user, SIGNAL(stateChanged(int)), SLOT(userStateChanged(int)));
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
		if ((*it)->isChecked())
			checkedUsers.push_back(it.key());
	}
	return checkedUsers;
}

void UserArea::checkAll(){
	if (linkUI.size() > checkedUserCounter)
	foreach(auto it, linkUI)
		it->setChecked(1);
}

void UserArea::uncheckAll(){
	if (checkedUserCounter)
	foreach(auto it, linkUI)
		it->setChecked(0);
}

void UserArea::userStateChanged(int state){
	if (state)
		++checkedUserCounter;
	else
		--checkedUserCounter;
}