#pragma once
#include <vector> //std::vector

typedef unsigned int uint;
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
	//zwraca referencj� na struktur� u�ytkownika o podanym id; dodaje u�ytkownika je�li trzeba
	UserData& getUser(uint id);
	//dopisuje zawarto�� rekordu do statystyk odpowiednich u�ytkownik�w
	void updateClientConnected(const LineInfo& lineInfo);
	void updateClientDisconnected(const LineInfo& lineInfo);
};

