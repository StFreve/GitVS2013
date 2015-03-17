#pragma once
#include <vk.h>

class vk::RequestCreator :public QWidget{
	Q_OBJECT

public:
	RequestCreator(QWidget* = 0);
	void newRequest(QLayout*, const QString&);
	void setTextLines(const QList<QPair<QString, QLineEdit*> >&);
	void setTextBoxes(const QList<QPair<QString, QTextEdit*> >&);
	void setSpinBoxes(const QList<QPair<QString, QSpinBox*> >&);
	void setUsers(const QList<vkAccount*>&);
public slots:
	void createRequest();
signals:
	void newRequestCreated(Requests*);
private:
	QString method;
	QTabWidget tabs;
	RequestTimeSettings* timeSettings;
	QComboBox RequestSendType;
	QWidget* firstTab;
	QList<QPair<QString,QLineEdit*> > textLines;
	QList<QPair<QString, QTextEdit*> > textBoxes;
	QList<QPair<QString, QSpinBox*> > spinBoxes;
	QList<vkAccount*> usersToSend;
};