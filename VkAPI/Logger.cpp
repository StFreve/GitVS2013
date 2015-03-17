#include <Logger.h>
using namespace vk;

Logger::Logger(QWidget* parent)
	:QTextEdit(parent){
	setReadOnly(true);
}

void Logger::userNewUser(vkAccount* newUser){
	append(time() + ": Trying to add new user.");
	connect(newUser, SIGNAL(syncStarted()), SLOT(userSyncStarted()));
	connect(newUser, SIGNAL(syncFinished()), SLOT(userSyncEnded()));
	connect(newUser, SIGNAL(syncError()), SLOT(userSyncError()));
	connect(newUser, SIGNAL(destroyed()), SLOT(userDeleted()));

}
void Logger::userDeleted(){
	QString user = getUserName((vkAccount*)sender());
	user = textColor("<b> " + user, "blue");

	append("User " + user + " was deleted.");
}
void Logger::userSyncStarted(){
	append(time() + ": User started synchronization.");
}
void Logger::userSyncEnded(){
	QString user = getUserName((vkAccount*)sender());
	user = textColor("<b> " + user, "blue");

	connect(((vkAccount*)sender()), SIGNAL(requestSended()), SLOT(userRequestSended()));
	connect(((vkAccount*)sender()), SIGNAL(requestFinished(const QByteArray&)), SLOT(userRequestSuccess()));
	connect(((vkAccount*)sender()), SIGNAL(requestError(const ApiRequestError&)), SLOT(userRequestError(const ApiRequestError&)));

	append(time("green") + ": User " + user + " synchronized.");
}
void Logger::userSyncError(){
	append(time() + ": " + textColor("User faild to synchronize.", "red"));
}
void Logger::userRequestSended(){
	QString user = getUserName((vkAccount*)sender());
	user = textColor("<b> " + user, "blue");

	append(time() + ": User " + user + " sended new request.");
}
void Logger::userRequestSuccess(){
	QString user = getUserName((vkAccount*)sender());
	user = textColor("<b> " + user, "blue");

	append(time("green") + ": User " + user + " succeess request");
}
void Logger::userRequestError(const ApiRequestError&){
	QString user = getUserName((vkAccount*)sender());
	user = textColor("<b> " + user, "blue");

	append(time("red") + ": User " + user + " request failed. " + textColor( "<b>" + ((vkAccount*)sender())->getErrorMsg(), "red"));
}
void Logger::requestNewRequest(Requests*){

}
void Logger::requestRequestDeleted(){

}

QString Logger::getUserName(vkAccount* user){
	return  user->getFirstName() + " " + user->getLastName();
}

QString Logger::textColor(const QString& text, const QString& color){
	return "<font color = '" + color + "' >" + text + +"</font>";
}

QString Logger::time(QString color){
	return textColor( "<b>" + QTime::currentTime().toString(), color);
}