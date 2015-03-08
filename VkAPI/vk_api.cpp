#include "vk_api.h"
#include <qjson\serializer.h>
vk_api::vk_api(QWidget *parent)
	: QWidget(parent)
{
	user = new vk::vkAccount("7233eab01fc001bd4eb033d9d6215c876fa5bf56a3d68eed62553260b0093ce03e91d45ab0ba066e8fb07");
	Request = new QLineEdit("Request");
	Result = new QTextEdit("Result");
	sendRequest = new QPushButton("Send Request");
	QVBoxLayout* vbl = new QVBoxLayout;
	connect(user, SIGNAL(requestFinished(const QByteArray&)), SLOT(showRes(const QByteArray&)));
	connect(user, SIGNAL(requestError(const ApiRequestError&)), SLOT(Error()));

	connect(sendRequest, SIGNAL(clicked()), SLOT(send()));
	vbl->addWidget(Request);
	vbl->addWidget(sendRequest);
	vbl->addWidget(Result);
	this->setLayout(vbl);
	ui.setupUi(this);
}
void vk_api::send(){
	QString req = Request->text();
	QStringList list = req.split(";");
	QUrlQuery qu;
	QString method = list[0];
	list.erase(list.begin());
	foreach(QString str, list){
		QStringList t = str.split("=");
		qu.addQueryItem(t[0], t[1]);
	}
	user->httpGET(method, qu);
}
void vk_api::showRes(const QByteArray& res){
	qDebug() << res;
	Result->setText(res);
}
void vk_api::Error(){
	Result->setText("Error");
}
vk_api::~vk_api()
{

}
