#include <vk.h>

using namespace vk;
RequestsViewer::RequestsViewer(QWidget* parent)
	:QScrollArea(parent){
	QWidget* wgt = new QWidget;
	wgt->setLayout(mainLayout = new FlowLayout);
	mainLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	mainLayout->setSpacing(1);
	setWidgetResizable(true);
	setWidget(wgt);
}

void RequestsViewer::addRequest(Requests* req){
	mainLayout->addWidget(req);
	connect(req, SIGNAL(destroyed()), SLOT(deleteRequest));
	reqList << req;
}

void RequestsViewer::deleteRequest(){
	Requests* toDel = (Requests*)sender();
	reqList.removeOne(toDel);
}