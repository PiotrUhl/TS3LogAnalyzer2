#pragma once
#include <ctime> //time_t
#include <string> //std::string
#include "RecordType.hpp"

//informacje zdekodowanej linii (tagged union)
class LineInfo {
	struct T1id {
		unsigned int id1;
		T1id(unsigned int _id1) : id1(_id1) {}
	};
	struct T1id1name : T1id {
		std::string nickname1;
		T1id1name(unsigned int _id1, const std::string& _nickname1) : T1id(_id1), nickname1(_nickname1) {}
	};
	struct T1id1name1ip : T1id1name {
		std::string ip1; //todo: zmieniæ tym na coœ bardziej sensownego
		T1id1name1ip(unsigned int _id1, const std::string& _nickname1, const std::string& _ip1) : T1id1name(_id1, _nickname1), ip1(_ip1) {}
	};
	struct T1id1name1ip1port : T1id1name1ip {
		unsigned short port1;
		T1id1name1ip1port(unsigned int _id1, const std::string& _nickname1, const std::string& _ip1, unsigned short _port1) : T1id1name1ip(_id1, _nickname1, _ip1), port1(_port1) {}
	};
	union Union {
		T1id t1id;
		T1id1name t1id1name;
		T1id1name1ip t1id1name1ip;
		T1id1name1ip1port t1id1name1ip1port;
		Union(T1id _t) : t1id(_t) {}
		Union(T1id1name _t) : t1id1name(_t) {}
		Union(T1id1name1ip _t) : t1id1name1ip(_t) {}
		Union(T1id1name1ip1port _t) : t1id1name1ip1port(_t) {}
		~Union() {}
	};
	const time_t time; //znacznik czasowy rekordu
	const RecordType recordType; //typ rekordu (tag)
	const Union u; //odpowiednia unia z danymi rekordu
public:
	//konstruktory i operatory przypisania
	LineInfo(RecordType _recordType, time_t _time, unsigned int _id1) : recordType(_recordType), time(_time), u(T1id(_id1)) {} //konstruktor dla wersji 1ip ()
	LineInfo(RecordType _recordType, time_t _time, unsigned int _id1, const std::string& _nickname1) : recordType(_recordType), time(_time), u(T1id1name(_id1, _nickname1)) {} //konstruktor dla wersji 1ip1nickname ()
	LineInfo(RecordType _recordType, time_t _time, unsigned int _id1, const std::string& _nickname1, const std::string& _ip1) : recordType(_recordType), time(_time), u(T1id1name1ip(_id1, _nickname1, _ip1)) {} //konstruktor dla wersji 1ip1nickname1id (CLIENT_CONNECTED)
	LineInfo(const LineInfo&) = default;
	LineInfo(LineInfo&&) = default;
	LineInfo& operator=(const LineInfo&) = default;
	LineInfo& operator=(LineInfo&&) = default;

	//zwraca typ rekordu
	RecordType getType() const;
	//zwraca czas rekordu
	time_t getTime() const;
	//zwraca pierwsze id rekodu (std::logic_error jeœli niedostêpne)
	unsigned int get1id() const;
	//zwraca pierwszy nickname rekodu (std::logic_error jeœli niedostêpny)
	std::string get1nickname() const;
	//zwraca pierwsze ip rekordu (std::logic_error jeœli niedostêpne)
	std::string get1ip() const;
	//zwraca pierwszy port rekordu (std::logic_error jeœli niedostêpny)
	std::string get1port() const;
};

