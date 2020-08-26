#include "RegexDictionary.h"

//zwraca s�ownik regex�w identyfikuj�cych
const std::map<RecordType, std::regex>& RegexDictionary::getIdentMap() const {
	return identMap;
}

//zwraca s�ownik regex�w wyci�gaj�cych dane
const std::map<RecordType, std::pair<std::regex, std::vector<LineData>>>& RegexDictionary::getDataMap() const {
	return dataMap;
}
