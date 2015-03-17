#pragma once
#include <vk.h>

class vk::RequestTimeSettings:public QGroupBox{
	Q_OBJECT

public:
	RequestTimeSettings(QWidget* = 0);
	QTime delayTime() const;
	QTime repeatTime() const;
	QTime userDelayTime() const;
	bool repeat() const;
	void setDefault();
public slots:
	void repeatSetActive(int);
private:
	QTimeEdit m_delayTime, m_repeatTime, m_userDelayTime;
	QCheckBox m_repeat;
};