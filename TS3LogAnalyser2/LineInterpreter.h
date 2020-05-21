#pragma once

class Line; //Line
class LineInfo; //LineInfo
#include "RecordType.hpp"
#include <memory>
#include <ctime>

class LineInterpreter {
public:
	//interpretuje linie
	std::unique_ptr<LineInfo> interpretLine(const Line& line) const;
	//odczytuje znacznik czasowy linii
	time_t getTime(const Line& line) const;
	//sprawdza rodzaj wpisu w linii
	RecordType checkRecordType(const Line& line) const;
};

