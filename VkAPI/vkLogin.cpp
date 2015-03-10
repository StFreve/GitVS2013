#include <vk.h>
using namespace vk;

vkLogin::vkLogin(QWidget* parent)
	:QWidget(parent),
	Page(new QWebView){
	QBoxLayout* layout = new QBoxLayout(QBoxLayout::LeftToRight);
	layout->setMargin(0);
	layout->addWidget(Page);
	setLayout(layout);
	resize(380, 430);
	connect(Page, SIGNAL(urlChanged(const QUrl&)), SLOT(urlChanged(const QUrl&)));
	connect(Page, SIGNAL(loadFinished(bool)), SLOT(showLogin(bool)));
}

void vkLogin::go(){
	QUrl urlToGo = AUTH_URL;
	urlToGo.setQuery(makeQuery());
	qDebug() << urlToGo;
	setEnabled(true);
	auto cookie = Page->page()->networkAccessManager()->cookieJar();
	Page->page()->networkAccessManager()->setCookieJar(new QNetworkCookieJar);
	Page->load(urlToGo);
	
}
void vkLogin::urlChanged(const QUrl& url){
	QUrlQuery query(url.url().section('#', -1));
	if (query.hasQueryItem("access_token")){
		setEnabled(false);
		createUser(query.queryItemValue("access_token"));
		hide();
	}
}

QUrlQuery vkLogin::makeQuery(){
	QUrlQuery query;
	query.addQueryItem("client_id", APP_ID);
	query.addQueryItem("scope", SCOPE);
	query.addQueryItem("redirect_uri", "https://oauth.vk.com/blank.html");
	query.addQueryItem("display", "mobile");
	query.addQueryItem("v", API_VERSION);
	query.addQueryItem("response_type", "token");
	return query;
}

void vkLogin::showLogin(bool ch){
	qDebug() << Page->url();
	if (ch && isEnabled()){
		Page->history()->clear();
		show();
	}
}

void vkLogin::createUser(const QString& token){
	emit newUser(new vkAccount(token));
}