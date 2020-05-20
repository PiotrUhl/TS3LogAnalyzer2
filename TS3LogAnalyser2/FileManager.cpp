#include "FileManager.h"
#include "Line.h"
#include <iostream> //debug

//konstruktor
FileManager::FileManager(const std::string& _basePath) : basePath(_basePath), lineNr(0), eol(false) {
	std::string searchPath = basePath + "\\ts3server_*_1.log";
	hFile = FindFirstFile(searchPath.c_str(), &fileData);
	currentFile = basePath + fileData.cFileName;
	file.open(currentFile.c_str());
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
				return Line("", 0, "", true); //zwróæ koniec logów
			}
			else {
				currentFile = basePath + fileData.cFileName;
				file.open(currentFile.c_str()); //otwórz nastêpny plik
				lineNr = 0;
				if (!file.good()) {
					throw std::runtime_error("Cannot open file " + basePath + fileData.cFileName);
				}
			}
		}
		else
			return Line(fileData.cFileName, ++lineNr, ret);
	}
}

//zwraca œcie¿kê obecnie otwartego pliku
std::string FileManager::getFilePath() const {
	return currentFile;	
}

//zwraca nazwê obecnie otwartego pliku
std::string FileManager::getFileName() const {
	return std::string(fileData.cFileName);
}

//zwraca numer ostatniej odczytanej linii
unsigned int FileManager::getLineNr() const {
	return lineNr;
}

//informuje czy pobrano ju¿ wszystkie linie z wszystkich plików
bool FileManager::endOfLog() const {
	return eol;
}
