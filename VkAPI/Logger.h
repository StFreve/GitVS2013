#pragma once
#include <vk.h>
using namespace vk;
class vk::Logger :public QTextEdit{
	Q_OBJECT

public:
	Logger(QWidget* = 0);
public slots:
	void userNewUser(vkAccount*);
	void userDeleted();
	void userSyncStarted();
	void userSyncEnded();
	void userSyncError();
	void userRequestSended();
	void userRequestSuccess();
	void userRequestError(const ApiRequestError&);
	void requestNewRequest(Requests*);
	void requestRequestDeleted();
private:
	QString getUserName(vkAccount*);
	QString textColor(const QString&, const QString&);
	QString time(QString = "grey");
};