#pragma once

class Line; //Line
class LineInfo; //LineInfo
#include "RecordType.hpp"

class LineInterpreter {
public:
	//interpretuje linie
	LineInfo interpretLine(Line line) const;
	//sprawdza rodzaj wpisu w linii
	RecordType checkRecordType(Line line) const;
};

