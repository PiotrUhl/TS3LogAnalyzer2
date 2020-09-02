#pragma once
#include "RecordType.hpp" //RecordType
#include "LineData.hpp" //LineData
#include <string> //std::string
#include <regex> //std::regex
#include <forward_list> //std::forward_list
#include <map> //std::map

class RegexDictionary {
	const std::map<RecordType, std::regex> identMap = {
		//{RecordType::UNIDENTIFIED, std::regex("")},
		{RecordType::SERVER_STARTED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServer \|((  \d+)|(\d+  ))\| ?listening on \d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}:\d{1,5})")},
		{RecordType::SERVER_MODIFIED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServerBase\|((  \d+)|(\d+  ))\| ?server was edited by '.+'\(id:\d+\))")},
		{RecordType::SERVER_STOPPED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServerBase\|((  \d+)|(\d+  ))\| ?stopped)")},
		{RecordType::PERMISSION_CHANGED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServer \|((  \d+)|(\d+  ))\| ?permission '.+'\(id:\d+\) with values \(value:.+\) was added by '.+'\(id:\d+\).+)")},
		{RecordType::QUERY_CONNECTED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServer \|((  \d+)|(\d+  ))\| ?query client connected '.+'\(id:\d+\))")},
		{RecordType::QUERY_DISCONNECTED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServerBase\|((  \d+)|(\d+  ))\| ?query client disconnected '.+'\(id:\d+\) reason 'reasonmsg=.+')")},
		{RecordType::CLIENT_CONNECTED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServerBase\|((  \d+)|(\d+  ))\| ?client connected '.+'\(id:\d+\)( using a myTeamSpeak ID)? from \d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}:\d{1,5})")},
		{RecordType::CLIENT_DISCONNECTED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServerBase\|((  \d+)|(\d+  ))\| ?client disconnected '.+'\(id:\d+\) reason 'reasonmsg=.+')")},
		{RecordType::CLIENT_SERVERGRUOP_MODIFIED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServer \|((  \d+)|(\d+  ))\| ?client \(id:\d+\) was added to servergroup '.+'\(id:\d+\) by client '.+'\(id:\d+\))")},
		{RecordType::CLIENT_CHANNELGROUP_MODIFIED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServer \|((  \d+)|(\d+  ))\| ?client '.+'\(id:\d+\) was added to channelgroup '.+'\(id:\d+\) by client '.+'\(id:\d+\) in channel '.+'\(id:\d+\))")},
		{RecordType::BAN_ADDED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?ban added reason='(.*)' (cluid|ip|name)='(.+)' bantime=(\d+) by client '(.+)'\(id:(\d+)\))")},
		{RecordType::BAN_DELETED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?ban deleted reason='(.*)' (cluid|ip|name)='(.+)' bantime=(\d+) by client '(.+)'\(id:(\d+)\))")},
		{RecordType::BAN_EXPIRED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|BanManager    \|(?:  \d+|\d+  )\| ?ban deleted \(expired\) reason='(.*)' (cluid|ip|name)='(.+)' bantime=(\d+) by client '(.+)'\(id:(\d+)\))")},
		{RecordType::COMPLAINT_ADDED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?complaint added for client '(.+)'\(id:(\d+)\) reason '(.*)' by client '(.+)'\(id:(\d+)\))")},
		{RecordType::COMPLAINT_DELETED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?complaint got deleted by client '(.+)'\(id:(\d+)\) for client '(.+)'\(id:(\d+)\) complained by '(.+)'\(id:(\d+)\))")},
		{RecordType::COMPLAINT_ALL_DELETED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?all complaints got deleted by client '(.+)'\(id:(\d+)\) for client '(.+)'\(id:(\d+)\))")},
		//{RecordType::CHANNEL_CREATED, std::regex("")},
		//{RecordType::CHANNEL_EDITED, std::regex("")},
		//{RecordType::CHANNEL_DELETED, std::regex("")},
		//{RecordType::CHANNEL_SUB_CREATED, std::regex("")},
		//{RecordType::FILE_UPLOADED, std::regex("")},
		//{RecordType::FILE_DOWNLOADED, std::regex("")},
		//{RecordType::FILE_DELETED, std::regex("")},
		//{RecordType::FILE_MOVED, std::regex("")},
		//{RecordType::FILE_DIRECTORY, std::regex("")}
	};

	//przyk³ad id1 dla channelCreated: regex reg(R"(\| channel '.+'\(id:(\d+)\) created by '.+'\(id:\d+\))");
	//do ka¿dego typu rekordu przypisany jest regex wyci¹gaj¹cy dane z niego oraz pod której ka¿dym indexem jest rodzaj danych zwracanych przez regexa pod tym indeksem
	const std::map<RecordType, std::pair<std::regex, std::vector<LineData>>> dataMap = {
		{RecordType::SERVER_STARTED, {std::regex(R"(listening on (\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}):(\d{1,5}))"), {LineData::NONE, LineData::IP1, LineData::PORT1}}},
		{RecordType::SERVER_MODIFIED, {std::regex(R"(server was edited by '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::NAME1, LineData::ID1}}},
		{RecordType::SERVER_STOPPED, {std::regex(R"(stopped)"), {LineData::NONE}}}, //todo: zoptymalizowaæ LineInterpreter::makeLineInfo() tak, by mo¿na by³o to usun¹æ
		{RecordType::PERMISSION_CHANGED, {std::regex(R"(permission '.+'\(id:\d+\) with values \(value:.+\) was added by '(.+)'\(id:(\d+)\).+)"), {LineData::NONE, LineData::NAME1, LineData::ID1}}}, //tu jest znacznie wiêcej informacji do wyci¹gniêcia, ale na razie s¹ one niepotrzebne
		{RecordType::QUERY_CONNECTED, {std::regex(R"(query client connected '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::NAME1, LineData::ID1}}},
		{RecordType::QUERY_DISCONNECTED, {std::regex(R"(query client disconnected '(.+)'\(id:(\d+)\) reason 'reasonmsg=(.+)')"), {LineData::NONE, LineData::NAME1, LineData::ID1, LineData::MESSAGE1}}},
		{RecordType::CLIENT_CONNECTED, {std::regex(R"(client connected '(.+)'\(id:(\d+)\)( using a myTeamSpeak ID)? from (\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}):(\d{1,5}))"), {LineData::NONE, LineData::NAME1, LineData::ID1, LineData::NONE/*chyba jest tu bool czy myTeamSpeakID*/, LineData::IP1, LineData::PORT1}}},
		{RecordType::CLIENT_DISCONNECTED, {std::regex(R"(client disconnected '(.+)'\(id:(\d+)\) reason 'reasonmsg=(.+)')"), {LineData::NONE, LineData::NAME1, LineData::ID1, LineData::MESSAGE1}}},
		{RecordType::CLIENT_SERVERGRUOP_MODIFIED, {std::regex(R"(client \(id:(\d+)\) was added to servergroup '(.+)'\(id:(\d+)\) by client '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::ID1, LineData::NAME2, LineData::ID2, LineData::NAME3, LineData::ID3}}},
		{RecordType::CLIENT_CHANNELGROUP_MODIFIED, {std::regex(R"(client '(.+)'\(id:(\d+)\) was added to channelgroup '(.+)'\(id:(\d+)\) by client '(.+)'\(id:(\d+)\) in channel '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::NAME1, LineData::ID1, LineData::NAME2, LineData::ID2, LineData::NAME3, LineData::ID3, LineData::NAME4, LineData::ID4}}},
		{RecordType::BAN_ADDED, {std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?ban added reason='(.*)' (cluid|ip|name)='(.+)' bantime=(\d+) by client '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::MESSAGE1, LineData::NONE /*ban target type*/, LineData::NONE /*ban target*/, LineData::NONE /*ban time*/, LineData::NAME1, LineData::ID1}}},
		{RecordType::BAN_DELETED, {std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?ban deleted reason='(.*)' (cluid|ip|name)='(.+)' bantime=(\d+) by client '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::MESSAGE1, LineData::NONE /*ban target type*/, LineData::NONE /*ban target*/, LineData::NONE /*ban time*/, LineData::NAME1, LineData::ID1}}},
		{RecordType::BAN_EXPIRED, {std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|BanManager    \|(?:  \d+|\d+  )\| ?ban deleted \(expired\) reason='(.*)' (cluid|ip|name)='(.+)' bantime=(\d+) by client '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::MESSAGE1, LineData::NONE /*ban target type*/, LineData::NONE /*ban target*/, LineData::NONE /*ban time*/, LineData::NAME1, LineData::ID1}}},
		{RecordType::COMPLAINT_ADDED, {std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?complaint added for client '(.+)'\(id:(\d+)\) reason '(.*)' by client '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::NAME1, LineData::ID1, LineData::MESSAGE1, LineData::NAME2, LineData::ID2}}},
		{RecordType::COMPLAINT_DELETED, {std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?complaint got deleted by client '(.+)'\(id:(\d+)\) for client '(.+)'\(id:(\d+)\) complained by '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::NAME1, LineData::ID1, LineData::NAME2, LineData::ID2, LineData::NAME3, LineData::ID3}}},
		{RecordType::COMPLAINT_ALL_DELETED, {std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.\d{6}\|INFO    \|VirtualServer \|(?:  \d+|\d+  )\| ?all complaints got deleted by client '(.+)'\(id:(\d+)\) for client '(.+)'\(id:(\d+)\))"), {LineData::NONE, LineData::NAME1, LineData::ID1, LineData::NAME2, LineData::ID2}}},
	};

public:
	//zwraca s³ownik regexów identyfikuj¹cych
	const std::map<RecordType, std::regex>& getIdentMap() const;
	//zwraca s³ownik regexów wyci¹gaj¹cych dane
	const std::map<RecordType, std::pair<std::regex, std::vector<LineData>>>& getDataMap() const;
};

