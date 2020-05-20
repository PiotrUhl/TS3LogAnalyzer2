#include <iostream>
#include <windows.h>
#include <vector>

#include "UserData.hpp"
#include "ServerData.hpp"
#include "Log.h"
#include "FileManager.h"
#include "LineInterpreter.h"
#include "UserDataUpdater.h"
#include "ServerDataUpdater.h"
#include "Line.h"
#include "LineInfo.h"
#include "RecordType.hpp"

int main() {

	std::string basePath = "D:\\Piotr\\Folder\\Server\\logs\\"; //bazowa �cie�ka z plikami log�w

	std::vector<UserData> userData; //statystyki u�ytkownik�w serwera
	ServerData serverData; //statystyki serwera
	unsigned int unknownLines = 0; // ilo�� niezidentyfikowanych linii;

	FileManager fileManager(basePath); //mened�er plik�w
	LineInterpreter lineInterpreter; //interpreter linii
	UserDataUpdater userDataUpdater(userData); //aktualizator statystyk u�ytkownika
	ServerDataUpdater serverDataUpdater(serverData); //aktualizator statystyk serwera
	for (Line line = fileManager.getLine(); line.endOfLog() == false; line = fileManager.getLine()) { //dla ka�dej linii w ka�dym pliku
		if (line.getNumber() == 1)
			std::cout << fileManager.getFileName() << '\n';
		LineInfo lineInfo = lineInterpreter.interpretLine(line); //interpretacja linii
		if (lineInfo.getType() == RecordType::UNIDENTIFIED)
			unknownLines++;
		else {
			userDataUpdater.update(lineInfo); //aktualizacja statystyk u�ytkownik�w o informacje z odczytanej linii
			serverDataUpdater.update(lineInfo); //aktualizacja statystyk serwera o informacje z odczytanej linii
		}
	}
	
	//zapis wynik�w

	std::cout << "Unknown lines: " << unknownLines << std::endl; //debug

	return 0;
}