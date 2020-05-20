#pragma once
#include "LineInfo1id1name.h"

class LineInfo1id1name1ip :	public LineInfo1id1name {
	std::string ip1; //pierwszy adres ip
	unsigned short int port1; //pierwszy port
public:
	//konstruktor
	LineInfo1id1name1ip(RecordType _recordType, time_t _time, unsigned int _id1, std::string _name1, std::string _ip1, unsigned short int _port1) : LineInfo1id1name(_recordType, _time, _id1, _name1), ip1(_ip1), port1(_port1) {}
	//zwraca pierwsze ip
	std::string getIp1() const;
	//zwraca pierwszy port
	unsigned short int getPort1() const;
};

/*QUERY_CONNECTED, CLIENT_CONNECTED*/