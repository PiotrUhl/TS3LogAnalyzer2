#include "RegexDictionary.h"

//zwraca s³ownik regexów identyfikuj¹cych
const std::map<RecordType, std::regex>& RegexDictionary::getIdentMap() const {
	return identMap;
}

//zwraca s³ownik regexów wyci¹gaj¹cych dane
const std::map<RecordType, std::pair<std::regex, std::vector<LineData>>>& RegexDictionary::getDataMap() const {
	return dataMap;
}
