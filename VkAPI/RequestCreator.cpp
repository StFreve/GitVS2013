#include <vk.h>
using namespace vk;
RequestCreator::RequestCreator(QWidget* parent)
	:QWidget(parent){
	QVBoxLayout* mainLayout = new QVBoxLayout;
	

	QHBoxLayout* buttons = new QHBoxLayout;
	QPushButton* OK = new QPushButton("OK");
	QPushButton* Cancel = new QPushButton("Cancel");
	buttons->addWidget(OK);
	buttons->addWidget(Cancel);
	connect(OK, SIGNAL(clicked()), SLOT(createRequest()));
	connect(OK, SIGNAL(clicked()), SLOT(hide()));
	connect(Cancel, SIGNAL(clicked()), SLOT(hide()));
	QVBoxLayout* secondTabLayout = new QVBoxLayout;
	secondTabLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	QWidget* secondTab = new QWidget;
	secondTabLayout->addWidget(timeSettings = new RequestTimeSettings);
	secondTabLayout->addWidget(new QLabel("Send type:"));
	secondTabLayout->addWidget(&RequestSendType);
	RequestSendType.addItem("Default");
	RequestSendType.addItem("Random");
	secondTab->setLayout(secondTabLayout);
	tabs.addTab(firstTab = new QWidget, "Request");
	tabs.addTab(secondTab, "Settings");
	mainLayout->addWidget(&tabs);
	mainLayout->addLayout(buttons);

	setLayout(mainLayout);
}

void RequestCreator::newRequest(QLayout* firstTabLayout, const QString& newMethod){
	if (firstTab->layout())
		delete firstTab->layout();
	firstTab->setLayout(firstTabLayout);
	textLines.clear();
	textBoxes.clear();
	spinBoxes.clear();
	method = newMethod;
}
void RequestCreator::setTextLines(const QList<QPair<QString, QLineEdit*> >& lst){
	textLines = lst;
}
void RequestCreator::setTextBoxes(const QList<QPair<QString, QTextEdit*> >& lst){
	textBoxes = lst;
}
void RequestCreator::setSpinBoxes(const QList<QPair<QString, QSpinBox*> >& lst){
	spinBoxes = lst;
}

void RequestCreator::setUsers(const QList<vkAccount*>& usersList){
	usersToSend = usersList;
}
void  RequestCreator::createRequest(){
	QMap<QString, QVector<QString> > query;
	foreach(auto reqSet, textLines){
		if (reqSet.second->text() != "")
		query[reqSet.first] << reqSet.second->text();
	}
	foreach(auto reqSet, textBoxes){
		if (reqSet.second->toPlainText() != "")
		query[reqSet.first] << reqSet.second->toPlainText();
	}
	foreach(auto reqSet, spinBoxes){
		if (reqSet.second->text() != "")
		query[reqSet.first] << reqSet.second->text();
	}
	Requests* newRequest = new Requests(usersToSend, method, query, *timeSettings, Requests::SendType(RequestSendType.currentIndex()));
	emit newRequestCreated(newRequest);
}