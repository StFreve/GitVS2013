#pragma once
#include <vk.h>
using namespace vk;


class vk::vkAlarm:public QTimer{
	Q_OBJECT

public:
	vkAlarm(const vkAlarm&);
	vkAlarm(vkAccount*, QWidget* = 0);
	~vkAlarm();
	vkAccount* getUser();
protected:
	vkAccount* AlarmingUser;
};