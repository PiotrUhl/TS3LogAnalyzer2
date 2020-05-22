#include "FileManager.h"
#include "Line.h"
#include <iostream> //debug
#include <fstream> //std::ifstream

//konstruktor
FileManager::FileManager(const std::string& _basePath) : basePath(_basePath), lineNr(0), eol(false) {
	std::string searchPath = basePath + "\\ts3server_*_1.log";
	hFile = FindFirstFile(searchPath.c_str(), &fileData);
	currentFile = basePath + fileData.cFileName;
	readFile(currentFile);
}

//destruktor
FileManager::~FileManager() {
	FindClose(hFile);
}

//pobiera i zwraca nastêpn¹ liniê z pliku
Line FileManager::getLine() {
	while (true) {
		if (!fileLines.empty()) { //je¿eli s¹ elementy w buforze
			std::string ret = fileLines.front();
			fileLines.pop_front();
			return Line(fileData.cFileName, ++lineNr, ret);
		}
		else {
			if (FindNextFile(hFile, &fileData) == 0) { //je¿eli nie znaleziono kolejnego pliku
				eol = true; //ustaw flagê koniec logów
				return Line("", 0, "", true); //zwróæ koniec logów
			}
			else {
				currentFile = basePath + fileData.cFileName;
				lineNr = 0;
				readFile(currentFile);
			}
		}
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

//pobiera zawartoœæ pliku do fileLines
void FileManager::readFile(const std::string& filePath) {
	std::ifstream file(filePath.c_str());
	if (!file.good()) {
		throw std::runtime_error("Cannot open file " + filePath);
	}
	while (!file.eof()) {
		std::string line;
		std::getline(file, line); //odczytaj liniê
		if (line.length() > 0)
			fileLines.push_back(line);
	}
	file.close();
}
