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
	//dopisuje zawartość rekordu do statystyk odpowiednich użytkowników
	void update(const LineInfo& lineInfo);
private:
	//dopisuje zawartość rekordu do statystyk odpowiednich użytkowników
	void updateClientConnected(const LineInfo& lineInfo);
};

