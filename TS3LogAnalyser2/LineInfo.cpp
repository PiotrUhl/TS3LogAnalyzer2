#include "LineInfo.h"
#include <limits>
#include <stdexcept>

#define ulong unsigned long

//ustawia dan¹ pod podanym indeksem
void LineInfo::setData(LineData index, std::string data) {
	dataMap.insert_or_assign(index, data);
}

//zwraca typ rekordu
RecordType LineInfo::getType() const {
	return recordType;
}

//zwraca czas rekordu
time_t LineInfo::getTime() const {
	return time;
}

//zwraca dan¹ spod adresu LineData o okreœlonym type (std::invalid_argument jeœli niedostêpne; std::logic_error je¿eli z³y typ)
uint LineInfo::getInt(LineData index) const {
	std::string data = dataMap.at(index);
	if (data.empty())
		throw std::invalid_argument("LineInfo::getInt(): No data at given index");
	try {
		return std::stoi(data);
	}
	catch (const std::invalid_argument&) {
		throw std::invalid_argument("LineInfo::getInt(): Data at given position isn't an int");
	}
	catch (const std::out_of_range&) {
		throw std::invalid_argument("LineInfo::getInt(): Data at given position isn't out of int range");
	}
}
uint LineInfo::getUint(LineData index) const {
	std::string data = dataMap.at(index);
	if (data.empty())
		throw std::invalid_argument("LineInfo::getUint(): No data at given index");
	try {
		ulong temp = std::stoul(data);
		if (/*temp < std::numeric_limits<uint>::min() || */temp > std::numeric_limits<uint>::max())
			throw std::invalid_argument("LineInfo::getUint(): Data at given position isn't out of unsigned int range");
		return static_cast<uint>(temp);
	}
	catch (const std::invalid_argument&) {
		throw std::invalid_argument("LineInfo::getUint(): Data at given position isn't an unsigned int");
	}
	catch (const std::out_of_range&) {
		throw std::invalid_argument("LineInfo::getUint(): Data at given position isn't out of unsigned int range");
	}
}
std::string LineInfo::getString(LineData index) const {
	std::string data = dataMap.at(index);
	if (data.empty())
		throw std::invalid_argument("LineInfo::getString(): No data at given index");
	return data;
}
std::string LineInfo::getIp(LineData index) const {
	std::string data = dataMap.at(index);
	if (data.empty())
		throw std::invalid_argument("LineInfo::getIp(): No data at given index");
	return data;
}
short LineInfo::getShort(LineData index) const {
	std::string data = dataMap.at(index);
	if (data.empty())
		throw std::invalid_argument("LineInfo::getUint(): No data at given index");
	try {
		int temp = std::stoi(data);
		if (temp < std::numeric_limits<short>::min() || temp > std::numeric_limits<short>::max())
			throw std::invalid_argument("LineInfo::getUint(): Data at given position isn't out of short int range");
		return static_cast<uint>(temp);
	}
	catch (const std::invalid_argument&) {
		throw std::invalid_argument("LineInfo::getUint(): Data at given position isn't an short int");
	}
	catch (const std::out_of_range&) {
		throw std::invalid_argument("LineInfo::getUint(): Data at given position isn't out of short int range");
	}
}
ushort LineInfo::getUshort(LineData index) const {
	std::string data = dataMap.at(index);
	if (data.empty())
		throw std::invalid_argument("LineInfo::getUint(): No data at given index");
	try {
		ulong temp = std::stoul(data);
		if (/*temp < std::numeric_limits<ushort>::min() || */temp > std::numeric_limits<ushort>::max())
			throw std::invalid_argument("LineInfo::getUint(): Data at given position isn't out of unsigned short int range");
		return static_cast<uint>(temp);
	}
	catch (const std::invalid_argument&) {
		throw std::invalid_argument("LineInfo::getUint(): Data at given position isn't an unsigned short int");
	}
	catch (const std::out_of_range&) {
		throw std::invalid_argument("LineInfo::getUint(): Data at given position isn't out of unsigned short int range");
	}
}