#pragma once
#include <vk.h>
class vk::vkLogin :public QWidget{
	Q_OBJECT

public:
	vkLogin(QWidget* = 0);
signals:
	void tokenWasGet(const QString&);
public slots:
	void urlChanged(const QUrl&);
	void go();
private:
	QWebView* Page;

	static	QUrlQuery makeQuery();
};