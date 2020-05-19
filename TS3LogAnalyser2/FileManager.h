#pragma once
#include <string> //std::string

class Line; //Line

class FileManager {
	std::string basePath; //bazowa �cie�ka plik�w log�w
public:
	//konstruktor
	FileManager(const std::string& _basePath);
	//pobiera i zwraca nast�pn� lini� z pliku
	Line getLine();
	//informuje czy ostatnia pobrana linia by�a ostatni� lini� pliku (nast�pna b�dzie z nowego pliku)
	bool endOfFile();
	//informuje czy pobrano ju� wszystkie linie z wszystkich plik�w
	bool endOfLog();
};

