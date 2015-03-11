#include <vk.h>
using namespace vk;
vkAlarm::vkAlarm(vkAccount* user, size_t timeToStart, QWidget* parent)
	:AlarmingUser(user), QTimer(parent), startTime(timeToStart), forPause(timeToStart){
	connect(AlarmingUser, SIGNAL(destroyed()), SLOT(deleteLater()));
}
vkAlarm::vkAlarm(const vkAlarm& rha)
	:AlarmingUser(rha.AlarmingUser),
	forPause(rha.forPause),
	startTime(rha.startTime){

}
vkAlarm::~vkAlarm(){

}

vkAccount* vkAlarm::getUser(){
	return AlarmingUser;
}

void vkAlarm::pause(){
	if (isActive()){
		forPause = remainingTime();
		stop();
	}
}

void vkAlarm::resume(){
	if (!isActive()){
		setInterval(forPause);
		start();
	}
}

void vkAlarm::start(){
	setInterval(startTime);
	QTimer::start();
}

void vkAlarm::setInterval(int msec){
	startTime = msec;
	forPause = msec;
	QTimer::setInterval(msec);
}