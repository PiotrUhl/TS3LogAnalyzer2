#include "LineInfo.h"

//zwraca typ rekordu
RecordType LineInfo::getType() const {
	return recordType;
}

//zwraca czas rekordu
time_t LineInfo::getTime() const {
	return time;
}
