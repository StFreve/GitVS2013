#include <vk.h>

Requests::Requests(QObject* parent)
	:QObject(parent){

}

Requests::Requests(const QList<vkA*>& users, QObject* parent)
	:vkList(users),
	QObject(parent){

}

void Requests::setAccountList(const QList<vkA*>& newList){
	vkList = newList;
}

void Requests::addAccount(vkA* user){
	vkList.push_back(user);
}

void Requests::deleteAccount(vkA* user){
	vkList.removeOne(user);
}

QList<Requests::vkA*> Requests::AccountList() const{
	return vkList;
}

void Requests::wallPost(){// const QString& owner_id, const QString& message, const QString& attachment){
	QUrlQuery query;
	//query.addQueryItem("owner_id", owner_id);
	query.addQueryItem("message", "Hello, World");
	//if (!attachment.isEmpty()){
	//		query.addQueryItem("attachments", attachment);
	//	}
	sendRequest("wall.post", query);
}

void Requests::sendRequest(const QString& method, const QUrlQuery& query){
	for (auto it : vkList){
		it->syncInformation();//httpGET(method, query);
	}
}