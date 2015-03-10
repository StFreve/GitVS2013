#include <vk.h>
vk::vkAccount::vkAccount(QWidget* parent)
	:QWidget(parent),
	fname("unknown"), lname("unknown"),
	token(""), id("unknown"),
	netManager(new QNetworkAccessManager(this)), lastNetReply(NULL), RequestStatus(NoErrors),
	ErrorMsg("No Errors"){
	connect(netManager, SIGNAL(finished(QNetworkReply*)), SLOT(finishRequest(QNetworkReply*)));
}

vk::vkAccount::vkAccount(const QString& token, QWidget* parent)
	:QWidget(parent),
	fname("unknown"), lname("unknown"),
	token(token),	id("unknown"),
	netManager(new QNetworkAccessManager(this)), lastNetReply(NULL), RequestStatus(NoErrors),
	ErrorMsg("No Errors"){
	connect(netManager, SIGNAL(finished(QNetworkReply*)), SLOT(finishRequest(QNetworkReply*)));

	syncInformation();
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
QUrl vk::vkAccount::getAvatarUrl() const{
	return Avatar;
}
void vk::vkAccount::updateToken(const QString& new_token){
	token = new_token;
	syncInformation();
}

void vk::vkAccount::httpGET(const QString& method, QUrlQuery urlq){
	urlq.addQueryItem("access_token", token);
	urlq.addQueryItem("v", API_VERSION);
	QUrl url = API_URL.toString() + method;
	url.setQuery(urlq);
	qDebug() << url.url();
	httpGET(QNetworkRequest(url));
}

void vk::vkAccount::httpGET(QNetworkRequest request){
	lastNetReply = netManager->get(request);
	emit requestSended();
}


void vk::vkAccount::syncInformation(){
	connect(this, SIGNAL(requestFinished(const QByteArray&)), SLOT(updateInformation(const QByteArray&)));
	connect(this, SIGNAL(requestError(const ApiRequestError&)), SIGNAL(syncError()));
	QUrlQuery query;
	query.addQueryItem("fields","photo_100");
	emit syncStarted();
	httpGET("users.get", query);
}

void vk::vkAccount::updateInformation(const QByteArray& reply){
	disconnect(this, SIGNAL(requestFinished(const QByteArray&)), this, SLOT(updateInformation(const QByteArray&)));
	disconnect(this, SIGNAL(requestError(const ApiRequestError&)), this, SIGNAL(syncError()));
	QJson::Parser parser;
	qDebug() << reply;
	QVariantMap result = parser.parse(reply).toMap()["response"].toList()[0].toMap();
	fname = result["first_name"].toString();
	lname = result["last_name"].toString();
	id = result["id"].toString();
	Avatar = result["photo_100"].toString();
	qDebug() << "User" << lname  << fname << "id" + id  << "Avatar" << Avatar << "added\n";
	emit syncFinished();
}

void vk::vkAccount::finishRequest(QNetworkReply* reply){
	if (reply->error() != QNetworkReply::NetworkError::NoError){
		emit requestError(RequestStatus = RequestFailed);
	}
	else{
		QByteArray ArrayToSend = reply->readAll();
		checkForErrors(ArrayToSend);
		if (RequestStatus == NoErrors){
			emit requestFinished(ArrayToSend);
		}
		else{
			emit requestError(RequestStatus);
		}
	}
	reply->deleteLater();
}

bool vk::vkAccount::isRunning() const{
	if (lastNetReply == NULL)
		return false;
	return lastNetReply->isRunning();
}
bool vk::vkAccount::isFinished() const{
	if (lastNetReply == NULL)
		return true;
	return lastNetReply->isFinished();
}
vk::ApiRequestError vk::vkAccount::lastRequestStatus() const{
	return RequestStatus;
}
vk::ApiRequestError vk::vkAccount::checkForErrors(const QByteArray& bta){
	qDebug() << bta;
	QJson::Parser parser;
	QVariantMap vmp= parser.parse(bta).toMap();
	if (vmp.find("error") != vmp.end()){
		RequestStatus = ApiRequestError(vmp["error"].toMap()["error_code"].toInt());
		ErrorMsg = vmp["error"].toMap()["error_msg"].toString();
		qDebug() << "ERROR" << RequestStatus;
		return RequestStatus;
	}
	else{
		RequestStatus = NoErrors;
		ErrorMsg = "No Errors";
	}
	return RequestStatus;
}
QString vk::vkAccount::getErrorMsg() const{
	return ErrorMsg;
}