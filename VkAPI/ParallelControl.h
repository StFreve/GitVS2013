#pragma once
#include <vk.h>
#include <UserArea.h>
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

private slots:
	void testRequest();
	void testAddUsers();
};