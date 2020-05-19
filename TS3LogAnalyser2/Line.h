#pragma once
#include <string>

//reprezentacja pojedyñczej linii odczytanej z pliku
class Line {
public:
	const std::string line; //odczytana linia
	const bool endOfFile; //koniec pliku
	const bool endOfLog; //koniec logów
	
	//konstruktory i operatory przypisania
	Line(const std::string & _line, bool _endOfFile, bool _endOfLog) : line(_line), endOfFile(_endOfFile), endOfLog(_endOfLog) {}
	Line(const Line& _) : line(_.line), endOfFile(_.endOfFile), endOfLog(_.endOfLog) {}
	Line(Line&& _) : line(_.line), endOfFile(_.endOfFile), endOfLog(_.endOfLog) {}
	Line& operator=(const Line&);
	Line& operator=(Line&&);
	
	//getter line
	std::string getLine() const;
	//getter endOfFile
	bool endOfFile() const;
	//getter endOfLog
	bool endOfLog() const;
};

