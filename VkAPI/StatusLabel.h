#pragma once
#include <vk.h>
class vk::StatusLabel : public QLabel{
	Q_OBJECT

	QMap<int, QPair<QString, QString> > statuses; // ID - Picture With Hint Text 
	const QSize picSize;
public:
	enum StatusID{
		OK,
		isRunning,
		Error
	};
	StatusLabel(int = 20, int = 20, QWidget* = 0);
	void addStatus(StatusID, const QString&, const QString&);
	void setStatus(StatusID, QString = "");
public slots:
	void setIsRunning();
	void setOK();
	void setError();
};