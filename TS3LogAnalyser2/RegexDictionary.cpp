#include "RegexDictionary.h"

//zwraca s³ownik regexów identyfikuj¹cych
const std::map<RecordType, std::regex>& RegexDictionary::getIdentMap() const {
	return idents;
}
