#include <vk.h>
const QString vk::vkAccountUI::DefaultAvatar("Images\\default.png");

vk::vkAccountUI::vkAccountUI(vkAccount* user, QWidget* parent)
	:QPushButton(parent),
	user(user){
	if (!user)
		user = new vkAccount(this);
	fname = new QLabel("First Name: ");
	lname = new QLabel("Last Name: ");
	id = new QLabel("User ID: ");
	state = new QCheckBox;
	avatar = new QLabel;
	
	connect(user, SIGNAL(syncFinished()), SLOT(updateInformation()));
	connect(this, SIGNAL(clicked()), SLOT(invertCheck()));
	setView();
}
vk::vkAccountUI::vkAccountUI(const QString& token, QWidget* parent)
	:vkAccountUI(0,parent){
	setToken(token);
}
vk::vkAccountUI::~vkAccountUI(){

}

void vk::vkAccountUI::setToken(const QString& new_token){
	user->updateToken(new_token);
}
void vk::vkAccountUI::updateInformation(){
	fname->setText("First Name:  " + user->getFirstName());
	lname->setText("Last Name:  " + user->getLastName());
	id->setText   ("User ID:       id" + user->getUserID());
	if (user->getAvatarUrl().url().contains("camera") || user->getAvatarUrl().url().isEmpty()){
		AvatarFileName = DefaultAvatar;
	}
	else{
		QString ImFormat = user->getAvatarUrl().path().section('.', -1);
		AvatarFileName = "Images\\id" + user->getUserID() + "." + ImFormat;
	}
	QFile image(AvatarFileName);
	if (image.exists()){
		QPixmap image(AvatarFileName);
		avatar->setPixmap(image.scaled(56, 56));
	}
	else
		downloadImage();

}
vk::vkAccount* vk::vkAccountUI::getAccount() const{
	return user;
}

void vk::vkAccountUI::downloadImage(){
	netManager = new QNetworkAccessManager;
	QNetworkRequest req(user->getAvatarUrl());
	connect(netManager, SIGNAL(finished(QNetworkReply*)), SLOT(saveAndSetDownloadedImage(QNetworkReply*)));
	QNetworkReply* reply = netManager->get(req);
	
}

void vk::vkAccountUI::saveAndSetDownloadedImage(QNetworkReply* reply){
	if (reply->error() != NoErrors){
		avatar->setPixmap(QPixmap(DefaultAvatar).scaled(56, 56));
		return;
	}
	QFile file(AvatarFileName);
	file.open(QIODevice::WriteOnly);
	file.write(reply->readAll());
	file.close();
	QPixmap image(AvatarFileName);
	avatar->setPixmap(image.scaled(56,56));
}

void vk::vkAccountUI::setView(){

	requestLabel = new StatusLabel();
	requestLabel->addStatus(StatusLabel::OK, "Status\\ReqFinished.png", "Request successfully sended");
	requestLabel->addStatus(StatusLabel::isRunning, "Status\\ReqSending.png", "Sending request");
	requestLabel->addStatus(StatusLabel::Error, "Status\\ReqFailed.png", "Request failed");

	syncLabel = new StatusLabel();
	syncLabel->addStatus(StatusLabel::OK, "Status\\SyncDone.png", "Synchronized");
	syncLabel->addStatus(StatusLabel::isRunning, "Status\\Sync.png", "Synchronizing");
	syncLabel->addStatus(StatusLabel::Error, "Status\\SyncFailed.png", "Synchronization failed");

	connect(user, SIGNAL(syncStarted()), syncLabel, SLOT(setIsRunning()));
	connect(user, SIGNAL(syncFinished()), syncLabel, SLOT(setOK()));
	connect(user, SIGNAL(syncError()), syncLabel, SLOT(setError()));

	connect(user, SIGNAL(requestSended()), requestLabel, SLOT(setIsRunning()));
	connect(user, SIGNAL(requestFinished(const QByteArray&)), requestLabel, SLOT(setOK()));
	connect(user, SIGNAL(requestError(const ApiRequestError&)), requestLabel, SLOT(setError()));


	requestLabel->setStatus(StatusLabel::isRunning);
	syncLabel->setStatus(StatusLabel::isRunning);

	avatar->setPixmap(QPixmap(DefaultAvatar).scaled(56, 56));

	state->setChecked(false);
	connect(state, SIGNAL(stateChanged(int)), SLOT(setActive(int)));
	
	QVBoxLayout* info_layout = new QVBoxLayout;
	info_layout->setMargin(0);
	info_layout->setAlignment(Qt::AlignRight | Qt::AlignTop);
	info_layout->addWidget(fname);
	info_layout->addWidget(lname);
	info_layout->addWidget(id);


	QVBoxLayout* status_layout = new QVBoxLayout;
	status_layout->setMargin(0);
	status_layout->setAlignment(Qt::AlignTop | Qt::AlignRight);
	status_layout->addWidget(syncLabel);
	status_layout->addWidget(requestLabel);

	main_layout = new QHBoxLayout;
	main_layout->setMargin(5);
	main_layout->setAlignment(Qt::AlignCenter);
	main_layout->addWidget(state, 0, Qt::AlignCenter);
	main_layout->addWidget(avatar);     // Avatar
	main_layout->addLayout(info_layout); // Account Information
	main_layout->addStretch(50);
	main_layout->addLayout(status_layout); // Status 
	setLayout(main_layout);
	
	if (user->getFirstName() != "unknown")
		updateInformation();
	setFixedHeight(70);
}


void vk::vkAccountUI::setChecked(int st){
	if (bool(st) != state->isChecked()){
		state->setChecked(bool(st));
		setProperty("cheked", bool(st));
	}
}

void vk::vkAccountUI::setActive(int st){
	if (st == 0 || st == 2){
		emit stateChanged(st);
	}
}

bool vk::vkAccountUI::isChecked() const{
	return state->isChecked();
}

void vk::vkAccountUI::mouseReleaseEvent(QMouseEvent *me){
	if (me->x() >= 0 && me->y() >= 0 && me->x() <= width() && me->y() <= height())
		setChecked(!isChecked());
	QPushButton::mouseReleaseEvent(me);
}
