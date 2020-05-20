#pragma once
#include <string> //std::string
#include <windows.h> //WIN32_FIND_DATA, HANDLE
#include <fstream> //std::ifstream
#include <string> //std::string

class Line; //Line

class FileManager {
	WIN32_FIND_DATA fileData; //dane aktualnego pliku
	HANDLE hFile; //uchwyt na aktualny plik
	std::ifstream file; //aktualny strumie� plikowy
	std::string basePath; //bazowa �cie�ka plik�w log�w
	std::string currentFile; //obecnie otwarty plik
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
	//informuje czy pobrano ju� wszystkie linie z wszystkich plik�w
	bool endOfLog() const;
};