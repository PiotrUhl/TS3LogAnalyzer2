#include "LineInterpreter.h"
#include "Line.h"
#include "LineInfo.h"

//interpretuje linie
std::unique_ptr<LineInfo> LineInterpreter::interpretLine(Line line) const {
	return std::make_unique<LineInfo>(RecordType::UNIDENTIFIED, 0);
}

//sprawdza rodzaj wpisu w linii
RecordType LineInterpreter::checkRecordType(Line line) const {
	return RecordType();
}
