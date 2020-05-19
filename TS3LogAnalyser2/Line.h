#pragma once
#include <string>

//reprezentacja pojedyñczej linii odczytanej z pliku
class Line {
	std::string line; //odczytana linia
	bool isEndOfFile; //koniec pliku
	bool isEndOfLog; //koniec logów
public:
	//konstruktory i operatory przypisania
	Line(const std::string & _line, bool _endOfFile, bool _endOfLog) : line(_line), isEndOfFile(_endOfFile), isEndOfLog(_endOfLog) {}
	Line(const Line& _) = default;
	Line(Line&& _) = default;
	Line& operator=(const Line&) = default;
	Line& operator=(Line&&) = default;
	
	//getter line
	std::string getLine() const;
	//getter endOfFile
	bool endOfFile() const;
	//getter endOfLog
	bool endOfLog() const;
};

