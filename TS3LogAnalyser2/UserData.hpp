#pragma once
#include <ctime> //time_t
#include <string> //std::string
#include <set> //std::set

//statystyki u�ytkownika

struct UserData {
	const unsigned int dbid; //dbid u�ytkownika
	bool active = false; //czy u�ytkownik wyst�puje w obr�bie przetworzonych log�w
	unsigned int clientConnected = 0; //ilo�� wej�� na server
	unsigned int clientConnectedQuery = 0; //ilo�� wej�� na server z konsoli
	unsigned int clientDisconnectedQuery = 0; //ilo�� wyj�� z servera z konsoli
	unsigned int clientDisconnectedLeaving = 0; //ilo�� wyj�� z servera (przez opuszczenie)
	unsigned int clientDisconnectedTimedOut = 0; //ilo�� wyjs� z servera (przez Timed Out)
	unsigned int clientDisconnectedKicked = 0; //ilo�� wyj�� z servera (przez kick)
	unsigned int clientDisconnectedKickedIdle = 0; //ilo�� wyj�� z servera (przez idleKick)
	unsigned int clientDisconnectedBanned = 0; //ilo�� wyj�� z servera (przez ban)
	unsigned int connectedClients = 0; //ilo�� klon�w u�ytkownika na serwerze
	time_t upTime = 0; //�aczny uptime u�ytkownika
	time_t currentTime = 0; //tymczasowo przechowywany czas
	time_t maxUpTime = 0; //najd�u�szy uptime u�ytkownika
	unsigned int channelCreated = 0; //ilo�� utworzonych kana��w
	unsigned int channelSubCreated = 0; //ilo�� utworzonych podkana��w
	unsigned int channelModified = 0; //ilo�� zmodyfiikowanych kana��w
	unsigned int channelDeleted = 0; //ilo�� usuni�tych kana��w
	unsigned int bansGiven = 0; //ilo�� danych ban�w
	unsigned int bansDeleted = 0; //ilo�� usunietych ban�w
	unsigned int complaintTaken = 0; //ilo�� otrzymanych complain�w
	unsigned int complaintGiven = 0; //ilo�� danych complain�w
	unsigned int fileUploaded = 0; //ilo�� zuploadowanych plik�w
	unsigned int fileDownloaded = 0; //ilo�� pobranych plik�w
	unsigned int fileDeleted = 0; //ilo�� usuni�tych plik�w
	unsigned int fileMoved = 0; //ilo�� przeniesionych/zmian nazwy plik�w
	unsigned int fileDirectory = 0; //ilo�� operacji na folderach plik�w
	unsigned int serverModified = 0; //ilo�� modyfikajci servera
	unsigned int permissionModified = 0; //ilo�� modyfikacji uprawnie�
	unsigned int clientGroupModified = 0; //ilo�� wykonanych modyfikacji grupy
	unsigned int clientGroupWasModified = 0; //ilo�� modyfikacji grupy u�ytkownika
	std::string lastNickname; //ostatnia znana nazwa u�ytkownika
	std::set<std::string> nicknames; //u�ywane nazwy u�ytkownika

	UserData(unsigned int _dbid) : dbid(_dbid) {}
};
