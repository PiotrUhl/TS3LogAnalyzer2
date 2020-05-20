#pragma once
#include <string> //std::string
#include <windows.h> //WIN32_FIND_DATA, HANDLE
#include <fstream> //std::ifstream
#include <string> //std::string

class Line; //Line

class FileManager {
	WIN32_FIND_DATA fileData; //dane aktualnego pliku
	HANDLE hFile; //uchwyt na aktualny plik
	std::ifstream file; //aktualny strumieñ plikowy
	std::string basePath; //bazowa œcie¿ka plików logów
	std::string currentFile; //obecnie otwarty plik
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
	//informuje czy pobrano ju¿ wszystkie linie z wszystkich plików
	bool endOfLog() const;
};