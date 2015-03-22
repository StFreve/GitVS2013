#pragma once 
#include <vk.h>

class vk::vkAccountUI: public QPushButton {
	Q_OBJECT
	Q_PROPERTY(bool checked READ isChecked)
public:
	vkAccountUI(vkAccount* = 0, QWidget* = 0);
	vkAccountUI(const QString& token, QWidget* = 0);
	~vkAccountUI();

	
	vkAccount* getAccount() const;
signals:
	void stateChanged(int);
	void pressed();
public slots:
	void setChecked(int);
	void updateInformation();
	void setToken(const QString&);
	bool isChecked() const;
protected:
	void mouseReleaseEvent(QMouseEvent *);
private slots:
	void setActive(int);

private:
	QCheckBox* state;
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