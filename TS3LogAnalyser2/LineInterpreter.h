#pragma once
#include <stdexcept>

class Line; //Line
class LineInfo; //LineInfo
#include "RecordType.hpp"

class LineInterpreter {
public:
	//interpretuje linie
	LineInfo interpretLine(Line line) const;
	//sprawdza rodzaj wpisu w linii
	RecordType checkRecordType(Line line) const;

	//wyj¹tek niezidentyfikowanej linii
	class UnidentifiedLineException : public std::runtime_error {
		std::string _line; //unidentified line
	public:
		//returns unidentified line
		std::string line();
	};
};