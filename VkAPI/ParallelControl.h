#pragma once
#include <vk.h>
#include <UserArea.h>
using namespace vk;
class vk::ParallelControl :public QMainWindow{
	Q_OBJECT



public:
	ParallelControl(QWidget* = 0);
	~ParallelControl();
signals:
	void pauseAll();
	void resumeAll();
private:
	void addTestingMenu();
	QMenuBar* menuBar;
	UserArea* userArea;
	vkLogin* loginWindow;
	RequestCreator* requestCreator;
	Logger* log;
	QList<vkAccount*> allUsers;
private slots:
	void testRequest();
	void testErrorRequest();
	void testAddUsers();
	void newUser(vkAccount*);
	void testCreateRequest();
};