#include "FileManager.h"
#include "Line.h"
#include <string>
//konstruktor
FileManager::FileManager(const std::string& _basePath) : basePath(_basePath) {
	
}

//pobiera i zwraca nastêpn¹ liniê z pliku
Line FileManager::getLine() {
	return Line("");
}
//informuje czy ostatnia pobrana linia by³a ostatni¹ lini¹ pliku (nastêpna bêdzie z nowego pliku)
bool FileManager::endOfFile() {
	return false;
}

//informuje czy pobrano ju¿ wszystkie linie z wszystkich plików
bool FileManager::endOfLog() {
	return false;
}
