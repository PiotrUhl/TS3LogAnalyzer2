#pragma once
#include <ctime> //time_t

struct ServerData { //statystyki servera
	unsigned int started = 0; //ilo�� w��cze� servera
	unsigned int edited = 0; //ilo�� modyfikacji servera
	unsigned int stopped = 0; //ilo�� zatrzyma� servera
	time_t upTime = 0; //�aczny uptime servera
	time_t currentTime = 0; //tymczasowo przechowywany czas
	time_t maxUpTime = 0; //najd�u�szy uptime servera
	unsigned int channelsDeletedAuto = 0; //ilo�� kana��w usuni�tych automatycznie
	unsigned int bansExpired = 0; //ilo�� przedawnionych ban�w
	unsigned int queryClientConnected = 0; //ilo�� po��cze� z konsol�
	unsigned int queryClientDisonnected = 0; //ilo�� roz��cze� z konsol�
	unsigned int clientConnected = 0; //ilo�� wej�� na server
	unsigned int clientDisconnectedLeaving = 0; //ilo�� wyj�� z servera (przez opuszczenie)
	unsigned int clientDisconnectedTimedOut = 0; //ilo�� wyjs� z servera (przez Timed Out)
	unsigned int clientDisconnectedKicked = 0; //ilo�� wyj�� z servera (przez kick)
	unsigned int clientDisconnectedKickedIdle = 0; //ilo�� wyj�� z servera (przez idleKick)
	unsigned int clientDisconnectedBanned = 0; //ilo�� wyj�� z servera (przez ban)
	unsigned int channelCreated = 0; //ilo�� utworzonych kana��w
	unsigned int channelSubCreated = 0; //ilo�� utworzonych kana��w
	unsigned int channelModified = 0; //ilo�� zmodyfiikowanych kana��w
	unsigned int channelDeleted = 0; //ilo�� usuni�tych kana��w
	unsigned int bans = 0; //ilo�� danych ban�w
	unsigned int bansDeleted = 0; //ilo�� usunietych ban�w
	unsigned int complaint = 0; //ilo�� otrzymanych complain�w
	unsigned int fileUploaded = 0; //ilo�� zuploadowanych plik�w
	unsigned int fileDownloaded = 0; //ilo�� pobranych plik�w
	unsigned int fileDeleted = 0; //ilo�� usuni�tych plik�w
	unsigned int fileMoved = 0; //ilo�� przeniesionych/zmian nazwy plik�w
	unsigned int fileDirectory = 0; //ilo�� operacji na folderach plik�w
	unsigned int permissionModified = 0; //ilo�� modyfikacji uprawnie�
	unsigned int clientGroupModified = 0; //ilo�� wykonanych modyfikacji grupy
};