#include "LineInterpreter.h"
#include "Line.h"
#include "LineInfo.h"
#include <regex>

//sprawdza poprawnoœæ pocz¹tkowej czêœci lini
bool LineInterpreter::checkLine(const Line& line) const {
	return std::regex_match(line.getLine(), std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|.*)"));
}

//próbuje naprawiæ niepoprawn¹ liniê
Line LineInterpreter::fixLine(const Line& line) const {
	std::smatch match;
	std::string str = line.getLine();
	if (std::regex_search(str, match, std::regex(R"(\d\d\d\d-\d\d-\d\d \d\d:\d\d:\d\d.(\d){6}\|.*)")) == false) {
		throw std::invalid_argument("Not a correct line (date validation failed) - fixing failed!");
	}
	else {
		return Line(line.getFile(), line.getNumber(), match[0]);
	}
}
//tworzy objekt LineInfo z podanych danych
LineInfo LineInterpreter::makeLineInfo(time_t time, RecordType type, const Line& line) const {
	LineInfo lineInfo(type, time);
	auto map = dictionary.getDataMap(); //pobiera s³ownik regexów
	auto dataAccessInfo = map.at(type); //wyci¹ga wpis dla danego typu
	std::string str = line.getLine();
	std::smatch result; 
	std::regex_search(str, result, dataAccessInfo.first); //pobiera wszystkie dane z linii do smatch

	auto indexDirectory = dataAccessInfo.second; //tablica umo¿liwiaj¹ca rozpoznanie danych w smatch
	for (int i = 0; i < indexDirectory.size(); i++) {
		if (indexDirectory[i] != LineData::NONE)
			lineInfo.setData(indexDirectory[i], result[i]); //informacja pod danym indeksem wyniku regexa jest dan¹ rodzaju opisanego pod tym samym indeksem w tablicy indexDirectory
	}
	return lineInfo;
}

//interpretuje linie
LineInfo LineInterpreter::interpretLine(const Line& line) const {
	if (!checkLine(line)) {
		//log: invalid line, trying fix
		Line fixedLine = fixLine(line);
		//log: line fixed
		return interpretLine(fixedLine);
	}
	time_t time = getTime(line, true);
	RecordType type = checkRecordType(line);
	if (type == RecordType::UNIDENTIFIED) //typ nierozmoznany
		return LineInfo(type, time);
	return makeLineInfo(time, type, line);
}

//odczytuje znacznik czasowy linii
time_t LineInterpreter::getTime(const Line& line, bool skipValidation) const {
	if (!skipValidation) {
		if (!checkLine(line)) {
			//log: invalid line, trying fix
			Line fixedLine = fixLine(line);
			//log: line fixed
			return getTime(fixedLine);
		}
	}
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
	_get_timezone(&timezone); //ró¿nica miêdzy czasem lokalnym a uniwersalnym
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
