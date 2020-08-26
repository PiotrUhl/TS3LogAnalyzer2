#pragma once
#include <ctime> //time_t
#include <string> //std::string
#include <optional> //std::optional
#include "RecordType.hpp" //RecordType
#pragma warning(push, 0) //to avoid boost warnings
#include <boost/asio/ip/address.hpp> //boost::asio::ip::address, boost::asio::ip::make_address()
#pragma warning(pop)

typedef unsigned int uint;
typedef unsigned short ushort;

//informacje zdekodowanej linii
class LineInfo {
	time_t time; //znacznik czasowy rekordu
	RecordType recordType; //typ rekordu
	std::optional<uint> id1;
	std::optional<std::string> name1;
	std::optional<boost::asio::ip::address> ip1;
	std::optional<ushort> port1;

public:
	//konstruktory i operatory przypisania
	LineInfo() : recordType(RecordType::UNIDENTIFIED), time(0) {}
	LineInfo(RecordType _recordType, time_t _time, uint _id1) : recordType(_recordType), time(_time), id1(_id1) {}
	LineInfo(RecordType _recordType, time_t _time, uint _id1, const std::string& _name1) : recordType(_recordType), time(_time), id1(_id1), name1(_name1) {}
	LineInfo(RecordType _recordType, time_t _time, uint _id1, const std::string& _name1, const std::string& _ip1) : recordType(_recordType), time(_time), id1(_id1), name1(_name1), ip1(boost::asio::ip::make_address(_ip1)) {}
	LineInfo(RecordType _recordType, time_t _time, uint _id1, const std::string& _name1, const boost::asio::ip::address& _ip1) : recordType(_recordType), time(_time), id1(_id1), name1(_name1), ip1(_ip1) {}
	LineInfo(RecordType _recordType, time_t _time, uint _id1, const std::string& _name1, const std::string& _ip1, ushort _port1) : recordType(_recordType), time(_time), id1(_id1), name1(_name1), ip1(boost::asio::ip::make_address(_ip1)), port1(_port1) {}
	LineInfo(RecordType _recordType, time_t _time, uint _id1, const std::string& _name1, const boost::asio::ip::address& _ip1, ushort _port1) : recordType(_recordType), time(_time), id1(_id1), name1(_name1), ip1(_ip1), port1(_port1) {}
	LineInfo(const LineInfo&) = default;
	LineInfo(LineInfo&&) = default;
	LineInfo& operator=(const LineInfo&) = default;
	LineInfo& operator=(LineInfo&&) = default;
	~LineInfo() = default;

	//zwraca typ rekordu
	RecordType getType() const;
	//zwraca czas rekordu
	time_t getTime() const;
	//zwraca pierwsze id rekodu (std::bad_optional_access jeœli niedostêpne)
	uint get1id() const;
	//zwraca pierwszy nickname rekodu (std::bad_optional_access jeœli niedostêpny)
	std::string get1nickname() const;
	//zwraca pierwsze ip rekordu (std::bad_optional_access jeœli niedostêpne)
	boost::asio::ip::address get1ip() const;
	//zwraca pierwszy port rekordu (std::bad_optional_access jeœli niedostêpny)
	ushort get1port() const;
};

