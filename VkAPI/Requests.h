#pragma once
#include <vk.h>

class Requests :public QObject{
	Q_OBJECT

		typedef vk::vkAccount vkA;
	QTimer timer;
	QList<vkA*> vkList;
public:
	Requests(QObject* = 0);
	Requests(const QList<vkA*>&, QObject* = 0);

	void setAccountList(const QList<vkA*>&);
	void addAccount(vkA*);
	void deleteAccount(vkA*);
	QList<vkA*> AccountList() const;

public slots:
	void wallPost();//const QString&, const QString&, const QString&); // owner_id, message, attachment;

	void sendRequest(const QString&, const QUrlQuery&);
};