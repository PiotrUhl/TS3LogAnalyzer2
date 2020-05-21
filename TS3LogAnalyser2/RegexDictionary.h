#pragma once
#include "RecordType.hpp"
#include <string>
#include <regex>
#include <map>

class RegexDictionary {
	const std::map<RecordType, std::regex> idents = {
		//{RecordType::UNIDENTIFIED, std::regex("")},
		//{RecordType::SERVER_STARTED, std::regex("")},
		//{RecordType::SERVER_MODIFIED, std::regex("")},
		//{RecordType::SERVER_STOPPED, std::regex("")},
		//{RecordType::PERMISSION_CHANGED, std::regex("")},
		//{RecordType::QUERY_CONNECTED, std::regex("")},
		//{RecordType::QUERY_DISCONNECTED, std::regex("")},
		{RecordType::CLIENT_CONNECTED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServerBase\|((  \d+)|(\d+  ))\| ?client connected '.+'\(id:\d+\)( using a myTeamSpeak ID)? from \d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}:\d{1,5})")},
		{RecordType::CLIENT_DISCONNECTED, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|INFO    \|VirtualServerBase\|((  \d+)|(\d+  ))\| ?client disconnected '.+'\(id:\d+\) reason 'reasonmsg=.+')")},
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

public:
	//zwraca s³ownik regexów identyfikuj¹cych
	const std::map<RecordType, std::regex>& getIdentMap() const;
};

