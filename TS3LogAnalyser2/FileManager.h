#pragma once
#include <string> //std::string
#include <windows.h> //WIN32_FIND_DATA, HANDLE
#include <list> //std::list
#include <string> //std::string

class Line; //Line

class FileManager {
	WIN32_FIND_DATA fileData; //dane aktualnego pliku
	HANDLE hFile; //uchwyt na aktualny plik
	std::list<std::string> fileLines; //pobrane linie aktualnego pliku
	std::string basePath; //bazowa �cie�ka plik�w log�w
	std::string currentFile; //obecnie otwarty plik
	unsigned int lineNr; //numer ostatniej odczytanej linii
	bool eol; //pobrano ju� wszystkie linie z wszystkich plik�w
public:
	//konstruktor
	FileManager(const std::string& _basePath);
	//destruktor
	~FileManager();
	//pobiera i zwraca nast�pn� lini� z pliku
	Line getLine();
	//zwraca �cie�k� obecnie otwartego pliku
	std::string getFilePath() const;
	//zwraca nazw� obecnie otwartego pliku
	std::string getFileName() const;
	//zwraca numer ostatniej odczytanej linii
	unsigned int getLineNr() const;
	//informuje czy pobrano ju� wszystkie linie z wszystkich plik�w
	bool endOfLog() const;
private:
	//pobiera zawarto�� pliku do fileLines
	void readFile(const std::string& filePath);
};