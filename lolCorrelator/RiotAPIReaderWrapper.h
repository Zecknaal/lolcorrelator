#pragma once

#include <string>

class RiotAPIReaderWrapper {
	public:
		virtual std::string callAPI(const char* url) = 0;
};