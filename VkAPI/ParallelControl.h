#pragma once
#include <vk.h>
#include <UserArea.h>
class vk::ParallelControl :public QMainWindow{
	Q_OBJECT



public:
	ParallelControl(QWidget* = 0);
	~ParallelControl();
	public slots:
	void testing();
private:
	QMenuBar* menuBar;
	UserArea* userArea;
	vkLogin* loginWindow;
};