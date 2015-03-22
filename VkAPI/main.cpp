#include <vk.h>
#include <vk_api.h>
#include <QtWidgets/QApplication>
#include <vkAccout.h>
#include <QJsonArray>
#include <QScrollArea>
#include <QStyle>
using namespace vk;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	QFile file("Style.qss");
	file.open(QFile::ReadOnly);
	QString strCSS = QLatin1String(file.readAll());
	qApp->setStyleSheet(strCSS);
	
	srand(time(NULL));
	ParallelControl w;
	w.show();
	return a.exec();
}

//7233eab01fc001bd4eb033d9d6215c876fa5bf56a3d68eed62553260b0093ce03e91d45ab0ba066e8fb07
//624d89e83aef0c6280a6189cdfffa7892afc4ce6475675eade18f194cab700733bc2779c778c204de1976
//ca18ed93806a88d9fe377ab1874b275d17fe1c3474d99ab574e650328f002b1acb092cf37b792cb5751a9
//7df1cecb785305eab711c2b0a19b5d77438bf53b6df580953be1d0e099bbbf00a6a04326aab6be6b890d7
//4c1d904aab823210778c1316cb627820461048c538944599f64a8e8fed9f92ca6bf2f1ff5494fd79645a8
//60c3ecf78b653d99b52276982826ebc08fd6e3dbfb927133c3495a107d8b8a314691b9dedfb3e0b67a702
