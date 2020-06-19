#include "UserDataUpdater.h"
#include "LineInfo.h"
#include "UserData.hpp"

//dopisuje zawartoœæ rekordu do statystyk odpowiednich u¿ytkowników
void UserDataUpdater::update(const LineInfo& lineInfo) {
	switch (lineInfo.getType()) {
	case RecordType::CLIENT_CONNECTED:
		updateClientConnected(lineInfo);
	//case RecordType::CLIENT_DISCONNECTED:
		//updateClientDisonnected(lineInfo);
	};
}

void UserDataUpdater::updateClientConnected(const LineInfo& lineInfo) {
	unsigned int id = lineInfo.get1id();
	while (userData.size() <= id) { //brak u¿ytkownika w bazie
		userData.push_back(UserData(static_cast<unsigned int>(userData.size()))); //cast only to suppress warning
	}
	userData[id].clientConnected++;
	if (userData[id].connectedClients++ == 0)
		userData[id].currentTime = lineInfo.getTime();
	userData[id].lastNickname = lineInfo.get1nickname();
	userData[id].nicknames.insert(lineInfo.get1nickname());
}
