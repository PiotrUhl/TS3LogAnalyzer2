#include "IPaddress.h"
#include <sstream>
#include <regex>

IPaddress::IPaddress(const std::string& ipString) {
	_ip = parse(ipString);
}
IPaddress::IPaddress(const unsigned char* ipBytes) {
	for (int i = 0; i < 4; i++) {
		_ip[i] = ipBytes[i];
	}
}

std::string IPaddress::getString() {
	std::stringstream ss;
	ss << (short)_ip[3] << '.' << (short)_ip[2] << '.' << (short)_ip[1] << '.' << (short)_ip[0];
	return ss.str();
}
std::array<unsigned char, 4> IPaddress::getArray() {
	return _ip;
}

IPaddress& IPaddress::operator=(const std::string& ipString) {
	_ip = parse(ipString);
	return *this;
}
IPaddress& IPaddress::operator=(std::array<unsigned char, 4> ipArray) {
	_ip = ipArray;
	return *this;
}
IPaddress& IPaddress::operator=(const unsigned char* ipBytes) {
	for (int i = 0; i < 4; i++) {
		_ip[i] = ipBytes[i];
	}
	return *this;
}

std::array<unsigned char, 4> IPaddress::parse(const std::string& ipString) {
	std::array<unsigned char, 4> ret;
	std::regex ipRegex(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");
	std::smatch result;
	std::regex_search(ipString, result, ipRegex);
	if (result.empty())
		throw std::invalid_argument("Invalid IP address!");
	for (char i = 0; i < 4; i++) {
		unsigned short octet = stoi(result[4 - i]);
		if (octet > 255)
			throw std::out_of_range("Octet out of range!");
		ret[i] = static_cast<unsigned char>(octet);
	}
	return ret;
}