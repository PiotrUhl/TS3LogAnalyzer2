#pragma once

class Line; //Line
class LineInfo; //LineInfo
#include "RecordType.hpp"
#include "RegexDictionary.h"

#include <ctime>

class RegexDictionary;

class LineInterpreter {
	RegexDictionary dictionary; //s³ownik wyra¿eñ regularnych
public:
	//interpretuje linie
	LineInfo interpretLine(const Line& line) const;
	//odczytuje znacznik czasowy linii
	time_t getTime(const Line& line, bool skipValidation = false) const;
	//sprawdza rodzaj wpisu w linii
	RecordType checkRecordType(const Line& line) const;
private:
	//sprawdza poprawnoœæ pocz¹tkowej czêœci lini
	bool checkLine(const Line& line) const;
	//próbuje naprawiæ niepoprawn¹ liniê
	Line fixLine(const Line& line) const;
	//tworzy objekt LineInfo z podanych danych
	LineInfo makeLineInfo(time_t time, RecordType type, const Line& line);
};

