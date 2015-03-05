#include <vk.h>
vk::vkAccount::vkAccount(QWidget* parent)
	:QWidget(parent),
	fname("uknown"), lname("uknown"),
	token(""), id("uknown"),
	netManager(new QNetworkAccessManager(this)){
	connect(netManager, SIGNAL(finished(QNetworkReply*)), SLOT(finishRequest(QNetworkReply*)));
}

vk::vkAccount::vkAccount(const QString& token, QWidget* parent)
	:QWidget(parent),
	fname("uknown"), lname("uknown"),
	token(token),	id("uknown"),
	netManager(new QNetworkAccessManager(this)){
	connect(netManager, SIGNAL(finished(QNetworkReply*)), SLOT(finishRequest(QNetworkReply*)));

	syncInformation();
}

vk::vkAccount::vkAccount(const QString& login, const QString& password, QWidget* parent)
	:vkAccount(LogIn(login,password),parent){

}

vk::vkAccount::~vkAccount(){

}

QString vk::vkAccount::getToken() const {
	return token;
}
QString vk::vkAccount::getFirstName() const {
	return fname;
}
QString vk::vkAccount::getLastName() const {
	return lname;
}
QString vk::vkAccount::getUserID() const {
	return id;
}

void vk::vkAccount::updateToken(const QString& new_token){
	token = new_token;
	syncInformation();
}

QNetworkReply* vk::vkAccount::httpGET(const QString& method, QUrlQuery urlq){
	urlq.addQueryItem("access_token", token);
	QUrl url = API_URL.toString() + method;
	url.setQuery(urlq);
	return httpGET(QNetworkRequest(url));
}

QNetworkReply* vk::vkAccount::httpGET(QNetworkRequest request){
	QNetworkReply* netReply = netManager->get(request);
	return netReply;
}

QNetworkReply* vk::vkAccount::httpPOST(const QString& method, QUrlQuery urlq){
	urlq.addQueryItem("access_token", token);
	QUrl url = API_URL.toString() + method;
	url.setQuery(urlq);
	return httpPOST(QNetworkRequest(url));
}
QNetworkReply* vk::vkAccount::httpPOST(QNetworkRequest request){
	return NULL;
}


void vk::vkAccount::syncInformation(){
	connect(this, SIGNAL(requestFinished(const QByteArray&)), SLOT(updateInformation(const QByteArray&)));
	connect(this, SIGNAL(requestError()), SIGNAL(syncError()));
	QUrlQuery query;
	httpGET("users.get", query);
}

void vk::vkAccount::updateInformation(const QByteArray& info){
	disconnect(this, SIGNAL(requestFinished(const QByteArray&)), this, SLOT(updateInformation(const QByteArray&)));
	disconnect(this, SIGNAL(requestError()), this, SIGNAL(syncError()));
	qDebug() << info;
}

void vk::vkAccount::finishRequest(QNetworkReply* reply){
	if (reply->error() != QNetworkReply::NetworkError::NoError){
		emit requestError();
	}
	else{
		emit requestFinished(reply->readAll());
	}
	reply->deleteLater();
}
QString vk::vkAccount::LogIn(const QString& login, const QString& pass){

	return "nothing";
}