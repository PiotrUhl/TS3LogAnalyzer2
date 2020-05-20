#pragma once
#include <string>

//reprezentacja pojedyñczej linii odczytanej z pliku
class Line {
	std::string file; //nazwa pliku z którego pochodzi linia
	unsigned int number; //numer linii w pliku
	std::string line; //odczytana linia
	bool eol; //koniec logów
public:
	//konstruktory i operatory przypisania
	Line(const std::string& _file, unsigned int _number, const std::string & _line, bool eol = false) : file(_file), number(_number), line(_line), eol(eol) {}
	Line(const Line& _) = default;
	Line(Line&& _) = default;
	Line& operator=(const Line&) = default;
	Line& operator=(Line&&) = default;
	
	//getter line
	std::string getLine() const;
	//getter file
	std::string getFile() const;
	//getter number
	unsigned int getNumber() const;
	//getter endOfLog
	bool endOfLog() const;
};

