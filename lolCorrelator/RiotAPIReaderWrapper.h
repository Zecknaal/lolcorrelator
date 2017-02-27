#pragma once

#include <string>

class RiotAPIReaderWrapper {
	public:
		virtual std::string callAPI(std::string url) = 0;
};