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
	case RecordType::CLIENT_SERVERGRUOP_MODIFIED: //todo: rozró¿nienie
	case RecordType::CLIENT_CHANNELGROUP_MODIFIED:
		serverData.clientGroupModified++;
		break;
	case RecordType::BAN_ADDED:
		serverData.bans++;
		break;
	case RecordType::BAN_DELETED:
		serverData.bansDeleted++;
		break;
	case RecordType::BAN_EXPIRED:
		serverData.bansExpired++;
		break;
	case RecordType::COMPLAINT_ADDED:
		serverData.complaint++;
		break;
	case RecordType::CHANNEL_CREATED:
		serverData.channelCreated++;
		break;
	case RecordType::CHANNEL_EDITED:
		serverData.channelModified++;
		break;
	case RecordType::CHANNEL_DELETED: //todo: rozró¿nienie miêdzy deleted a deleteg auto (id usera 0)
		serverData.channelDeleted++;
		break;
	case RecordType::CHANNEL_SUB_CREATED:
		serverData.channelSubCreated++;
		break;
	case RecordType::FILE_UPLOADED:
		serverData.fileUploaded++;
		break;
	case RecordType::FILE_DOWNLOADED:
		serverData.fileDownloaded++;
		break;
	case RecordType::FILE_DELETED:
		serverData.fileDeleted++;
		break;
	}
}

//dopisuje zawartoœæ rekordu do statystyk serwera
void ServerDataUpdater::updateClientDisconnected(const LineInfo& lineInfo) {
	std::string reasonmsg = lineInfo.getString(LineData::MESSAGE1);
	//todo: rozpoznawanie rodzaju opuszczenia serwera po reasonmsg
}
