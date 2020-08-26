#pragma once
#include <ctime> //time_t
#include <string> //std::string
#include <any> //std::any
#include <utility> //std::pair
#include "RecordType.hpp" //RecordType
#include "LineData.hpp" //LineData
#pragma warning(push, 0) //to avoid boost warnings
#include <boost/asio/ip/address.hpp> //boost::asio::ip::address, boost::asio::ip::make_address()
#pragma warning(pop)

typedef unsigned int uint;
typedef unsigned short ushort;

//informacje zdekodowanej linii
class LineInfo {
	time_t time; //znacznik czasowy rekordu
	RecordType recordType; //typ rekordu
	std::map<LineData, std::any> dataMap;

public:
	//konstruktory i operatory przypisania
	LineInfo() : recordType(RecordType::UNIDENTIFIED), time(0) {}
	LineInfo(RecordType _recordType, time_t _time) : recordType(_recordType), time(_time) {}
	LineInfo(const LineInfo&) = default;
	LineInfo(LineInfo&&) = default;
	LineInfo& operator=(const LineInfo&) = default;
	LineInfo& operator=(LineInfo&&) = default;
	~LineInfo() = default;

	//ustawia dan¹ pod podanym indeksem
	void setData(LineData index, std::any data);

	//zwraca typ rekordu
	RecordType getType() const;
	//zwraca czas rekordu
	time_t getTime() const;
	//zwraca dan¹ spod indexu o okreœlonym type (std::invalid_argument jeœli niedostêpne; std::logic_error je¿eli z³y typ)
	uint getInt(LineData index) const;
	uint getUint(LineData index) const;
	std::string getString(LineData index) const;
	boost::asio::ip::address getIp(LineData index) const;
	ushort getShort(LineData index) const;
	ushort getUshort(LineData index) const;
};

