#pragma once

class Line; //Line
class LineInfo; //LineInfo
#include "RecordType.hpp"
#include <memory>

class LineInterpreter {
public:
	//interpretuje linie
	std::unique_ptr<LineInfo> interpretLine(Line line) const;
	//sprawdza rodzaj wpisu w linii
	RecordType checkRecordType(Line line) const;
};

