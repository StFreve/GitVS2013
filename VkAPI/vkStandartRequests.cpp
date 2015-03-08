#include <vk.h>
QString vk::StandartRequests::DefaultParametr = "";
void vk::StandartRequests::Users::get(vk::vkAccount& user, QString user_ids, QString fields, QString name_case){
	QUrlQuery query;
	if (!user_ids.isEmpty()){
		query.addQueryItem("user_ids", user_ids);
	}
	if (!fields.isEmpty()){
		query.addQueryItem("fields", fields);
	}
	if (!name_case.isEmpty()){
		query.addQueryItem("name_case", name_case);
	}
	user.httpGET("users.get", query);
}
