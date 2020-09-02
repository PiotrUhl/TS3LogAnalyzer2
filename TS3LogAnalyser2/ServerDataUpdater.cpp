#include "ServerDataUpdater.h"
#include "LineInfo.h"
#include "ServerData.hpp"

//dopisuje zawarto�� rekordu do statystyk serwera
void ServerDataUpdater::update(const LineInfo& lineInfo) {
	switch (lineInfo.getType()) {
	case RecordType::SERVER_STARTED:
		//todo: sprawdzi� czy wszycy u�ytkownicy s� roz��czeni
		//todo: liczenie uptimu
		serverData.started++;
		break;
	case RecordType::SERVER_MODIFIED:
		serverData.edited++;
		break;
	case RecordType::SERVER_STOPPED:
		//todo: liczenie uptimu
		serverData.stopped++;
		break;
	case RecordType::PERMISSION_CHANGED:
		serverData.permissionModified++;
		break;
	case RecordType::QUERY_CONNECTED:
		serverData.queryClientConnected++;
		break;
	case RecordType::QUERY_DISCONNECTED:
		serverData.queryClientDisonnected++;
		break;
	case RecordType::CLIENT_CONNECTED:
		serverData.clientConnected++;
		break;
	case RecordType::CLIENT_DISCONNECTED:
		updateClientDisconnected(lineInfo);
		break;
	case RecordType::CLIENT_SERVERGRUOP_MODIFIED: //todo: rozr�nienie
	case RecordType::CLIENT_CHANNELGROUP_MODIFIED:
		serverData.clientGroupModified++;
		break;
	case RecordType::BAN_ADDED:
		serverData.bans++;
		break;
	}
}

//dopisuje zawarto�� rekordu do statystyk serwera
void ServerDataUpdater::updateClientDisconnected(const LineInfo& lineInfo) {
	std::string reasonmsg = lineInfo.getString(LineData::MESSAGE1);
	//todo: rozpoznawanie rodzaju opuszczenia serwera po reasonmsg
}
