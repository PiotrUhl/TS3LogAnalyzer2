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
		//{RecordType::SERVER_STARTED, std::regex("")},
		//{RecordType::SERVER_MODIFIED, std::regex("")},
		//{RecordType::SERVER_STOPPED, std::regex("")},
		//{RecordType::PERMISSION_CHANGED, std::regex("")},
		//{RecordType::QUERY_CONNECTED, std::regex("")},
		//{RecordType::QUERY_DISCONNECTED, std::regex("")},
		{RecordType::CLIENT_CONNECTED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServerBase\|((  \d+)|(\d+  ))\| ?client connected '.+'\(id:\d+\)( using a myTeamSpeak ID)? from \d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}:\d{1,5})")},
		{RecordType::CLIENT_DISCONNECTED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServerBase\|((  \d+)|(\d+  ))\| ?client disconnected '.+'\(id:\d+\) reason 'reasonmsg=.+')")}
		//{RecordType::CLIENT_SERVERGRUOP_MODIFIED, std::regex("")},
		//{RecordType::CLIENT_CHANNELGROUP_MODIFIED, std::regex("")},
		//{RecordType::BAN_ADDED, std::regex("")},
		//{RecordType::BAN_DELETED, std::regex("")},
		//{RecordType::BAN_EXPIRED, std::regex("")},
		//{RecordType::COMPLAINT_ADDED, std::regex("")},
		//{RecordType::COMPLAINT_DELETED, std::regex("")},
		//{RecordType::COMPLAINT_ALL_DELETED, std::regex("")},
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
		{RecordType::CLIENT_CONNECTED, {std::regex(R"(client connected '(.+)'\(id:(\d+)\)( using a myTeamSpeak ID)? from (\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}):(\d{1,5}))"), {LineData::NONE, LineData::NAME1, LineData::ID1, LineData::NONE/*chyba jest tu bool czy myTeamSpeakID*/, LineData::IP1, LineData::PORT1}}},
		{RecordType::CLIENT_DISCONNECTED, {std::regex(R"(client disconnected '(.+)'\(id:(\d+)\) reason 'reasonmsg=(.+)')"), {LineData::NONE, LineData::NAME1, LineData::ID1, LineData::MESSAGE1}}}
	};

public:
	//zwraca s³ownik regexów identyfikuj¹cych
	const std::map<RecordType, std::regex>& getIdentMap() const;
	//zwraca s³ownik regexów wyci¹gaj¹cych dane
	const std::map<RecordType, std::pair<std::regex, std::vector<LineData>>>& getDataMap() const;
};

