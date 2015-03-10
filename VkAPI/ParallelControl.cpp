#include <vk.h>
using namespace vk;
ParallelControl::ParallelControl(QWidget* parent)
	:QMainWindow(parent),
	menuBar(new QMenuBar(this)),
	userArea(new UserArea),
	loginWindow(new vkLogin){
	QMenu* menu = new QMenu("File");
	menu->addAction("Load..");
	menu->addSeparator();
	menu->addAction("Save");
	menu->addAction("Save as..");
	menu->addSeparator();
	menu->addAction("Exit");
	menuBar->addMenu(menu);

	menu = new QMenu("Account");
	menu->addAction("Add..", loginWindow, SLOT(go()));
	menuBar->addMenu(menu);


	menu = new QMenu("Testing");
	menu->addAction("Send Request", this, SLOT(testing()));
	menuBar->addMenu(menu);


	setMenuBar(menuBar);
	setCentralWidget(userArea);
	connect(loginWindow, SIGNAL(newUser(vkAccount*)), userArea, SLOT(addUser(vkAccount*)));


}
ParallelControl::~ParallelControl(){

}
void ParallelControl::testing(){
	vkAccountUI* userUI = (vkAccountUI*)userArea->widget()->layout()->itemAt(0)->widget();
	vkAccount* user = userUI->getAccount();
	QList<vkAccount*> lst;
	lst.push_back(user);
	QMap < QString, QVector<QString> > m;
	m["message"].push_back("Hello World!");
	m["message"].push_back("Hello Friends!");
	Requests* req = new Requests(lst, "wall.post", m, QTime(0, 0, 5), QTime(0, 0), QTime(0, 0, 5));
}