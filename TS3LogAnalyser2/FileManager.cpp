#include "FileManager.h"
#include "Line.h"
#include <string>
//konstruktor
FileManager::FileManager(const std::string& _basePath) : basePath(_basePath) {
	
}

//pobiera i zwraca nast�pn� lini� z pliku
Line FileManager::getLine() {
	return Line("");
}
//informuje czy ostatnia pobrana linia by�a ostatni� lini� pliku (nast�pna b�dzie z nowego pliku)
bool FileManager::endOfFile() {
	return false;
}

//informuje czy pobrano ju� wszystkie linie z wszystkich plik�w
bool FileManager::endOfLog() {
	return false;
}
