#pragma once
#include <vk.h>
using namespace vk;


class vk::vkAlarm:public QTimer{
	Q_OBJECT

public slots:
	void pause();
	void resume();
	void start();
public:
	vkAlarm(const vkAlarm&);
	vkAlarm(vkAccount*, size_t, QWidget* = 0);
	~vkAlarm();
	vkAccount* getUser();
	void setInterval(int);
protected:
	vkAccount* AlarmingUser;
	size_t forPause;
	size_t startTime;
};