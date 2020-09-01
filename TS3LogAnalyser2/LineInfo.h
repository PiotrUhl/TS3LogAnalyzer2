#pragma once
#include <ctime> //time_t
#include <string> //std::string
#include <utility> //std::pair
#include <map> //std::map
#include "RecordType.hpp" //RecordType
#include "LineData.hpp" //LineData

typedef unsigned int uint;
typedef unsigned short ushort;

//informacje zdekodowanej linii
class LineInfo {
	time_t time; //znacznik czasowy rekordu
	RecordType recordType; //typ rekordu
	std::map<LineData, std::string> dataMap;

public:
	//konstruktory i operatory przypisania
	LineInfo() : recordType(RecordType::UNIDENTIFIED), time(0) {}
	LineInfo(RecordType _recordType, time_t _time) : recordType(_recordType), time(_time) {}
	LineInfo(const LineInfo&) = default;
	LineInfo(LineInfo&&) = default;
	LineInfo& operator=(const LineInfo&) = default;
	LineInfo& operator=(LineInfo&&) = default;
	~LineInfo() = default;

	//ustawia dan� pod podanym indeksem
	void setData(LineData index, std::string data);

	//zwraca typ rekordu
	RecordType getType() const;
	//zwraca czas rekordu
	time_t getTime() const;
	//zwraca dan� spod indexu o okre�lonym type (std::invalid_argument je�li niedost�pne; std::logic_error je�eli z�y typ)
	uint getInt(LineData index) const;
	uint getUint(LineData index) const;
	std::string getString(LineData index) const;
	std::string getIp(LineData index) const; //string is temporary, replace with something better
	short getShort(LineData index) const;
	ushort getUshort(LineData index) const;
};

