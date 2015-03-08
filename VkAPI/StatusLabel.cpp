#include <StatusLabel.h>
using namespace vk;
StatusLabel::StatusLabel(int w, int h, QWidget* parent)
	:QLabel(parent),
	picSize(w,h){

}
void StatusLabel::addStatus(StatusID ID, const QString& Pic, const QString& Hint){
	statuses[ID] = qMakePair(Pic, Hint);
}
void StatusLabel::setStatus(StatusID ID, QString msg){
	QString PicAddr = statuses[ID].first;
	QString Hint;
	if (msg.isEmpty())
		Hint = statuses[ID].second;
	else
		Hint = msg;
	QPixmap Pic(PicAddr);
	setPixmap(Pic.scaled(picSize));
	setToolTip(Hint);
}

void StatusLabel::setIsRunning(){
	setStatus(isRunning);
}
void StatusLabel::setOK(){
	setStatus(OK);
}
void StatusLabel::setError(){
	QString error_msg = ((vkAccount*)sender())->getErrorMsg();
	setStatus(Error, error_msg);
}