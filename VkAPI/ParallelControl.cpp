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


	
	addTestingMenu();

	setMenuBar(menuBar);
	setCentralWidget(userArea);
	connect(loginWindow, SIGNAL(newUser(vkAccount*)), userArea, SLOT(addUser(vkAccount*)));
	resize(300, 300);

}
ParallelControl::~ParallelControl(){

}

void ParallelControl::addTestingMenu(){
	QMenu* menu = new QMenu("Testing");
	menu->addAction("Send Request", this, SLOT(testRequest()));
	menu->addAction("Pause All", this, SIGNAL(pauseAll()));
	menu->addAction("Resume All", this, SIGNAL(resumeAll()));
	menu->addAction("Add User", this, SLOT(testAddUsers()));
	menuBar->addMenu(menu);
}

void ParallelControl::testRequest(){
	vkAccountUI* userUI = (vkAccountUI*)userArea->widget()->layout()->itemAt(0)->widget();
	vkAccount* user = userUI->getAccount();
	QList<vkAccount*> lst;
	lst.push_back(user);
	QMap < QString, QVector<QString> > m;
	Requests* req = new Requests(lst, "users.get", m, QTime(0, 0, 5), QTime(0, 0), QTime(0, 0, 5));
	connect(this, SIGNAL(pauseAll()), req, SIGNAL(pause()));
	connect(this, SIGNAL(resumeAll()), req, SIGNAL(resume()));
}

void ParallelControl::testAddUsers(){
	emit loginWindow->newUser(new vkAccount("7233eab01fc001bd4eb033d9d6215c876fa5bf56a3d68eed62553260b0093ce03e91d45ab0ba066e8fb07"));
}