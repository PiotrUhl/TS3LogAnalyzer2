#pragma once
#include <string> //std::string

class Line; //Line

class FileManager {
	std::string basePath; //bazowa œcie¿ka plików logów
public:
	//konstruktor
	FileManager(const std::string& _basePath);
	//pobiera i zwraca nastêpn¹ liniê z pliku
	Line getLine();
	//informuje czy ostatnia pobrana linia by³a ostatni¹ lini¹ pliku (nastêpna bêdzie z nowego pliku)
	bool endOfFile();
	//informuje czy pobrano ju¿ wszystkie linie z wszystkich plików
	bool endOfLog();
};

