#pragma once
#include <vk.h>
class vk::vkAccount:public QWidget{
	Q_OBJECT
	Q_PROPERTY(QString first_name READ getFirstName)
	Q_PROPERTY(QString last_mame READ getLastName)
	Q_PROPERTY(QString access_token READ getToken)
	Q_PROPERTY(QString user_id READ getUserID)


signals:
	void syncFinished();
	void syncError();
	void requestFinished(const QByteArray&);
	void requestError();

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

	// Write Functions
	void updateToken(const QString&);

	// POST and GET Requests
	QNetworkReply* httpGET(const QString&,QUrlQuery);
	QNetworkReply* httpGET(QNetworkRequest);

	QNetworkReply* httpPOST(const QString&, QUrlQuery);
	QNetworkReply* httpPOST(QNetworkRequest);

	
public slots:
	void syncInformation();


private slots:
	void updateInformation(const QByteArray& info);
	void finishRequest(QNetworkReply*);

private:
	//Variables
	QString fname, lname, token, id;
	QDateTime lastUpdate;
	QNetworkAccessManager* netManager;

	QString LogIn(const QString&, const QString&); // Login and return Access token
};