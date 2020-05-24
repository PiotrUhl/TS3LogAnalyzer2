#include "LineInfoFactory.h"
#include "LineInfo1id1name.h"
#include "LineInfo1id1name1ip.h"
#include <regex>

//tworzy odpowieni¹ podklasê LineInfo dla danego rekordu
std::unique_ptr<LineInfo> LineInfoFactory::create(RecordType type, time_t time, const Line& line) const {
	switch (type) {
	case RecordType::CLIENT_CONNECTED:
		return make1id1name1ip(type, time, line);
	}
	return std::make_unique<LineInfo>(RecordType::UNIDENTIFIED, 0);
}

//tworzy podklasê LineInfo dla jednego id i jednej nazwy
std::unique_ptr<LineInfo> LineInfoFactory::make1id1name1ip(RecordType type, time_t time, const Line & line) const {
	return std::make_unique<LineInfo1id1name1ip>(type, time, getId(line), getNickname(line), getIp(line), getPort(line));
}

//wyci¹ga id z linii
unsigned int LineInfoFactory::getId(const Line& line, unsigned int nr) const {
	std::regex getIdRegex(R"(\(id:\d+\))");
	std::smatch match;
	const std::string& temp = line.getLine();
	if (std::regex_search(temp, match, getIdRegex)) {
		return std::stoi(match[0].str().substr(4, match[0].str().find(')') - 4));
	}
}

//wyci¹ga nickname z linii
std::string LineInfoFactory::getNickname(const Line & line, unsigned int nr) const {
	std::regex getNicknameRegex(R"('.*'\(id:\d+\))");;
	std::smatch match;
	const std::string& temp = line.getLine();
	if (std::regex_search(temp, match, getNicknameRegex)) {
		return match[0].str().substr(1, match[0].str().find('\'', 1) - 1);
	}
}

//wyci¹ga ip z linii
std::string LineInfoFactory::getIp(const Line& line, unsigned int nr) const {
	std::regex getIpRegex(R"(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}:\d{1,5})");
	std::smatch match;
	const std::string& temp = line.getLine();
	if (std::regex_search(temp, match, getIpRegex)) {
		return match[0].str().substr(0, match[0].str().find(':'));
	}
}

//wyci¹ga port z linii
unsigned short int LineInfoFactory::getPort(const Line& line, unsigned int nr) const {
	std::regex getIpRegex(R"(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}:\d{1,5})");
	std::smatch match;
	const std::string& temp = line.getLine();
	if (std::regex_search(temp, match, getIpRegex)) {
		std::string str = match[0].str().substr(match[0].str().find(':') + 1); //debug
		return std::stoi(str);
	}
}