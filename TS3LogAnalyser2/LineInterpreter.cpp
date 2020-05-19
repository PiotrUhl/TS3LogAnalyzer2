#include "LineInterpreter.h"
#include "Line.h"
#include "LineInfo.h"


//interpretuje linie
LineInfo LineInterpreter::interpretLine(Line line) const {
	return LineInfo(RecordType::UNIDENTIFIED, 0);
}

//sprawdza rodzaj wpisu w linii
RecordType LineInterpreter::checkRecordType(Line line) const {
	return RecordType();
}
