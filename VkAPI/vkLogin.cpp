#include <vk.h>
using namespace vk;

vkLogin::vkLogin(QWidget* parent)
	:QWidget(parent),
	Page(new QWebView(this)){
	connect(Page, SIGNAL(urlChanged(const QUrl&)), SLOT(urlChanged(const QUrl&)));
}

void vkLogin::go(){
	QUrl urlToGo = AUTH_URL;
	urlToGo.setQuery(makeQuery());
	qDebug() << urlToGo;
	Page->load(urlToGo);
}
void vkLogin::urlChanged(const QUrl& url){
	QUrlQuery query(url.url().section('#', -1));
	if (query.hasQueryItem("access_token")){
		emit tokenWasGet(query.queryItemValue("access_token"));
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