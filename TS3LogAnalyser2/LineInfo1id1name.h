#pragma once
#include "LineInfo.h"
#include <string>

//dane rekordu z jednym id i jedn¹ nazw¹
class LineInfo1id1name : public LineInfo {
	unsigned int id1; //pierwsze id
	std::string name1; //pierwsza nazwa
public:
	//konstruktor
	LineInfo1id1name(RecordType _recordType, time_t _time, unsigned int _id1, std::string _name1) : LineInfo(_recordType, _time), id1(_id1), name1(_name1) {}
	//zwraca pierwsze id
	unsigned int getId1() const;
	//zwraca pierwsz¹ nazwê
	std::string getName1() const;
};

/*SERVER_MODIFIED*/