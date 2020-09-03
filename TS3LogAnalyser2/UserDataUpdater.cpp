#include "UserDataUpdater.h"
#include "LineInfo.h"
#include "UserData.hpp"
#include "LineData.hpp"

//dopisuje zawarto�� rekordu do statystyk odpowiednich u�ytkownik�w
void UserDataUpdater::update(const LineInfo& lineInfo) {
	switch (lineInfo.getType()) {
	case RecordType::SERVER_MODIFIED:
		getUser(lineInfo.getUint(LineData::ID1)).serverModified++;
		break;
	case RecordType::PERMISSION_CHANGED:
		getUser(lineInfo.getUint(LineData::ID1)).permissionModified++;
		break;
	case RecordType::QUERY_CONNECTED:
		getUser(lineInfo.getUint(LineData::ID1)).clientConnectedQuery++;
		break;
	case RecordType::QUERY_DISCONNECTED:
		//todo: rozr�nianie rodzaju wyj�cia query po reasonmsg
		getUser(lineInfo.getUint(LineData::ID1)).clientDisconnectedQuery++;
		break;
	case RecordType::CLIENT_CONNECTED:
		updateClientConnected(lineInfo);
		break;
	case RecordType::CLIENT_DISCONNECTED:
		updateClientDisconnected(lineInfo);
		break;
	case RecordType::CLIENT_SERVERGRUOP_MODIFIED: //todo: rozr�nienie
	case RecordType::CLIENT_CHANNELGROUP_MODIFIED:
		getUser(lineInfo.getUint(LineData::ID1)).clientGroupWasModified++;
		getUser(lineInfo.getUint(LineData::ID3)).clientModifiedGroup++;
		break;
	case RecordType::BAN_ADDED:
		getUser(lineInfo.getUint(LineData::ID1)).bansGiven++;
		break;
	case RecordType::BAN_DELETED:
		getUser(lineInfo.getUint(LineData::ID1)).bansDeleted++;
		break;
	case RecordType::COMPLAINT_ADDED:
		getUser(lineInfo.getUint(LineData::ID1)).complaintTaken++;
		getUser(lineInfo.getUint(LineData::ID2)).complaintGiven++;
		break;
	case RecordType::COMPLAINT_DELETED:
		break;
	case RecordType::CHANNEL_CREATED:
		getUser(lineInfo.getUint(LineData::ID2)).channelCreated++;
		break;
	case RecordType::CHANNEL_EDITED:
		getUser(lineInfo.getUint(LineData::ID2)).channelModified++;
		break;
	case RecordType::CHANNEL_SUB_CREATED:
		getUser(lineInfo.getUint(LineData::ID3)).channelSubCreated++;
		break;
	};
}

//zwraca referencj� na struktur� u�ytkownika o podanym id; dodaje u�ytkownika je�li trzeba
UserData& UserDataUpdater::getUser(uint id) {
	while (userData.size() <= id) { //brak u�ytkownika w bazie
		userData.push_back(UserData(static_cast<unsigned int>(userData.size()))); //cast only to suppress warning
	}
	return userData.at(id);
}

void UserDataUpdater::updateClientConnected(const LineInfo& lineInfo) {
	UserData& user = getUser(lineInfo.getUint(LineData::ID1));
	user.clientConnected++;
	if (user.connectedClients++ == 0)
		user.currentTime = lineInfo.getTime();
	user.lastNickname = lineInfo.getString(LineData::NAME1);
	user.nicknames.insert(lineInfo.getString(LineData::NAME1));
}

void UserDataUpdater::updateClientDisconnected(const LineInfo& lineInfo) {
	UserData& user = getUser(lineInfo.getUint(LineData::ID1));
	std::string reasonmsg = lineInfo.getString(LineData::MESSAGE1);
	user.clientDisconnectedLeaving++; //todo: rozr�nianie typu disconnectu po reasonmsg

	if (user.connectedClients-- == 1) { //je�eli nie ma wi�cej kopii u�ytkownika na serwerze, liczymy czas
		time_t uptime = lineInfo.getTime() - user.currentTime; //czas kt�ry u�ytkownik sp�dzi� na serwerze prze tym roz��czeniem (od ostatniego po��czenia)
		user.upTime += uptime;
		if (user.maxUpTime < uptime)
			user.maxUpTime = uptime;
			user.maxUpTime = uptime;
	}
}