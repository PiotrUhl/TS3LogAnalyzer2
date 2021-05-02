#pragma once

#include <string>
#include <array>

class IPaddress {
	std::array<unsigned char, 4> _ip;
public:
	//konstruktory
	IPaddress() = default;
	IPaddress(const std::string& ipString);
	IPaddress(std::array<unsigned char, 4> ipArray);
	IPaddress(const unsigned char* ipBytes);
	//rule of five
	IPaddress(const IPaddress&) = default;
	IPaddress(IPaddress&&) = default;
	IPaddress& operator=(const IPaddress&) = default;
	IPaddress& operator=(IPaddress&&) = default;
	~IPaddress() = default;
	//gettery
	std::string getString();
	std::array<unsigned char, 4> getArray();
	//parsuj¹ce operatory przypisania
	IPaddress& operator=(const std::string& ipString);
	IPaddress& operator=(std::array<unsigned char, 4> ipArray);
	IPaddress& operator=(const unsigned char* ipBytes);
private:
	//konwertuje string na tablicê znaków, rzuca std::invalid_argument i std::out_of_range
	std::array<unsigned char, 4> parse(const std::string& ipString);
};