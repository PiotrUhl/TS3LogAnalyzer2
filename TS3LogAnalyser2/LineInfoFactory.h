#pragma once
#include "LineInfo.h"
#include "Line.h"
#include <memory>

class LineInfoFactory {

public:
	//tworzy odpowieni� podklas� LineInfo dla danego rekordu
	std::unique_ptr<LineInfo> create(RecordType type, time_t time, const Line& line) const;
private:
	//tworzy podklas� LineInfo dla jednego id i jednej nazwy i jednego ip
	std::unique_ptr<LineInfo> make1id1name1ip(RecordType type, time_t time, const Line& line) const;
	
	//wyci�ga id z linii
	unsigned int getId(const Line& line, unsigned int nr = 0) const;
	//wyci�ga nickname z linii
	std::string getName(const Line& line, unsigned int nr = 0) const;
	//wyci�ga ip z linii
	std::string getIp(const Line& line, unsigned int nr = 0) const;
	//wyci�ga port z linii
	unsigned short int getPort(const Line& line, unsigned int nr = 0) const;
};

