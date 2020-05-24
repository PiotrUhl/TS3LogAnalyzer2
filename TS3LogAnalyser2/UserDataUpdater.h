#pragma once
#include <vector> //std::vector

struct UserData;
class LineInfo;

//aktualizator struktury UserData
class UserDataUpdater {
	std::vector<UserData>& userData;
public:
	//konstruktor
	UserDataUpdater(std::vector<UserData>& _userData) : userData(_userData) {}
	//dopisuje zawartoœæ rekordu do statystyk odpowiednich u¿ytkowników
	void update(const LineInfo& lineInfo);
private:
	//dopisuje zawartoœæ rekordu do statystyk odpowiednich u¿ytkowników
	void updateClientConnected(const LineInfo& lineInfo);
};

