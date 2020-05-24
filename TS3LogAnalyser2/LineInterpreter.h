#pragma once

class Line; //Line
class LineInfo; //LineInfo
#include "RecordType.hpp"
#include "RegexDictionary.h"
#include "LineInfoFactory.h"

#include <memory>
#include <ctime>

class RegexDictionary;

class LineInterpreter {
	RegexDictionary dictionary; //s³ownik wyra¿eñ regularnych
	LineInfoFactory factory; //fabryka klas LineInfo
public:
	//interpretuje linie
	std::unique_ptr<LineInfo> interpretLine(const Line& line) const;
	//odczytuje znacznik czasowy linii
	time_t getTime(const Line& line, bool skipValidation = false) const;
	//sprawdza rodzaj wpisu w linii
	RecordType checkRecordType(const Line& line) const;
private:
	//sprawdza poprawnoœæ pocz¹tkowej czêœci lini
	bool checkLine(const Line& line) const;
	//próbuje naprawiæ niepoprawn¹ liniê
	Line fixLine(const Line& line) const;
};

