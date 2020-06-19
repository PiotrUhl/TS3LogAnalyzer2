#include "LineInfo.h"

//zwraca typ rekordu
RecordType LineInfo::getType() const {
	return recordType;
}

//zwraca czas rekordu
time_t LineInfo::getTime() const {
	return time;
}

//zwraca pierwsze id rekodu (std::bad_optional_access je�li niedost�pne)
uint LineInfo::get1id() const {
	return id1.value();
}

//zwraca pierwszy nickname rekodu (std::bad_optional_access je�li niedost�pny)
std::string LineInfo::get1nickname() const {
	return name1.value();
}

//zwraca pierwsze ip rekordu (std::bad_optional_access je�li niedost�pne)
boost::asio::ip::address LineInfo::get1ip() const {
	return ip1.value();
}

//zwraca pierwszy port rekordu (std::bad_optional_access je�li niedost�pny)
ushort LineInfo::get1port() const {
	return port1.value();
}