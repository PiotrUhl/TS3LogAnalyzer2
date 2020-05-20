#include "Line.h"

//getter line
std::string Line::getLine() const {
	return line;
}

//getter file
std::string Line::getFile() const {
	return file;
}

//getter endOfLog
bool Line::endOfLog() const {
	return eol;
}
