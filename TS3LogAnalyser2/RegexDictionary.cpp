#include "RegexDictionary.h"

//zwraca s�ownik regex�w identyfikuj�cych
const std::map<RecordType, std::regex>& RegexDictionary::getIdentMap() const {
	return idents;
}
