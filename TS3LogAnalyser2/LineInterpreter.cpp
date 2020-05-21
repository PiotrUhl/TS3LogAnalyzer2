#include "LineInterpreter.h"
#include "Line.h"
#include "LineInfo.h"
#include <regex>

//interpretuje linie
std::unique_ptr<LineInfo> LineInterpreter::interpretLine(const Line& line) const {
	if (!std::regex_match(line.getLine(), std::regex("\\d\\d\\d\\d-\\d\\d-\\d\\d \\d\\d:\\d\\d:\\d\\d.(\\d){6}\\|.*")))
		throw std::invalid_argument("Not a correct line (date validation failed)!");
	return std::make_unique<LineInfo>(RecordType::UNIDENTIFIED, getTime(line, true));
}

//odczytuje znacznik czasowy linii
time_t LineInterpreter::getTime(const Line& line, bool skipValidation) const {
	if (!skipValidation)
		if (!std::regex_match(line.getLine(), std::regex("\\d\\d\\d\\d-\\d\\d-\\d\\d \\d\\d:\\d\\d:\\d\\d.(\\d){6}\\|.*")))
			throw std::invalid_argument("Not a correct line (validation failed)!");
	std::tm tm;
	tm.tm_isdst = 0;
	try {
		tm.tm_year = std::stoi(line.getLine().substr(0, 4)) - 1900;
		tm.tm_mon = std::stoi(line.getLine().substr(5, 2));
		tm.tm_mday = std::stoi(line.getLine().substr(8, 2));
		tm.tm_hour = std::stoi(line.getLine().substr(11, 2));
		tm.tm_min = std::stoi(line.getLine().substr(14, 2));
		tm.tm_sec = std::stoi(line.getLine().substr(17, 2));
	}
	catch (const std::logic_error&) {
		throw std::invalid_argument("Not a correct line (date conversion failed)!");
	}
	long timezone;
	_get_timezone(&timezone); //pobieranie ró¿nicy miêdzy czasem lokalnym a uniwersalnym
	return mktime(&tm) - timezone;
}

//sprawdza rodzaj wpisu w linii
RecordType LineInterpreter::checkRecordType(const Line& line) const {
	auto map = dictionary.getIdentMap();
	for (auto k : map) {
		if (std::regex_match(line.getLine(), k.second)) {
			return k.first;
		}
	}
	return RecordType::UNIDENTIFIED;
}
