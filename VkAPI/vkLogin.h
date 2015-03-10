#pragma once
#include <vk.h>
class vk::vkLogin :public QWidget{
	Q_OBJECT

public:
	vkLogin(QWidget* = 0);
signals:
	void newUser(vkAccount*);
public slots:
	void urlChanged(const QUrl&);
	void go();
private slots:
	void showLogin(bool);
	void createUser(const QString&);
private:
	QWebView* Page;

	static	QUrlQuery makeQuery();
};