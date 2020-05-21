#include "LineInterpreter.h"
#include "Line.h"
#include "LineInfo.h"

//interpretuje linie
std::unique_ptr<LineInfo> LineInterpreter::interpretLine(const Line& line) const {
	return std::make_unique<LineInfo>(RecordType::UNIDENTIFIED, 0);
}

//odczytuje znacznik czasowy linii
time_t LineInterpreter::getTime(const Line& line) const {
	return 0;
}

//sprawdza rodzaj wpisu w linii
RecordType LineInterpreter::checkRecordType(const Line& line) const {
	return RecordType();
}
