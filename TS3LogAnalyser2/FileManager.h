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
	std::string basePath; //bazowa œcie¿ka plików logów
	std::string currentFile; //obecnie otwarty plik
	unsigned int lineNr; //numer ostatniej odczytanej linii
	bool eol; //pobrano ju¿ wszystkie linie z wszystkich plików
public:
	//konstruktor
	FileManager(const std::string& _basePath);
	//destruktor
	~FileManager();
	//pobiera i zwraca nastêpn¹ liniê z pliku
	Line getLine();
	//zwraca œcie¿kê obecnie otwartego pliku
	std::string getFilePath() const;
	//zwraca nazwê obecnie otwartego pliku
	std::string getFileName() const;
	//zwraca numer ostatniej odczytanej linii
	unsigned int getLineNr() const;
	//informuje czy pobrano ju¿ wszystkie linie z wszystkich plików
	bool endOfLog() const;
private:
	//pobiera zawartoœæ pliku do fileLines
	void readFile(const std::string& filePath);
};