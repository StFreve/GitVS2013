#include <vk.h>
using namespace vk;
ParallelControl::ParallelControl(QWidget* parent)
	:QMainWindow(parent),
	menuBar(new QMenuBar(this)),
	userArea(new UserArea),
	loginWindow(new vkLogin),
	requestCreator(new RequestCreator){
	QWidget* centralWidget = new QWidget;
	
	QMenu* menu = new QMenu("File");
	menu->addAction("Load..");
	menu->addSeparator();
	menu->addAction("Save");
	menu->addAction("Save as..");
	menu->addSeparator();
	menu->addAction("Exit", qApp, SLOT(quit()));
	menuBar->addMenu(menu);

	menu = new QMenu("Account");
	menu->addAction("Add..", loginWindow, SLOT(go()));
	menuBar->addMenu(menu);
	
	
	addTestingMenu();


	log = new Logger;
	connect(loginWindow, SIGNAL(newUser(vkAccount*)), log, SLOT(userNewUser(vkAccount*)));

	QHBoxLayout* lb = new QHBoxLayout;
	lb->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	lb->addWidget(userArea);
	
	lb->addWidget(log);
	centralWidget->setLayout(lb);

	setMenuBar(menuBar);
	setCentralWidget(centralWidget);
	connect(loginWindow, SIGNAL(newUser(vkAccount*)), userArea, SLOT(addUser(vkAccount*)));
	resize(600, 300);
}
ParallelControl::~ParallelControl(){

}

void ParallelControl::addTestingMenu(){
	QMenu* menu = new QMenu("Testing");
	menu->addAction("Create Request", this, SLOT(testCreateRequest()));
	menu->addAction("Send Request", this, SLOT(testRequest()));
	menu->addAction("Send Error Request", this, SLOT(testErrorRequest()));
	menu->addAction("Pause All", this, SIGNAL(pauseAll()));
	menu->addAction("Resume All", this, SIGNAL(resumeAll()));
	menu->addAction("Add User", this, SLOT(testAddUsers()));
	menuBar->addMenu(menu);

	connect(loginWindow, SIGNAL(newUser(vkAccount*)), SLOT(newUser(vkAccount*)));

}

void ParallelControl::testRequest(){
	//vkAccountUI* userUI = (vkAccountUI*)userArea->widget()->layout()->itemAt(0)->widget();
	//vkAccount* user = userUI->getAccount();
	//QList<vkAccount*> lst;
	//lst.push_back(user);
	// 203069876
	QMap < QString, QVector<QString> > m;
	//m["user_id"] << "203069876";
	//m["message"] << "Hello, I'm StFreve's bot." << "I will send you some random messages." << "The messages will come in every 2 minutes" << "These messages will come in absolutely random order." << "Try to locate them in correct order." << ":-)";
	Requests* req = new Requests(allUsers, "users.get", m, QTime(0, 0, 10), QTime(0, 0), QTime(0, 0, 1), vk::Requests::SendType::Random);
	connect(this, SIGNAL(pauseAll()), req, SIGNAL(pause()));
	connect(this, SIGNAL(resumeAll()), req, SIGNAL(resume()));
}

void ParallelControl::testErrorRequest(){
	//vkAccountUI* userUI = (vkAccountUI*)userArea->widget()->layout()->itemAt(0)->widget();
	//vkAccount* user = userUI->getAccount();
	QList<vkAccount*> lst = allUsers;
	lst.pop_back();
	lst.pop_back();
	//lst.push_back(user);
	// 203069876
	QMap < QString, QVector<QString> > m;
	//m["user_id"] << "203069876";
	//m["message"] << "Hello, I'm StFreve's bot." << "I will send you some random messages." << "The messages will come in every 2 minutes" << "These messages will come in absolutely random order." << "Try to locate them in correct order." << ":-)";
	Requests* req = new Requests(allUsers, "user.get", m, QTime(0, 0, 10), QTime(0, 0), QTime(0, 0, 1), vk::Requests::SendType::Random);
	connect(this, SIGNAL(pauseAll()), req, SIGNAL(pause()));
	connect(this, SIGNAL(resumeAll()), req, SIGNAL(resume()));
}

void ParallelControl::testAddUsers(){
	emit loginWindow->newUser(new vkAccount("20fe4c0ca541c9419f5938932ccc494793d143852caff1d1b14d0ac486f59c6242e8070970eed409e3cee"));
	emit loginWindow->newUser(new vkAccount("624d89e83aef0c6280a6189cdfffa7892afc4ce6475675eade18f194cab700733bc2779c778c204de1976"));
	//emit loginWindow->newUser(new vkAccount("ca18ed93806a88d9fe377ab1874b275d17fe1c3474d99ab574e650328f002b1acb092cf37b792cb5751a9"));
	//emit loginWindow->newUser(new vkAccount("7df1cecb785305eab711c2b0a19b5d77438bf53b6df580953be1d0e099bbbf00a6a04326aab6be6b890d7"));
	//emit loginWindow->newUser(new vkAccount("4c1d904aab823210778c1316cb627820461048c538944599f64a8e8fed9f92ca6bf2f1ff5494fd79645a8"));
	//emit loginWindow->newUser(new vkAccount("60c3ecf78b653d99b52276982826ebc08fd6e3dbfb927133c3495a107d8b8a314691b9dedfb3e0b67a702"));

}

void ParallelControl::newUser(vkAccount* newU){
	allUsers << newU;
}

void ParallelControl::testCreateRequest(){
	QVBoxLayout* la = new QVBoxLayout;
	QList< QPair<QString, QLineEdit*> > lines;
	lines.push_back(qMakePair(QString("message"), new QLineEdit));
	la->addWidget(lines.back().second);
	requestCreator->newRequest(la, "wall.post");
	requestCreator->setTextLines(lines);
	requestCreator->setUsers(userArea->getCheckedUsers());
	requestCreator->show();

}