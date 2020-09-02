#include "ServerDataUpdater.h"
#include "LineInfo.h"
#include "ServerData.hpp"

//dopisuje zawartoœæ rekordu do statystyk serwera
void ServerDataUpdater::update(const LineInfo& lineInfo) {
	switch (lineInfo.getType()) {
	case RecordType::SERVER_STARTED:
		//todo: sprawdziæ czy wszycy u¿ytkownicy s¹ roz³¹czeni
		//todo: liczenie uptimu
		serverData.started++;
		break;
	case RecordType::SERVER_STOPPED:
		//todo: liczenie uptimu
		serverData.stopped++;
		break;
	case RecordType::CLIENT_CONNECTED:
		serverData.clientConnected++;
		break;
	case RecordType::CLIENT_DISCONNECTED:
		updateClientDisconnected(lineInfo);
		break;
	};
}

//dopisuje zawartoœæ rekordu do statystyk serwera
void ServerDataUpdater::updateClientDisconnected(const LineInfo& lineInfo) {
	std::string reasonmsg = lineInfo.getString(LineData::MESSAGE1);
	//todo: rozpoznawanie rodzaju opuszczenia serwera po reasonmsg
}
