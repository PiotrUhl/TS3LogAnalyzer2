#include <iostream>
#include <windows.h>
#include <vector>

#include "UserData.hpp"
#include "ServerData.hpp"
#include "Log.h"
#include "FileManager.h"
#include "LineInterpreter.h"

int main() {

	std::string basePath; //bazowa �cie�ka z plikami log�w

	std::vector<UserData> userData; //statystyki u�ytkownik�w serwera
	ServerData serverData; //statystyki serwera
	unsigned int unknownLine = 0; // ilo�� niezidentyfikowanych linii;




	FileManager fileManager(basePath); //mened�er plik�w
	LineInterpreter lineInterpreter; //interpreter linii
	UserDataUpdater userDataUpdater(userData); //aktualizator statystyk u�ytkownika
	ServerDataUpdater serverDataUpdater(serverData); //aktualizator statystyk serwera
	for (Line line = fileManager.getLine(); line.endOfLog() == false; line = fileManager.getLine()) { //dla ka�dej linii w ka�dym pliku
		LineInfo lineInfo = lineInterpreter.interpretLine(line); //interpretacja linii
		userDataUpdater(lineInfo); //aktualizacja statystyk u�ytkownik�w o informacje z odczytanej linii
		serverDataUpdater(lineInfo); //aktualizacja statystyk serwera o informacje z odczytanej linii
	}
	
	//zapis wynik�w

	return 0;
}