#include "Line.h"

//operator przypisania
Line& Line::operator=(const Line& _) {
	Line ret(_);
	return ret;
}
Line& Line::operator=(Line&& _) {
	Line ret(_);
	return ret;
}

//getter line
std::string Line::getLine() const {
	return line;
}

//getter endOfFile
bool Line::endOfFile() const {
	return endOfFile;
}

bool Line::endOfLog() const {
	return endOfLog;
}
