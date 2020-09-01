#define WIN32_LEAN_AND_MEAN

#include <iostream>
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

	//std::string basePath = "D:\\Piotr\\Folder\\Server\\logs\\"; //bazowa œcie¿ka z plikami logów
	//std::string basePath = "D:\\Piotr\\Folder\\Programowanie\\C++\\Wlasne\\TS3LogAnalyser2\\logs\\"; //bazowa œcie¿ka z plikami logów
	//std::string basePath = R"(C:\Users\uhlp\source\repos\TS3LogAnalyzer2\logs\)"; //bazowa œcie¿ka z plikami logów
	std::string basePath = R"(C:\Users\uhlp\source\repos\TS3LogAnalyzer2\logs_sel\)"; //bazowa œcie¿ka z plikami logów
	//std::string basePath = R"(C:\Users\uhlp\source\repos\TS3LogAnalyzer2\logs_sel_sel\)"; //bazowa œcie¿ka z plikami logów

	std::vector<UserData> userData; //statystyki u¿ytkowników serwera
	ServerData serverData; //statystyki serwera
	unsigned int unknownLines = 0; // iloœæ niezidentyfikowanych linii
	unsigned int exceptions = 0; //iloœæ wyrzuconych wyj¹tków, wy³apanych dopiero w funckcji main()

	FileManager fileManager(basePath); //mened¿er plików
	LineInterpreter lineInterpreter; //interpreter linii
	UserDataUpdater userDataUpdater(userData); //aktualizator statystyk u¿ytkownika
	ServerDataUpdater serverDataUpdater(serverData); //aktualizator statystyk serwera
	for (Line line = fileManager.getLine(); line.endOfLog() == false; line = fileManager.getLine()) { //dla ka¿dej linii w ka¿dym pliku
		if (line.getNumber() == 1)
			std::cout << fileManager.getFileName() << '\n';
		try {
			LineInfo lineInfo = lineInterpreter.interpretLine(line); //interpretacja linii
			if (lineInfo.getType() == RecordType::UNIDENTIFIED)
				unknownLines++;
			else {
				userDataUpdater.update(lineInfo); //aktualizacja statystyk u¿ytkowników o informacje z odczytanej linii
				serverDataUpdater.update(lineInfo); //aktualizacja statystyk serwera o informacje z odczytanej linii
			}
		}
		catch (const std::exception& exc) {
			std::cerr << "Exception thrown at line:\n" << line.getLine() << "\n" << typeid(exc).name() << ": \"" << exc.what() << "\"\n";
			exceptions++;
			unknownLines++;
		}

	}
	
	//zapis wyników

	std::cout << "Unknown lines: " << unknownLines << std::endl; //debug

	return 0;
}