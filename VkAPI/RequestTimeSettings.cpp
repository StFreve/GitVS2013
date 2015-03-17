#include <vk.h>
using namespace vk;
RequestTimeSettings::RequestTimeSettings(QWidget* parent)
	:QGroupBox(parent){
	m_delayTime.setDisplayFormat("hh:mm:ss");
	m_repeatTime.setDisplayFormat("hh:mm:ss");
	m_userDelayTime.setDisplayFormat("hh:mm:ss");

	setTitle("Time settings");
	QGridLayout* lay = new QGridLayout;
	lay->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	lay->addWidget(new QLabel("Delay request:"), 0, 0);
	lay->addWidget(&m_delayTime, 0, 1);

	
	lay->addWidget(new QLabel("Delay between request:"), 1, 0);
	lay->addWidget(&m_userDelayTime, 1, 1);

	m_repeat.setText("Repeat request");
	connect(&m_repeat, SIGNAL(stateChanged(int)), SLOT(repeatSetActive(int)));
	repeatSetActive(0);
	lay->addWidget(&m_repeat, 2, 0);
	lay->addWidget(&m_repeatTime, 2, 1);
	setLayout(lay);
}

void RequestTimeSettings::repeatSetActive(int state){
	if (state != 1)
		m_repeatTime.setEnabled(state);
}

QTime RequestTimeSettings::delayTime() const{
	return m_delayTime.time();
}
QTime RequestTimeSettings::repeatTime() const{
	return m_repeatTime.time();
}
QTime RequestTimeSettings::userDelayTime() const{
	return m_userDelayTime.time();
}
bool RequestTimeSettings::repeat() const{
	return m_repeat.isChecked();
}

void RequestTimeSettings::setDefault(){
	m_delayTime.clear();
	m_repeatTime.clear();
	m_userDelayTime.clear();
	m_repeat.setChecked(false);
}