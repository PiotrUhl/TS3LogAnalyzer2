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
	//dopisuje zawartoœæ rekordu do statystyk odpowiednich u¿ytkowników
	void update(const LineInfo& lineInfo);
private:
	//zwraca referencjê na strukturê u¿ytkownika o podanym id; dodaje u¿ytkownika jeœli trzeba
	UserData& getUser(uint id);
	//dopisuje zawartoœæ rekordu do statystyk odpowiednich u¿ytkowników
	void updateClientConnected(const LineInfo& lineInfo);
	void updateClientDisconnected(const LineInfo& lineInfo);
};

