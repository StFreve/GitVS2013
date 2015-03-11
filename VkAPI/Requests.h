#pragma once
#include <vk.h>
using namespace vk;
class vk::Requests :public QObject{
	Q_OBJECT

public:
	enum SendType{
		Default,    // Send the same request to all users, and only then changes it to the next
		Random      // Send a random request to each users
	};
	Requests(const QList<vkAccount*>&, const QString&, const QMap<QString, QVector<QString> >&, QTime = QTime(0,0), QTime = QTime(0,0,30), SendType = Default, QWidget* = 0);
	Requests(const QList<vkAccount*>&, const QString&, const QMap<QString, QVector<QString> >&, QTime, QTime = QTime(0, 0), QTime = QTime(0, 0, 30), SendType = Default, QWidget* = 0);
signals:
	void requestIsEmpty();
	void pause();
	void start();
	void resume();
public slots:
	void removeUser(vkAccount*);
	void removeUser();
	void sendRequest();
private:
	const QString method;
	QMap<QString, QVector<QString> > requestParametrs;
	QMap<vkAccount*, vkAlarm*> users;
	QTime delayUser, repeatTime;
	bool repeat;
	SendType sendType;
	size_t requestsLeft;
	size_t requestsSend;

	QUrlQuery radnomRequest();
	QUrlQuery defaultRequest();
};