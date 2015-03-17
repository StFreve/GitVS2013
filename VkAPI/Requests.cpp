#include <vk.h>
using namespace vk;
Requests::Requests(const QList<vkAccount*>& userList, const QString& method, const QMap<QString, QVector<QString> >& reqPar, QTime delay, QTime delayUser, SendType type, QWidget* parent)
	:method(method), requestParametrs(reqPar),
	delayUser(delayUser), sendType(type), requestsSend(0),
	QObject(parent), requestsLeft(userList.size()),repeat(false){
	QTime delayIt(delay);
	vkAlarm* alarm;
	foreach(vkAccount* vkUser, userList){
		alarm = users[vkUser] = new vkAlarm(vkUser, delayIt.msecsSinceStartOfDay());
		connect(alarm, SIGNAL(timeout()), SLOT(sendRequest()));
		connect(this, SIGNAL(pause()), alarm, SLOT(pause()));
		connect(this, SIGNAL(start()), alarm, SLOT(start()));
		connect(this, SIGNAL(resume()), alarm, SLOT(resume()));
		delayIt = delayIt.addMSecs(delayUser.msecsSinceStartOfDay());
		alarm->start();
	}
}

Requests::Requests(const QList<vkAccount*>& userList, const QString& method, const QMap<QString, QVector<QString> >& reqPar, QTime repeatTime, QTime delay, QTime delayUser, SendType type, QWidget* parent)
	:method(method), requestParametrs(reqPar), repeatTime(repeatTime),
	delayUser(delayUser), sendType(type), requestsSend(0),
	QObject(parent), requestsLeft(userList.size()),repeat(true){
	QTime delayIt(delay);
	vkAlarm* alarm;
	foreach(vkAccount* vkUser, userList){
		alarm = users[vkUser] = new vkAlarm(vkUser, delayIt.msecsSinceStartOfDay());
		connect(alarm, SIGNAL(timeout()), SLOT(sendRequest()));
		connect(this, SIGNAL(pause()), alarm, SLOT(pause()));
		connect(this, SIGNAL(start()), alarm, SLOT(start()));
		connect(this, SIGNAL(resume()), alarm, SLOT(resume()));
		connect(alarm, SIGNAL(destroyed()), SLOT(removeUser()));
		delayIt = delayIt.addMSecs(delayUser.msecsSinceStartOfDay());
		alarm->start();
	}
}

Requests::Requests(const QList<vkAccount*>& userList, const QString& method, const QMap<QString, QVector<QString> >& reqPar, const RequestTimeSettings& timeSet, SendType type, QWidget* parent)
	:method(method), requestParametrs(reqPar), repeatTime(timeSet.repeatTime()),
	delayUser(timeSet.userDelayTime()), sendType(type), requestsSend(0),
	QObject(parent), requestsLeft(userList.size()), repeat(timeSet.repeat()){
	QTime delayIt(timeSet.delayTime());
	vkAlarm* alarm;
	foreach(vkAccount* vkUser, userList){
		alarm = users[vkUser] = new vkAlarm(vkUser, delayIt.msecsSinceStartOfDay());
		connect(alarm, SIGNAL(timeout()), SLOT(sendRequest()));
		connect(this, SIGNAL(pause()), alarm, SLOT(pause()));
		connect(this, SIGNAL(start()), alarm, SLOT(start()));
		connect(this, SIGNAL(resume()), alarm, SLOT(resume()));
		delayIt = delayIt.addMSecs(delayUser.msecsSinceStartOfDay());
		alarm->start();
	}
}
void Requests::sendRequest(){
	vkAlarm* userToSend = (vkAlarm*)sender();
	userToSend->stop();
	userToSend->getUser()->httpGET(method, sendType == Default ? defaultRequest() : radnomRequest());
	++requestsSend;
	if (repeat){
		userToSend->setInterval(repeatTime.msecsSinceStartOfDay() + delayUser.msecsSinceStartOfDay());
		userToSend->start();
	}
	else{
		if (!(--requestsLeft)){
			emit requestIsEmpty();
		}
	}
}
void Requests::removeUser(){
	removeUser((vkAccount*)sender());
}

void Requests::removeUser(vkAccount* userToDelete){
	if (users.contains(userToDelete)){
		users.remove(userToDelete);
	}
}

QUrlQuery Requests::radnomRequest(){
	QUrlQuery query;
	size_t index;
	for (auto it = requestParametrs.begin(); it != requestParametrs.end(); ++it){
		index = rand() % it->size();
		query.addQueryItem(it.key(), (*it)[index]);
	}
	return query;
}

QUrlQuery Requests::defaultRequest(){
	QUrlQuery query;
	size_t index = requestsSend / users.size();
	for (auto it = requestParametrs.begin(); it != requestParametrs.end(); ++it){
		query.addQueryItem(it.key(), (*it)[index % it->size() ]);
	}
	return query;
}
