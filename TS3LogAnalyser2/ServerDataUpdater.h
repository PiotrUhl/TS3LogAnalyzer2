#pragma once

struct ServerData;
class LineInfo;

//aktualizator struktury ServerData
class ServerDataUpdater {
	ServerData& serverData;
public:
	//konstruktor
	ServerDataUpdater(ServerData& _serverData) : serverData(_serverData) {}
	//dopisuje zawartoœæ rekordu do statystyk serwera
	void update(const LineInfo& lineInfo);
};

