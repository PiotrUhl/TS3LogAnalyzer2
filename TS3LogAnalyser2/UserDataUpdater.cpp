#include "UserDataUpdater.h"
#include "LineInfo.h"
#include "UserData.hpp"
#include "LineData.hpp"

//dopisuje zawartoœæ rekordu do statystyk odpowiednich u¿ytkowników
void UserDataUpdater::update(const LineInfo& lineInfo) {
	switch (lineInfo.getType()) {
	case RecordType::CLIENT_CONNECTED:
		updateClientConnected(lineInfo);
		break;
	case RecordType::CLIENT_DISCONNECTED:
		updateClientDisconnected(lineInfo);
		break;
	};
}

void UserDataUpdater::updateClientConnected(const LineInfo& lineInfo) {
	unsigned int id = lineInfo.getUint(LineData::ID1);
	while (userData.size() <= id) { //brak u¿ytkownika w bazie
		userData.push_back(UserData(static_cast<unsigned int>(userData.size()))); //cast only to suppress warning
	}
	userData[id].clientConnected++;
	if (userData[id].connectedClients++ == 0)
		userData[id].currentTime = lineInfo.getTime();
	userData[id].lastNickname = lineInfo.getString(LineData::NAME1);
	userData[id].nicknames.insert(lineInfo.getString(LineData::NAME1));
}

void UserDataUpdater::updateClientDisconnected(const LineInfo& lineInfo) {
	unsigned int id = lineInfo.getInt(LineData::ID1);
	while (userData.size() <= id) { //brak u¿ytkownika w bazie
		userData.push_back(UserData(static_cast<unsigned int>(userData.size()))); //cast only to suppress warning
	}

	std::string reasonmsg = lineInfo.getString(LineData::MESSAGE1);
	userData[id].clientDisconnectedLeaving++; //todo: rozró¿nianie typu disconnectu po reasonmsg

	if (userData[id].connectedClients-- == 1) { //je¿eli nie ma wiêcej kopii u¿ytkownika na serwerze, liczymy czas
		time_t uptime = lineInfo.getTime() - userData[id].currentTime; //czas który u¿ytkownik spêdzi³ na serwerze prze tym roz³¹czeniem (od ostatniego po³¹czenia)
		userData[id].upTime += uptime;
		if (userData[id].maxUpTime < uptime)
			userData[id].maxUpTime = uptime;
	}
}