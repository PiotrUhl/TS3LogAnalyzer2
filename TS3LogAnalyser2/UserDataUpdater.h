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
	//dopisuje zawarto�� rekordu do statystyk odpowiednich u�ytkownik�w
	void update(const LineInfo& lineInfo);
private:
	//dopisuje zawarto�� rekordu do statystyk odpowiednich u�ytkownik�w
	void updateClientConnected(const LineInfo& lineInfo);
};

