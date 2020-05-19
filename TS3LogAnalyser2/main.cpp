#include <iostream>
#include <windows.h>
#include <vector>

#include "UserData.h"
#include "ServerData.h"
#include "Log.h"

int main() {

	std::vector<UserData> userData; //statystyki u¿ytkowników serwera
	ServerData serverData; //statystyki serwera
	unsigned int unknownLine = 0; // iloœæ niezidentyfikowanych linii;

	FileManager fileManager; //mened¿er plików
	LineInterpreter lineInterpreter; //interpreter linii
	UserDataUpdater userDataUpdater(userData); //aktualizator statystyk u¿ytkownika
	ServerDataUpdater serverDataUpdater(serverData); //aktualizator statystyk serwera
	for (Line line = fileManager.getLine(); line.endOfLog() == false; line = fileManager.getLine()) { //dla ka¿dej linii w ka¿dym pliku
		LineInfo lineInfo = lineInterpreter.interpretLine(line); //interpretacja linii
		userDataUpdater(lineInfo); //aktualizacja statystyk u¿ytkowników o informacje z odczytanej linii
		serverDataUpdater(lineInfo); //aktualizacja statystyk serwera o informacje z odczytanej linii
	}
	
	//zapis wyników

	return 0;
}