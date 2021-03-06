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
	//dopisuje zawartość rekordu do statystyk odpowiednich użytkowników
	void update(const LineInfo& lineInfo);
private:
	//zwraca referencję na strukturę użytkownika o podanym id; dodaje użytkownika jeśli trzeba
	UserData& getUser(uint id);
	//dopisuje zawartość rekordu do statystyk odpowiednich użytkowników
	void updateClientConnected(const LineInfo& lineInfo);
	void updateClientDisconnected(const LineInfo& lineInfo);
};

