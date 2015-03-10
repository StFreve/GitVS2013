#include <vk.h>
#include <vk_api.h>
#include <QtWidgets/QApplication>
#include <vkAccout.h>
#include <QJsonArray>
#include <QScrollArea>
//int main(int argc, char *argv[])
//{
//	QApplication a(argc, argv);
//	QScrollArea main;
//
//	QVBoxLayout* vbl = new QVBoxLayout;
//	vk::vkAccountUI* vkUI[10]; 
//	vkUI[0] = new vk::vkAccountUI("7233eab01fc001bd4eb033d9d6215c876fa5bf56a3d68eed62553260b0093ce03e91d45ab0ba066e8fb07");
//	vkUI[1] = new vk::vkAccountUI("624d89e83aef0c6280a6189cdfffa7892afc4ce6475675eade18f194cab700733bc2779c778c204de1976");
//	vkUI[2] = new vk::vkAccountUI("ca18ed93806a88d9fe377ab1874b275d17fe1c3474d99ab574e650328f002b1acb092cf37b792cb5751a9");
//	vkUI[3] = new vk::vkAccountUI("7df1cecb785305eab711c2b0a19b5d77438bf53b6df580953be1d0e099bbbf00a6a04326aab6be6b890d7");
//	vkUI[4] = new vk::vkAccountUI("4c1d904aab823210778c1316cb627820461048c538944599f64a8e8fed9f92ca6bf2f1ff5494fd79645a8");
//	vkUI[5] = new vk::vkAccountUI("60c3ecf78b653d99b52276982826ebc08fd6e3dbfb927133c3495a107d8b8a314691b9dedfb3e0b67a702");
//	QList<vk::vkAccount*> list;
//	for(int i = 0; i < 1; ++i){
//		vbl->addWidget(vkUI[i]);
//		list.push_back(vkUI[i]->getAccount());
//	}
//	Requests* req = new Requests(list);
//	QPushButton pb("press");
//	QWidget::connect(&pb, SIGNAL(clicked()), req, SLOT(wallPost()));
//	main.setLayout(vbl);
//	main.setWidgetResizable(true);
//	main.show();
//	pb.show();
//	return a.exec();
//}

using namespace vk;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/*vkAccountUI* ui = new vkAccountUI;
	vkLogin* login = new vkLogin;
	QWidget::connect(login, SIGNAL(tokenWasGet(const QString&)), ui, SLOT(setToken(const QString&)));
	QWidget::connect(ui->getAccount(), SIGNAL(syncStarted()), ui, SLOT(show()));
	QPushButton pb;
	login->go();*/
	ParallelControl w;
	w.show();
	return a.exec();
}
