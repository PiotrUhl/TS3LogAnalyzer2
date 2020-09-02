#pragma once
#include <ctime> //time_t
#include <string> //std::string
#include <set> //std::set

//statystyki u¿ytkownika

struct UserData {
	const unsigned int dbid; //dbid u¿ytkownika
	bool active = false; //czy u¿ytkownik wystêpuje w obrêbie przetworzonych logów
	unsigned int clientConnected = 0; //iloœæ wejœæ na server
	unsigned int clientConnectedQuery = 0; //iloœæ wejœæ na server z konsoli
	unsigned int clientDisconnectedQuery = 0; //iloœæ wyjœæ z servera z konsoli
	unsigned int clientDisconnectedLeaving = 0; //iloœæ wyjœæ z servera (przez opuszczenie)
	unsigned int clientDisconnectedTimedOut = 0; //iloœæ wyjsæ z servera (przez Timed Out)
	unsigned int clientDisconnectedKicked = 0; //iloœæ wyjœæ z servera (przez kick)
	unsigned int clientDisconnectedKickedIdle = 0; //iloœæ wyjœæ z servera (przez idleKick)
	unsigned int clientDisconnectedBanned = 0; //iloœæ wyjœæ z servera (przez ban)
	unsigned int connectedClients = 0; //iloœæ klonów u¿ytkownika na serwerze
	time_t upTime = 0; //³aczny uptime u¿ytkownika
	time_t currentTime = 0; //tymczasowo przechowywany czas
	time_t maxUpTime = 0; //najd³u¿szy uptime u¿ytkownika
	unsigned int channelCreated = 0; //iloœæ utworzonych kana³ów
	unsigned int channelSubCreated = 0; //iloœæ utworzonych podkana³ów
	unsigned int channelModified = 0; //iloœæ zmodyfiikowanych kana³ów
	unsigned int channelDeleted = 0; //iloœæ usuniêtych kana³ów
	unsigned int bansGiven = 0; //iloœæ danych banów
	unsigned int bansDeleted = 0; //iloœæ usunietych banów
	unsigned int complaintTaken = 0; //iloœæ otrzymanych complainów
	unsigned int complaintGiven = 0; //iloœæ danych complainów
	unsigned int fileUploaded = 0; //iloœæ zuploadowanych plików
	unsigned int fileDownloaded = 0; //iloœæ pobranych plików
	unsigned int fileDeleted = 0; //iloœæ usuniêtych plików
	unsigned int fileMoved = 0; //iloœæ przeniesionych/zmian nazwy plików
	unsigned int fileDirectory = 0; //iloœæ operacji na folderach plików
	unsigned int serverModified = 0; //iloœæ modyfikajci servera
	unsigned int permissionModified = 0; //iloœæ modyfikacji uprawnieñ
	unsigned int clientGroupModified = 0; //iloœæ wykonanych modyfikacji grupy
	unsigned int clientGroupWasModified = 0; //iloœæ modyfikacji grupy u¿ytkownika
	std::string lastNickname; //ostatnia znana nazwa u¿ytkownika
	std::set<std::string> nicknames; //u¿ywane nazwy u¿ytkownika

	UserData(unsigned int _dbid) : dbid(_dbid) {}
};
