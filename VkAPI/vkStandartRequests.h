#pragma once
#include <vk.h>
class vk::StandartRequests{
	static QString DefaultParametr;
public:
	class Users{
		static void get(vkAccount&, QString = DefaultParametr, QString = DefaultParametr, QString = DefaultParametr); // User Accout, User ID, Fields, Name Case
		static void search(vkAccount&);
		static void isAppUser(vkAccount&);
		static void getSubscriptions(vkAccount&);
		static void getFollowers(vkAccount&);
		static void report(vkAccount&);
		static void getNearby(vkAccount&);
	}
};