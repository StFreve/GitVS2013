#pragma once
#include <vk.h>

class vk::RequestsViewer :public QScrollArea{
	Q_OBJECT

public:
	RequestsViewer(QWidget* = 0);
public slots:
	void addRequest(Requests*);
private slots:
	void deleteRequest();
private:
	QList<Requests*> reqList;
	FlowLayout* mainLayout;
};