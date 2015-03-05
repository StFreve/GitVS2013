#include "vk_api.h"
#include <QtWidgets/QApplication>
#include <vkAccout.h>
#include <QJsonArray>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	vk::vkAccount vk_user("7233eab01fc001bd4eb033d9d6215c876fa5bf56a3d68eed62553260b0093ce03e91d45ab0ba066e8fb07");
	vk_user.show();
	QJsonArray js; 
	return a.exec();
}
