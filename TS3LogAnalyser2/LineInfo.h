#pragma once
#include <ctime> //time_t

enum class RecordType;

//informacje zdekodowanej linii
class LineInfo {
	RecordType recordType; //typ rekordu
	time_t time; //record timestamp
public:
	//konstruktory i operatory przypisania
	LineInfo(RecordType _recordType, time_t _time) : recordType(_recordType), time(_time) {}
	LineInfo(const LineInfo&) = default;
	LineInfo(LineInfo&&) = default;
	LineInfo& operator=(const LineInfo&) = default;
	LineInfo& operator=(LineInfo&&) = default;

	//zwraca typ rekordu
	RecordType getType() const;
	//zwraca czas rekordu
	time_t getTime() const;
};

