#pragma once

class Line; //Line
class LineInfo; //LineInfo
#include "RecordType.hpp"
#include "RegexDictionary.h"
#include <memory>
#include <ctime>

class RegexDictionary;

class LineInterpreter {
	RegexDictionary dictionary; //s�ownik wyra�e� regularnych
public:
	//interpretuje linie
	std::unique_ptr<LineInfo> interpretLine(const Line& line) const;
	//odczytuje znacznik czasowy linii
	time_t getTime(const Line& line, bool skipValidation = false) const;
	//sprawdza rodzaj wpisu w linii
	RecordType checkRecordType(const Line& line) const;
};

