#include "LineInfo.h"

//ustawia dan¹ pod podanym indeksem
void LineInfo::setData(LineData index, std::any data) {
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
	return getUint(index);
}
uint LineInfo::getUint(LineData index) const {
	std::any data = dataMap.at(index);
	if (data.has_value() == false)
		throw std::invalid_argument("No data at given index");
	if (data.type() == typeid(int))
		return std::any_cast<int>(data);
	else if (data.type() == typeid(uint))
		return std::any_cast<uint>(data);
	else
		throw std::logic_error("Data at given index is type \'" + std::string(data.type().name()) + "\'which cannot be converted to int.");
}
std::string LineInfo::getString(LineData index) const {
	std::any data = dataMap.at(index);
	if (data.has_value() == false)
		throw std::invalid_argument("No data at given index");
	else if (data.type() == typeid(std::string))
		return std::any_cast<std::string>(data);
	else
		throw std::logic_error("Data at given index is type \'" + std::string(data.type().name()) + "\'which cannot be converted to string.");
}
boost::asio::ip::address LineInfo::getIp(LineData index) const {
	std::any data = dataMap.at(index);
	if (data.has_value() == false)
		throw std::invalid_argument("No data at given index");
	else if (data.type() == typeid(boost::asio::ip::address))
		return std::any_cast<boost::asio::ip::address>(data);
	else
		throw std::logic_error("Data at given index is type \'" + std::string(data.type().name()) + "\'which cannot be converted to ip address.");
}
ushort LineInfo::getShort(LineData index) const {
	return getUshort(index);
}
ushort LineInfo::getUshort(LineData index) const {
	std::any data = dataMap.at(index);
	if (data.has_value() == false)
		throw std::invalid_argument("No data at given index");
	if (data.type() == typeid(short))
		return std::any_cast<short>(data);
	else if (data.type() == typeid(ushort))
		return std::any_cast<ushort>(data);
	else
		throw std::logic_error("Data at given index is type \'" + std::string(data.type().name()) + "\'which cannot be converted to short int.");
}