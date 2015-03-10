#pragma once 
#include <vk.h>

class vk::vkAccountUI: public QWidget{
	Q_OBJECT

public:
	vkAccountUI(QWidget* = 0);
	vkAccountUI(vkAccount*, QWidget* = 0);
	vkAccountUI(const QString& token, QWidget* = 0);
	~vkAccountUI();

	
	vkAccount* getAccount() const;
public slots:
	void updateInformation();
	void setToken(const QString&);
private:
	vkAccount* user;
	QLabel *fname, *lname, *id, *avatar;
	StatusLabel *requestLabel, *syncLabel;
	QHBoxLayout* main_layout;
	QNetworkAccessManager* netManager;
	QString AvatarFileName;
	static const QString DefaultAvatar;

	void setView();
	void downloadImage();
private slots:
	void saveAndSetDownloadedImage(QNetworkReply*);
};