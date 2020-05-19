#include "Line.h"

//getter line
std::string Line::getLine() const {
	return line;
}

//getter endOfFile
bool Line::endOfFile() const {
	return isEndOfFile;
}

//getter endOfLog
bool Line::endOfLog() const {
	return isEndOfLog;
}
