#pragma once
#include <vk.h>
class vk::vkAccount:public QWidget{
	Q_OBJECT
	Q_PROPERTY(QString first_name READ getFirstName)
	Q_PROPERTY(QString last_mame READ getLastName)
	Q_PROPERTY(QString access_token READ getToken)
	Q_PROPERTY(QString user_id READ getUserID)


signals:
	void syncStarted();
	void syncFinished();
	void syncError();
	void requestFinished(const QByteArray&);
	void requestError(const ApiRequestError&);
	void requestSended();
public:
	// Constructors and Destructor
	vkAccount(QWidget* = 0);
	vkAccount(const QString&, QWidget* = 0);  // Init with Access token
	vkAccount(const QString&, const QString&, QWidget* = 0); //Init with Login and Password
	~vkAccount();

	// Read functions
	QString getToken() const;
	QString getFirstName() const;
	QString getLastName() const;
	QString getUserID() const;
	QUrl getAvatarUrl() const;
	// Write Functions
	void updateToken(const QString&);

	// POST and GET Requests
	void httpGET(const QString&,QUrlQuery);
	void httpGET(QNetworkRequest);

	// Status
	bool isRunning() const;
	bool isFinished() const;
	ApiRequestError lastRequestStatus() const;
	QString getErrorMsg() const;
	
public slots:
	void syncInformation();


private slots:
	void updateInformation(const QByteArray&);
	void finishRequest(QNetworkReply*);

private:
	//Variables
	QString fname, lname, token, id;
	QUrl Avatar;
	QDateTime lastUpdate;
	QNetworkAccessManager* netManager;
	QNetworkReply* lastNetReply;
	ApiRequestError RequestStatus;
	QString ErrorMsg;

	ApiRequestError checkForErrors(const QByteArray&);
	QString LogIn(const QString&, const QString&); // Login and return Access token
};