#pragma once
#include <ctime> //time_t

struct ServerData { //statystyki servera
	unsigned int started = 0; //iloœæ w³¹czeñ servera
	unsigned int edited = 0; //iloœæ modyfikacji servera
	unsigned int stopped = 0; //iloœæ zatrzymañ servera
	time_t upTime = 0; //³aczny uptime servera
	time_t currentTime = 0; //tymczasowo przechowywany czas
	time_t maxUpTime = 0; //najd³u¿szy uptime servera
	unsigned int channelsDeletedAuto = 0; //iloœæ kana³ów usuniêtych automatycznie
	unsigned int bansExpired = 0; //iloœæ przedawnionych banów
	unsigned int queryClientConnected = 0; //iloœæ po³¹czeñ z konsol¹
	unsigned int queryClientDisonnected = 0; //iloœæ roz³¹czeñ z konsol¹
	unsigned int clientConnected = 0; //iloœæ wejœæ na server
	unsigned int clientDisconnectedLeaving = 0; //iloœæ wyjœæ z servera (przez opuszczenie)
	unsigned int clientDisconnectedTimedOut = 0; //iloœæ wyjsæ z servera (przez Timed Out)
	unsigned int clientDisconnectedKicked = 0; //iloœæ wyjœæ z servera (przez kick)
	unsigned int clientDisconnectedKickedIdle = 0; //iloœæ wyjœæ z servera (przez idleKick)
	unsigned int clientDisconnectedBanned = 0; //iloœæ wyjœæ z servera (przez ban)
	unsigned int channelCreated = 0; //iloœæ utworzonych kana³ów
	unsigned int channelSubCreated = 0; //iloœæ utworzonych kana³ów
	unsigned int channelModified = 0; //iloœæ zmodyfiikowanych kana³ów
	unsigned int channelDeleted = 0; //iloœæ usuniêtych kana³ów
	unsigned int bans = 0; //iloœæ danych banów
	unsigned int bansDeleted = 0; //iloœæ usunietych banów
	unsigned int complaint = 0; //iloœæ otrzymanych complainów
	unsigned int fileUploaded = 0; //iloœæ zuploadowanych plików
	unsigned int fileDownloaded = 0; //iloœæ pobranych plików
	unsigned int fileDeleted = 0; //iloœæ usuniêtych plików
	unsigned int fileMoved = 0; //iloœæ przeniesionych/zmian nazwy plików
	unsigned int fileDirectory = 0; //iloœæ operacji na folderach plików
	unsigned int permissionModified = 0; //iloœæ modyfikacji uprawnieñ
	unsigned int clientGroupModified = 0; //iloœæ wykonanych modyfikacji grupy
};