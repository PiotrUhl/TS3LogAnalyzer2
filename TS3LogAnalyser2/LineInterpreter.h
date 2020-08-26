#pragma once

class Line; //Line
class LineInfo; //LineInfo
#include "RecordType.hpp"
#include "RegexDictionary.h"

#include <ctime>

class RegexDictionary;

class LineInterpreter {
	RegexDictionary dictionary; //s�ownik wyra�e� regularnych
public:
	//interpretuje linie
	LineInfo interpretLine(const Line& line) const;
	//odczytuje znacznik czasowy linii
	time_t getTime(const Line& line, bool skipValidation = false) const;
	//sprawdza rodzaj wpisu w linii
	RecordType checkRecordType(const Line& line) const;
private:
	//sprawdza poprawno�� pocz�tkowej cz�ci lini
	bool checkLine(const Line& line) const;
	//pr�buje naprawi� niepoprawn� lini�
	Line fixLine(const Line& line) const;
	//tworzy objekt LineInfo z podanych danych
	LineInfo makeLineInfo(time_t time, RecordType type, const Line& line);
};

