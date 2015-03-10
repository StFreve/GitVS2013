#include <vk.h>
using namespace vk;
vkAlarm::vkAlarm(vkAccount* user, QWidget* parent)
	:AlarmingUser(user), QTimer(parent){
}
vkAlarm::vkAlarm(const vkAlarm& rha)
	:AlarmingUser(rha.AlarmingUser){

}
vkAlarm::~vkAlarm(){

}

vkAccount* vkAlarm::getUser(){
	return AlarmingUser;
}