#include <vk.h>
using namespace vk;
Requests::Requests(const QList<vkAccount*>& userList, const QString& method, const QMap<QString, QVector<QString> >& reqPar, QTime delay, QTime delayUser, SendType type, QWidget* parent)
	:method(method), requestParametrs(reqPar),
	delayUser(delayUser), sendType(type), requestsSend(0),
	QObject(parent), requestsLeft(userList.size()),repeat(false){
	QTime delayIt(delay);
	foreach(vkAccount* vkUser, userList){
		users.push_back(vkUser);
		users.back().setInterval(delayIt.msecsSinceStartOfDay());
		connect(&users.back(), SIGNAL(timeout()), SLOT(sendRequest()));
		delayIt.addMSecs(delayUser.msecsSinceStartOfDay());
		users.back().start();
	}
}

Requests::Requests(const QList<vkAccount*>& userList, const QString& method, const QMap<QString, QVector<QString> >& reqPar, QTime repeatTime, QTime delay, QTime delayUser, SendType type, QWidget* parent)
	:method(method), requestParametrs(reqPar), repeatTime(repeatTime),
	delayUser(delayUser), sendType(type), requestsSend(0),
	QObject(parent), requestsLeft(userList.size()),repeat(true){
	QTime delayIt(delay);
	foreach(vkAccount* vkUser, userList){
		users.push_back(vkUser);
		users.back().setInterval(delayIt.msecsSinceStartOfDay());
		connect(&users.back(), SIGNAL(timeout()), SLOT(sendRequest()));
		delayIt.addMSecs(delayUser.msecsSinceStartOfDay());
		users.back().start();
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

void Requests::removeUser(vkAccount* userToDelete){
	for (auto it = users.begin(); it != users.end(); ++it){
		if (it->getUser() == userToDelete){
			users.erase(it);
			break;
		}
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