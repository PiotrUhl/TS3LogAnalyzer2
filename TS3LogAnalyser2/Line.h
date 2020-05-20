#pragma once
#include <string>

//reprezentacja pojedyñczej linii odczytanej z pliku
class Line {
	std::string line; //odczytana linia
	bool eol; //koniec logów
public:
	//konstruktory i operatory przypisania
	Line(const std::string & _line, bool eol = false) : line(_line), eol(eol) {}
	Line(const Line& _) = default;
	Line(Line&& _) = default;
	Line& operator=(const Line&) = default;
	Line& operator=(Line&&) = default;
	
	//getter line
	std::string getLine() const;
	//getter endOfLog
	bool endOfLog() const;
};

