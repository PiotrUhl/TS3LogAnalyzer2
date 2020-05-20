#include "FileManager.h"
#include "Line.h"
#include <iostream> //debug

//konstruktor
FileManager::FileManager(const std::string& _basePath) : basePath(_basePath), eol(false) {
	std::string searchPath = basePath + "\\ts3server_*_1.log";
	hFile = FindFirstFile(searchPath.c_str(), &fileData);
	file.open(std::string(basePath+fileData.cFileName).c_str());
	if (!file.good()) {
		throw std::runtime_error("Cannot open file " + basePath + fileData.cFileName);
	}
}

//destruktor
FileManager::~FileManager() {
	FindClose(hFile);
	file.close();
}

//pobiera i zwraca nastêpn¹ liniê z pliku
Line FileManager::getLine() {
	std::string ret;
	while (true) {
		std::getline(file, ret); //odczytaj nastêpn¹ liniê
		if (file.eof()) { //je¿eli osi¹gniêto koniec pliku
			file.close(); //zamknij obecny plik
			if (FindNextFile(hFile, &fileData) == 0) { //je¿eli nie znaleziono kolejnego pliku
				eol = true; //ustaw flagê koniec logów
				return Line("", true); //zwróæ koniec logów
			}
			else {
				file.open(std::string(basePath + fileData.cFileName).c_str()); //otwórz nastêpny plik
				if (!file.good()) {
					throw std::runtime_error("Cannot open file " + basePath + fileData.cFileName);
				}
			}
		}
		else
			return Line(ret);
	}
}

//informuje czy pobrano ju¿ wszystkie linie z wszystkich plików
bool FileManager::endOfLog() {
	return eol;
}
