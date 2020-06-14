#include "UserDataUpdater.h"
#include "LineInfo.h"
#include "LineInfo1id1name1ip.h"
#include "UserData.hpp"

//dopisuje zawartość rekordu do statystyk odpowiednich użytkowników
void UserDataUpdater::update(const LineInfo& lineInfo) {
	switch (lineInfo.getType()) {
	case RecordType::CLIENT_CONNECTED:
		updateClientConnected(lineInfo);
	//case RecordType::CLIENT_DISCONNECTED:
		//updateClientDisonnected(lineInfo);
	};
}

void UserDataUpdater::updateClientConnected(const LineInfo& lineInfo) {
	const LineInfo1id1name1ip& info = static_cast<const LineInfo1id1name1ip&>(lineInfo);
	unsigned int id = info.getId1();
	while (userData.size() <= id) { //brak użytkownika w bazie
		userData.push_back(UserData(static_cast<unsigned int>(userData.size()))); //cast only to suppress warning
	}
	userData[id].clientConnected++;
	if (userData[id].connectedClients++ == 0)
		userData[id].currentTime = info.getTime();
	userData[id].lastNickname = info.getName1();
	userData[id].nicknames.insert(info.getName1());
}
